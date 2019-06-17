# include "Calculs.h"


void TrierTableauCarte(T_pays tab[], int nbPays)
{
	int i,k;
	T_pays tempo;

	for (i = 0; i < nbPays; i++)
	{
		for (k = 0; k < nbPays; k++)
		{
			if (tab[k].xo > tab[i].xo)
			{
				tempo = tab[i];
				tab[i] = tab[k];
				tab[k] = tempo;
			}
			else if ((tab[k].xo == tab[i].xo) && (tab[k].yo > tab[i].yo))
			{
				tempo = tab[i];
				tab[i] = tab[k];
				tab[k] = tempo;
			}
		}
	}
}



bool Control_X_commun(T_pays pays0, T_pays pays1)
{
	bool valeur = (((pays1.xo < pays0.xo) && ((pays1.xo + pays1.longueur) >= pays0.xo)) || ((pays1.xo >= pays0.xo) && pays1.xo <= (pays0.xo + pays0.longueur)));
	return valeur;
}

bool Control_Y_commun(T_pays pays0, T_pays pays1)
{
	bool valeur = (((pays1.yo < pays0.yo) && ((pays1.yo + pays1.hauteur) >= pays0.yo)) || ((pays1.yo >= pays0.yo) && (pays1.yo <= pays0.yo + pays0.hauteur)));
	return valeur;
}



void controle_Voisin(T_pays carte[], int tab[][12],int nbPays)
{
	bool voisin;

	for (int i = 0; i < nbPays - 1; i++)
	{
		for (int k = 0; k < nbPays; k++)
		{
			voisin = false;

			if (i == k) k++;

			if ((carte[k].xo + carte[k].longueur) == carte[i].xo)
			{
				printf("\n son x1 identique au xo");
				if (Control_Y_commun(carte[i], carte[k]))
				{
					printf("\n 1 est voisin a gauche");
					voisin = true;

				}
				else { printf("\n pas voisins"); }
			}

			else if ((carte[k].yo + (carte[k].hauteur)) == carte[i].yo)
			{
				printf("\n son y1 identique au yo");

				if (Control_X_commun(carte[i], carte[k]))
				{
					printf("\n 1 est voisin au dessous");
					voisin = true;
				}
				else { printf("\n pas voisins"); }
			}

			else if (carte[k].xo == (carte[i].xo + carte[i].longueur))
			{
				printf("\n son xo identique au x1");
				if (Control_Y_commun(carte[i], carte[k]))
				{
					printf("\n 1 est voisin a droite");
					voisin = true;
				}
				else { printf("\n pas voisins"); }
			}

			else if (carte[k].yo == (carte[i].yo + carte[i].hauteur))
			{
				printf("\n son y1 identique au yo");

				if (Control_X_commun(carte[i], carte[k]))
				{
					printf("\n 1 est voisin au dessus");
					voisin = true;
				}
				else { printf("\n pas voisins"); }
			}

			if (voisin)
			{
				tab[i][k] = 1;
				tab[k][i] = 1;
				carte[i].nb_voisins++;
			}
			
		}
		
		
	}
}



int calcul_somme(T_pays pays)
{
	int somme = 0;
	for (int i = 0; i < 5; i++)
	{
		somme = somme + pays.couleurs_voisins[i];
	}
	return somme;
}
/* ___________________________________ FONCTIONS COLORATION _________________________________________________*/



void colorePays(T_pays carte[], int tab[][12], int nbPays)
{
	int i,k, valeur;
	int Matcolor[5] = { 0,0,0,0,0 };


	i = 0;															// initialisation couleur du carré origine et de ses voisins directs
	valeur = 0;
	carte[i].color = 7;														
	k = 0;
	for (k = 0; k < nbPays; k++)

	{
		if (tab[i][k] == 1)
		{ 
			valeur = valeur + 1;
				if (valeur % 2 == 0) carte[k].color = 1;
				else carte[k].color = 5;
		}
	}

	for (i = 0; i < nbPays; i++)

	{
		if ((carte[i].color == 0) && (carte[i].nb_voisins == 0))
		{
			 carte[i].color = 1;
		}

		else if ((carte[i].color == 0) && (carte[i].nb_voisins == 1))
		{
			k = 0;
			while (tab[i][k] != 1) k++;
			
			if (carte[k].color == 0)
			{
					carte[i].color = 1;
					carte[k].color = 3;
			}

			else if (carte[k].color > 3) carte[k].color = 1;
			else carte[k].color = 7;
			}
		}

	}



