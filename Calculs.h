#pragma once
#include <conio.h>
#include <math.h>
#include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "public.h"
#include "InOut.h"

void TrierTableauCarte(T_pays tab[], int nbPays);

bool Control_X_commun(T_pays rectangle0, T_pays rectangle1);
bool Control_Y_commun(T_pays rectangle0, T_pays rectangle1);

void controle_Voisin(T_pays carte[], int tab[][12], int i);

int calcul_somme(T_pays pays);
void colorePays(T_pays carte[], int tab[][12], int nbPays);

