#include "InOut.h"
#pragma warning(disable : 4996)

FILE* fic;
int compteur;

void lireFichier(char nomfichier[], T_pays carte[], int* psinbPays)

{

	char ligne[81]; // pour mémoriser la ligne lue dans le fichier
	int nb_lignes_lues, nb_val_lues; // compteurs pour le test
	compteur = 0;

	fic = fopen(nomfichier, "rt");

	if (fic == NULL)
	{
		puts("Pb d'ouverture du fichier exemple.txt !");
		exit(0);
	}

	while (fgets(ligne, 81, fic) != 0 && (ligne[0] == '<' || ligne[0] == '/'));
	nb_lignes_lues = 0; // pour l'affichage de test

	while (fgets(ligne, 81, fic) != NULL)
	{
		nb_lignes_lues++;
		// ANALYSE avec sscanf de la ligne lue précedemment par fgets :
		nb_val_lues = sscanf(ligne, "\n %*s%d%*s%d%*s%d%*s%d%*s%*s%*s%*s", &carte[compteur].xo, &carte[compteur].yo, &carte[compteur].longueur, &carte[compteur].hauteur);
		if (nb_val_lues != 4)
			printf(" \n !!!! PROBLEME Ligne %2hd !!!!", nb_lignes_lues);

		else // affichage POUR LE TEST :
		{
			printf("\n (Donnees extraites Ligne %2hd) xo : %d yo : %d longueur : %d largeur : %d couleur : %d", nb_lignes_lues, carte[compteur].xo, carte[compteur].yo, carte[compteur].longueur, carte[compteur].hauteur, carte[compteur].color);
			compteur++;
		}

	}
	
	fclose(fic);

	*psinbPays = compteur++;
}



//_____________________________ FONCTION ECRITURE FICHIER AVEC COULEURS ________________________________


void EcrireFichier(char nomfichier[], T_pays carte[], int nbPays)

{
	fic = fopen(nomfichier, "wt");
	char color[8][7] = {"white","yellow","","red","","blue","","green"};	//-->  white=0, yellow = 1, red = 3, blue =5, green=7
	if (fic != NULL)
	{
		fprintf(fic, "<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Strict//EN \" \" http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\ \" >");
		fprintf(fic, "\n<html> \n  <head> \n    <title> Carte </title> \n  </head> \n\n  <body> \n\n    <svg width = 1200 height = 1000 version = 1.1 xmlns = \" http://www.w3.org/2000/svg\ \" >");

		for (compteur = 0; compteur < nbPays; compteur++)
		{
			fprintf(fic, "\n      <rect\n        x= %d y= %d width= %d height= %d fill= %s stroke= black \n     />", carte[compteur].xo, carte[compteur].yo, carte[compteur].longueur, carte[compteur].hauteur, color[carte[compteur].color]);
		}
		fprintf(fic, "\n    </svg>\n  </body>\n\n</html>");
		fclose(fic);
	}

	else { printf("ouverture impossible"); }
}


