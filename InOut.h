#pragma once
#include <conio.h>
#include <math.h>
#include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "public.h"

typedef struct
{														// structure pays de forme rectangle
	int xo, yo, longueur, hauteur, nb_voisins=0;		//xo, yo: coordonnées mini du rectangle 
	int color = 0;										//color --> white = 0, yellow= 1, red = 3, blue = 5, green= 10;
	int couleurs_voisins[5] = { 0,0,0,0,0 };			// cases w y r b g: valeur 0 si pas de couleur, 1 si couleur;
} T_pays;												// sommes possibles: w 0,y 1,r 3,yr 4,b 5,yb 6, rb 8, yrb 9, g 10,yg 11,rg 13, bg 15 ,yrg 16, rbg 18


void lireFichier(char nomfichier[], T_pays carte[], int* psinbPays);

void EcrireFichier(char nomfichier[], T_pays carte[], int nbPays);