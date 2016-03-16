#include "stdafx.h"

void buscaConstrucao(char **, int, int);
int buscaLista(char **, int, int);
char *lerEntrada(FILE *, int);
char lerImg(FILE *);

int sizeX, sizeY, numConstr;
int main()
{
	FILE *entrada, *saida;
	char **img;

	sizeX = 9;
	sizeY = 15;
	int i, j, nTeste = 0;
	char *s1, *s2, *resto;


	numConstr = 0;
	if ((entrada = fopen("IMAGEM.IN", "r")) == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada");
	}
	saida = fopen("IMAGEM.OUT", "w");
	if (saida == NULL) {
		printf("Erro ao abrir o arquivo");
		return 9;
	}
	while (((s1 = lerEntrada(entrada, 2)) && (s2 = lerEntrada(entrada, 2))) || ((s1 == "0") && (s2 == "0")))
	{
		nTeste++;
		sizeX = (int)strtod(s1, &resto);
		sizeY = (int)strtod(s2, &resto);

		img = (char **)malloc(sizeX * sizeof(char *));
		for (i = 0; i < sizeY; i++)
			img[i] = (char *)malloc(sizeY * sizeof(char *));

		for (i = 0; i < sizeX; i++)
			for (j = 0; j  < sizeY; j ++)
				img[i][j] = lerImg(entrada);

		for (i = 0; i < sizeX; i++)
		{
			for (j = 0; j < sizeY; j++)
			{
				if (img[i][j] > '0')
					buscaConstrucao(img, i, j);
			}
		}
		for (i = 0; i < sizeX; i++)
		{
			puts(img[i]);
		}
		fprintf(saida, "Teste %d", nTeste);
		fprintf(saida, "Numero de construcoes: %d\n", numConstr);
		fputs("", saida);
		printf("Total de objetos: %d\n", numConstr);
	}
	fclose(saida);
	system("pause");
	return 0;
}

void buscaConstrucao(char ** img, int i, int j) {
	if ((j > 0) && (buscaLista(img, i, j - 1)))
		return;
	if ((i > 0) && (buscaLista(img, i - 1, j)))
		return;
	if ((i > 0) && (j > 0) && (buscaLista(img, i - 1, j - 1)))
		return;
	if ((i > 0) && (j < sizeY) && (buscaLista(img, i - 1, j + 1)))
		return;
	numConstr++;
	return;
}

int buscaLista(char ** img, int i, int j) {
	return img[i][j] > '0' ? 1 : 0;
}

char *lerEntrada(FILE *entrada, int tamMax) {
	char *s;

	tamMax++;
	if ((s = (char *)malloc(tamMax * sizeof(char*))) == NULL)
		return NULL;
	if ((fgets(s, tamMax, entrada)) == NULL)
	{
		printf("Erro ao ler o arquivo de entrada");
	}
	return s;
}

char lerImg(FILE *entrada) {
	char c;

	while ((c = getc(entrada)) != EOF && (c =='\n' || c == ' '))
		continue;
	return c;
}