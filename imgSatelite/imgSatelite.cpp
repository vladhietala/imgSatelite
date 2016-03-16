#include "stdafx.h"

void buscaConstrucao(char **, int, int);
int buscaLista(char **, int, int);

int sizeX, sizeY, numConstr;
int main()
{
	char **img;

	sizeX = 9;
	sizeY = 15;
	int i, j;

	numConstr = 0;
	img = (char **)malloc(sizeX * sizeof(char *));

	for (i = 0; i < sizeY; i++)
	{
		img[i] = (char *)malloc(sizeY * sizeof(char *));
	}

	img[0] = "000000000000000";
	img[1] = "007677888000080";
	img[2] = "008000000900000";
	img[3] = "006003300080000";
	img[4] = "005003300800000";
	img[5] = "004000009000600";
	img[6] = "034556780005000";
	img[7] = "300000000004400";
	img[8] = "020000000000000";

	//img = img2;

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
	printf("Total de objetos: %d\n", numConstr);
	system("pause");
	return 0;
}

/*

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 7 6 7 7 8 8 8 0 0 0 0 8 0
0 0 8 0 0 0 0 0 0 9 0 0 0 0 0
0 0 6 0 0 3 3 0 0 0 8 0 0 0 0
0 0 5 0 0 3 3 0 0 8 0 0 0 0 0
0 0 4 0 0 0 0 0 9 0 0 0 6 0 0
0 3 4 5 5 6 7 8 0 0 0 5 0 0 0
3 0 0 0 0 0 0 0 0 0 0 4 4 0 0
0 2 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
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

/*	if (j > 0) {
		if (buscaLista(img, i, j - 1))
			return;
		if (j > 0 && j < sizeY) {
			if (buscaLista(img, i - 1, j))
				return;
			if (buscaLista(img, i - 1, j - 1))
				return;
			if (buscaLista(img, i - 1, j + 1))
				return;
		}
	}
	*/
}

int buscaLista(char ** img, int i, int j) {
	int isConstruction;
	isConstruction = img[i][j] > '0' ? 1 : 0;
	return isConstruction;
}

