#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

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

    for ( i = 0; i < sizeX; i++)
    {
        for ( j = 0; j < sizeY; j++)
        {
            if (img[i][j] > 0)
                buscaConstrucao(img, i, j);
        }

    }
    printf("%d objetos",numConstr);
    getchar();
    return 0;
}

void buscaConstrucao(char ** img, int i, int j){
    if (i > 0 && i < sizeX){
        if (buscaLista(img, i - 1, j))
            return;
        if (j>0 && j< sizeY){
          if (buscaLista(img, i - 1, j -1))
            return;
          if (buscaLista(img, i, j - 1))
            return;
          if (buscaLista(img, i + 1, j))
            return;
        }
    }
    numConstr++;
    return;
}

int buscaLista(char ** img, int i, int j){
    return (img[i][j] > 0) ? 1 : 0;
}

