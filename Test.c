#include "Outil.h"

#define N 11

typedef enum {maison = 0, restaurant, clinique, usine, epicerie, champ, garage}t_type_batiment;
typedef enum {vivre = 0, soin, materiaux, arme, survivant, rien}t_objet_a_trouver;
typedef enum {massue = 0, machette, hache, epee, arc, arbalete, pistolet, mitraillette, sniper}t_arme;
typedef enum {intact, vide}t_fouille_batiment;


// Fonction qui va définir ce que l'on va trouver dans chaque bâtiments (juste le type pas la quantitée) en fonction du bâtiments
int type_ressource_batiment(int test)
{
	char * tab_ressource[] = {"vivre", "soin", "materiaux", "arme", "survivant", "rien"};
	int tab_restaurant[2] = {vivre, survivant};
	int tab_clinique[2] = {soin, survivant};
	int tab_usine[3] = {materiaux, arme, survivant};
	int tab_epicerie[3] = {vivre, soin, survivant};
	int tab_champ[3] = {vivre, materiaux, survivant};
	int tab_garage[3] = {materiaux, arme, survivant};
	int ressource;
	Appel0("type_ressource_batiment");
	
	switch(test)
	{
		case 0: printf("Vous rentrez dans une maison qui n'est pas encore explorée, exploration en cours...\n");
			ressource = nHasard(6);
			printf("Objet type: %i\n", ressource);
			break;
		case 1: printf("Vous rentrez dans un restaurant qui n'est pas encore explorée, exploration en cours...\n");
			ressource = tab_restaurant[nHasard(2)];
			printf("Objet type: %i\n", ressource);
			break;
		case 2: printf("Vous rentrez dans une clinique qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_clinique[nHasard(2)];
			printf("Objet type: %i\n", ressource);
			break;
		case 3: printf("Vous rentrez dans une usine qui n'est pas encore explorée, exploration en cours...\n");
			ressource = tab_usine[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
		case 4: printf("Vous rentrez dans une épicerie qui n'est pas encore explorée, exploration en cours...\n");
			ressource = tab_epicerie[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
		case 5: printf("Vous rentrez dans un champ qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_champ[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
		case 6: printf("Vous rentrez dans un garage qui n'est pas encore exploré, exploration en cours...\n");
			ressource = tab_garage[nHasard(3)];
			printf("Objet type: %i\n", ressource);
			break;
	}
	Appel1("type_ressource_batiment");
	return ressource;
}

// Indique quelle ressource à été trouvé
int ressource_trouve(int type_ressource)
{
	int nom_ressource;
	Appel0("Ressource trouvé(es)");
	switch(type_ressource)
	{
		case 0: printf("Ressource trouvé: Vivre\n");break;
		case 1: printf("Ressource trouvé: Soin\n");break;
		case 2: printf("Ressource trouvé: Matériaux\n");break;
		case 3: printf("Ressource trouvé: Arme\n");break;
		case 4: printf("Ressource trouvé: Survivant\n");break;
		case 5: printf("Ressource trouvé: Rien\n");break;
	}
	Appel1("Ressource trouvé(es)");
	return nom_ressource;
}

// Fonction qui retourne le nombre de ressources trouvé dans le bâtiment dont le type à été définie dans la fonction ressource_batiment
int nombre_ressource_trouve(int type_ressource)
{
	int nb_ressource;
	Appel0("nombre_ressource_trouve");
	switch(type_ressource)
	{
		case 0: nb_ressource = 20;break;
		case 1: nb_ressource = 20;break;
		case 2: nb_ressource = 10;break;
		case 3: nb_ressource = 1;break;
		case 4: nb_ressource = 1;break;
		case 5: nb_ressource = 0;break;
	}
	printf("Quantité: %i\n", nb_ressource);
	Appel1("nombre_ressource_trouve");
	return nb_ressource;
}


// Chance d'avoir tel ou tel type d'arme en fonction de sa catégorie
int chance_type_arme()
{
	int chance;
	int type_arme;
	Appel0("chance_type_arme");
	chance = nHasard(999);
	
	if (chance <= 249) // Machette
	{
		type_arme = 0;
	}
	else if ((chance >= 250) && (chance <= 449)) // Hache
	{
		type_arme = 1;
	}
	else if ((chance >= 450) && (chance <= 474)) // Epée
	{
		type_arme = 2;
	}
	else if ((chance >= 475) && (chance <= 724)) // Arc
	{
		type_arme = 3;
	}
	else if ((chance >= 725) && (chance <= 924)) // Arbalète
	{
		type_arme = 4;
	}
	else if ((chance  >= 925) && (chance <= 974)) // Pistolet
	{
		type_arme = 5;
	}
	else if ((chance >= 975) && (chance <= 998)) // Mitraillette
	{
		type_arme = 6;
	}
	else if (chance == 999) // Sniper
	{
		type_arme = 7;
	}

	Appel1("chance_type_arme");
	return type_arme;
}


// Affiche l'arme obtenue
int affiche_type_arme(int arme) 
{
	Appel0("Afficher arme");
	switch(arme)
	{
		case 0: printf("Arme Obtenue: Machette\n");break;
		case 1: printf("Arme Obtenue: Hache\n");break;
		case 2: printf("Arme Obtenue: Epée\n");break;
		case 3: printf("Arme Obtenue: Arc\n");break;
		case 4: printf("Arme Obtenue: Arbalète\n");break;
		case 5: printf("Arme Obtenue: Pistolet\n");break;
		case 6: printf("Arme Obtenue: Mitraillette\n");break;
		case 7: printf("Arme Obtenue: Sniper\n");break;
	
		}
	Appel1("Afficher arme");
	return arme;	
}

// Fonction qui indique si un bâtiment à été exploré ou non lorsque l'on selectionne un bâtiment

int fouille_batiment(int statut)
{
	Appel0("Fouille bâtiment");	
	switch(statut)
	{
		case 0: statut = intact;break;
		case 1: statut = vide;break;
	}
	
	Appel1("Fouille bâtiment");
	return statut;
}


int main2()
{

	int nom_ressource;
	int type_ressource;
	int nb_ressource;
	int test;
	int niveau;
	int type_arme;
	int statut;
	int arme;
	
	HasardInit();
	
	printf("Maison=0, Restaurant=1, Clinique=2, Usine=3, Epicerie=4, Champ=5, Garage=6, Pharmacie=7: ");
	scanf("%i", &test);
	printf("Intact = 0, Vide = 1: ");
	scanf("%i", &statut);
	
	/*statut = fouille_batiment(statut);*/

	if (statut == 0)
	{
		type_ressource = type_ressource_batiment(test);
	
		nom_ressource = ressource_trouve(type_ressource);


		nb_ressource = nombre_ressource_trouve(type_ressource);
	
		if(type_ressource == 3) 
		{
			type_arme = chance_type_arme();
			arme = affiche_type_arme(type_arme);
		}
	}
	else if(statut == 1)
	{
		printf("Le bâtiment à déjà été visité\n");
	}


}

void ModuleAmorceR()
{
	//amorce tous les modules (code à exécuter une fois pour toutes AVANT d'utiliser un quelconque module depuis le main)
	OutilAMORCER();//NE PAS DECLASSER:doit toujours être appelé en premier
	//amorcer TOUS les modules autres que Outil mentionnés dans les include de main.c
}//ModuleAmorceR

int main (int argc, const char * argv[]) 
{
	Appel0("");//NE PAS TOUCHER; ce code doit toujours être placé au début du main
		ModuleAmorceR();//NE PAS TOUCHER; ce code doit toujours suivre immédiatement Appel0("")
		main2();
	Appel1("");//NE PAS TOUCHER; ce code doit toujours être placé à la fin du main, juste avant le return()
    return 0;
}//main



