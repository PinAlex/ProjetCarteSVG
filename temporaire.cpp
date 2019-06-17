/* _____________________________ FONCTIONS DE SAISIE _____________________________________________

int saisir_entierpositif()
{
	int choix, test;
	do
	{
		rewind(stdin);
		printf("VEUILLEZ SAISIR LE NOMBRE DE PAYS A CREER (1 A %d):  ", Nbmax_pays);
		test = scanf_s("%d", &choix);
	} while ((test == 0) || (choix == 0) || (choix > Nbmax_pays));
	return choix;
}

_____________________________ FONCTIONS DE CONTROLE _____________________________________________




bool testCreation(int num)
{
	bool valeur;


	return valeur;
}


_____________________________ FONCTIONS DE CREATION DES OBJETS ________________________________

void creer_pays(T_pays pays, int num)
{
	do
	{
		srand(time(NULL));
		pays.xo = taille_min_carre + rand() % (MapLong - 1 + 1);
		pays.yo = taille_min_carre + rand() % (MapHeight - 1 + 1);
		pays.longueur = 1 + rand() % (taille_max_carre - 1 + 1);
		pays.hauteur = 1 + rand() % (taille_max_carre - 1 + 1);
		pays.color = 4; //couleur blanche à la création
	} while (!testCreation(num));

	printf("\n creation du pays n°%d : %d   %d   %d   %d  %d", num, pays.xo, pays.yo, pays.longueur, pays.hauteur, pays.color);
}

void creer_carte(T_pays T_tab[], int i)  // creation de la carte 
{
	int compteur;
	printf("Creation de la carte avec %d pays", i);
	if (compteur == 0)
		T_tab[compteur] = { 0,0,10,10,4 };
	for (compteur = 1; compteur < i; compteur++)
	{
		creer_pays(T_tab[compteur], compteur);
	}

}
*/



