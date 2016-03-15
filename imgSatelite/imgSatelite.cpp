// imgSatelite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "imgSatelite.h"

int buscaConstrucao(char **, size_t, size_t);

int main()
{
	char **img;

	int sizeX = 9, sizeY = 15;

	img = (char **)malloc(sizeX * sizeof(char *));

	for (size_t i = 0; i < sizeY; i++)
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

	for (size_t i = 0; i < sizeX; i++)
	{
		for (size_t j = 0; j < sizeY; j++)
		{
			int r = buscaConstrucao(img, i, j);
		}

	}

	getchar();

	return 0;
}

int buscaConstrucao(char ** img, size_t i, size_t j) {
	int pos = 0;
	fputchar(img[i][j]);
	return pos;
}

