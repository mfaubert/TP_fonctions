// But :	   Programme qui dessine des formes aux dimensions diverses, pleines ou vides, selon les choix que l'utilisateur fait dans les menus	   
// Auteur :	   Ma�t� Faubert
// Date :      10 novembre 2020


#include <iostream>		// Biblioth�que qui fournit des fonctions pour permettre la communication entre le programme et l'utilisateur
#include <time.h>		// Biblioth�que qui fournit des fonctions bas�es sur les dates et heures
#include <stdlib.h> // Pour ajouter les couleurs 
#include "Fonctions0443181.h"		// Biblioth�que du programmeur rassemblant les fonctions permettant la gestion des menus et la validation des choix fait dans ces menus

using namespace std;

int main()
{
	// D�finition des constantes 
	const int QUITTER = 5;     // Le choix maximum dans le menu 1. Pourrait changer si le programmeur ajoute une forme supppl�mentaire
	const int RETOUR = 3;     // Le choix maximum dans le menu 2. Pourrait changer si le programmeur ajoute une option supppl�mentaire

	const int RECTANGLE = 1;     // Pour faciliter la lecture du code dans le switch
	const int TRIANGLE = 2;
	const int CARRE = 3;
	const int LOSANGE = 4;

	// D�finition des variables	
	int choixForme;
	int choixRemplissage;

	srand(time(NULL));	            // Permet d'initialiser le random seed
	setlocale(LC_ALL, "");            // Permet de g�rer les caract�res accentu�s

   // Afficher le menu des formes et lire un choix valide 
	choixForme = validerMenu(1 /* choix du menu des formes */);

	// Tant que l'utilisateur ne veut pas quitter
	while (choixForme != 5)
	{
		// Afficher le menu du remplissage et lire un choix valide
		choixRemplissage = validerMenu(2 /* Menu du remplissage */);

		// Si l'utilisateur n'est pas revenu au menu principal
		if (choixRemplissage != 3)
		{
			// Ici, l'utilisateur a fait le choix d'une forme et du remplissage, il nous reste � traiter et dessiner la forme
			switch (choixForme)
			{
			case RECTANGLE:
				// Traiter forme demande les dimensions de la forme, affiche la phrase de pr�sentation de la forme et appelle la fonction
				// dessinant la forme
				traiterRectangle(choixRemplissage);
				break;
			case TRIANGLE:
				traiterTriangle(choixRemplissage);
				break;
			case CARRE:
				traiterCarre(choixRemplissage);
				break;
			case LOSANGE:
				traiterLosange(choixRemplissage);
				break;
			} // Fin du switch
		}// fin du if

	   // On pr�sente de nouveau le menu principal des choix des formes et on lit le choix de l'utilisateur
		choixForme = validerMenu(1 /* Menu des formes*/);

	} // Fin du while (choixForme != iQUITTER)
	return 0;

}


