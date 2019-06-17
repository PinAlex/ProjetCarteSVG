#include <conio.h>
#include <math.h>
#include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "public.h"
# include "InOut.h"
# include "Calculs.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 4129)

/* _____________________________ FONCTION MAIN ________________________________*/

int main()
{
	char nom[20];

	T_pays carte[12];						// a creer avec un MALLOC
	int T_voisins[12][12];					// a creer avec un MALLOC
	
	int i, k, nbPays = 0;

	/* ouverture du fichier et copie des attributs des rectangles du fichier dans un tableau*/
	
	printf("le nom de votre fichier doit faire moins de %d caracteres", (int)sizeof(nom) - 1);

	rewind(stdin);
	printf("\n saisir nom du fichier a ouvrir (exemple: test.txt) :    ");
	scanf("%s", &nom);

	lireFichier(nom, carte, &nbPays);

	/* tri des pays dans tableau selon les x croissants et y croissants */

	TrierTableauCarte(carte, nbPays);
	

	/* initialisation du tableau 2D des voisins de chaque pays */

	for (i = 0; i < nbPays; i++)
	{
		for (k = 0; k < nbPays; k++)
		{
			T_voisins[i][k] = 0;
		}
	}
	
	controle_Voisin(carte, T_voisins, nbPays);

	for (i = 0; i < nbPays; i++)
	{
		printf("\n pays n° %d nb voisins : %d", i, carte[i].nb_voisins);
	}


	colorePays(carte, T_voisins, nbPays);

	EcrireFichier(nom, carte, nbPays);

	return 0;
}


	