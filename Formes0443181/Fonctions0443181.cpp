#include "Fonctions0443181.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>

using namespace std;

// Afficher le menu du choix de forme
void afficherMenu1()
{
	cout << endl;
	cout << "Choisissez la forme : " << endl;
	cout << "1. Rectangle" << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Carré" << endl;
	cout << "4. Losange" << endl;
	cout << "5. Quitter" << endl;
	cout << "Votre Choix --> ";

}

// Afficher le menu du choix de remplissage
void afficherMenu2()
{
	cout << "Choisissez votre remplissage : " << endl;
	cout << "1. Forme pleine" << endl;
	cout << "2. Forme vide" << endl;
	cout << "3. Retour au menu précédent." << endl;
	cout << "Votre choix --> ";

}
// Valider la saisie d'un entier pour la validation du menu
int saisirEntier()
{
	string clavier;
	int nombre;

	getline(cin, clavier, '\n');		

	while ((clavier.empty() || ((clavier.front() < '0' || clavier.front() > '9')
		&& (clavier.length() <= 1 || clavier.front() != '-' || clavier.at(1) < '0' || clavier.at(1) > '9'))))

	{
		cout << "Erreur : Vous devez taper des chiffres pour entrer un nombre entier." << endl;
		cout << "Veuillez entrer un nombre entier : ";
		getline(cin, clavier, '\n');
	}

	return stoi(clavier);
}

// Valider le menu du choix de forme
int validerMenu(int choixMenu)
{

	if (choixMenu == 1) {

		int choixForme;
		afficherMenu1();

		// Récupérer le choix de l'utilisateur
		choixForme = saisirEntier();

		// Valider le choix, tant que le choix n'est pas valide, redemander le choix.
		while (!(choixForme >= 1 && choixForme <= 5)) {
			cout << "Votre choix de forme n'est pas valide, il doit être compris entre 1 et 5." << endl;
			cout << "Votre choix --> ";
			cin >> choixForme;
		}

		// Retourner le choix
		return choixForme;
	}

	else if (choixMenu == 2) {
		int choixRemplissage;
		afficherMenu2();

		// Récupérer le choix de l'utilisateur
		choixRemplissage = saisirEntier();

		// Valider le choix, tant que le choix n'est pas valide, redemander le choix.
		while (!(choixRemplissage >= 1 && choixRemplissage <= 3)) {
			cout << "Votre choix de remplissage n'est pas valide, il doit être compris entre 1 et 3." << endl;
			cout << "Votre choix --> ";
			cin >> choixRemplissage;
		}

		if (choixRemplissage == 3) {
			afficherMenu1;
			validerMenu(1);
			afficherMenu2;
			validerMenu(2);
		}

		return choixRemplissage;

	}
	
}

// Demander et définir un symbole
char definirSymbole()
{
	char symbole;

	cout << "Veuillez choisir un symbole de remplissage pour vos formes : ";
	cin >> symbole;
	return symbole;
}

// Définir le symbole en fonction du mode de remplissage
char definirRemplissage(int choixRemplissage, char symbole)
{
	char choix; 

	// Choix de remplissage 1 -> plein
	if (choixRemplissage == 1) {
		choix = symbole;
	}
	// Choix de remplissage 2 -> vide
	else if (choixRemplissage == 2) {
		choix = ' ';
	}
	return choix;
}

// Traiter le Rectangle pour afficher les bonne dimensions et le bon remplissage
void traiterRectangle(int choixRemplissage)
{
	int hauteur;
	int largeur;
	char symbole;

	cout << "Entrez la hauteur du rectangle : ";
	hauteur = saisirEntier();

	cout << "Entrez la largeur du rectangle : ";
	largeur = saisirEntier();
	// Plein
	if (choixRemplissage == 1) {
		symbole = definirSymbole();
		cout << endl;
		cout << "Voici votre rectangle plein de "<< hauteur << "x" << largeur << " :" << endl;
		cout << endl;
		dessinerRectangle(hauteur, largeur, choixRemplissage, symbole);
	}
	// Vide
	else if (choixRemplissage == 2) {
		cout << "Voici votre rectangle vide de " << hauteur << "x" << largeur << " :" << endl;
		cout << endl;
		dessinerRectangle(hauteur, largeur, choixRemplissage, ' ');
	}
}

// Dessiner le rectangle vide ou plein
void dessinerRectangle(int hauteur, int largeur, int choixRemplissage, char symbole)
{
	char remplissage = definirRemplissage(choixRemplissage, symbole);

	for (int j = 0; j < hauteur; j++) {

		for (int i = 0; i < largeur; i++) {
			if (i == 0 || i == (largeur - 1)) {
				cout << "*";
			}
			else if (j == 0 || j == (hauteur - 1)) {
				cout << "*";
			}
			else {
				cout << remplissage;
			}
		}
		cout << endl;
	}
}
	
// Traiter le triangle pour le dessiner avec les options de remplissage dans les 
// 4 positions alétoires.
void traiterTriangle(int choixRemplissage)
{
	int hauteur;
	int alea = genererNombreAleatoire();
	char symbole;

	cout << "Entrez la hauteur du triangle : ";
	hauteur = saisirEntier();

	cout << endl;
	if (choixRemplissage == 1) {
		symbole = definirSymbole();
		cout << endl;
		cout << "Voici votre triangle plein de hauteur " << hauteur << ":" << endl;
		cout << endl;
	}
	else if (choixRemplissage == 2){
		symbole = ' ';
		cout << "Voici votre triangle vide de hauteur " << hauteur << ":" << endl;
		cout << endl;
	}

	switch (alea) {
		case 1:
			// Traiter le triangle et afficher sa position aléatoirement
			dessinerTriangle1(hauteur, choixRemplissage, symbole);
			break;
		case 2:
			dessinerTriangle2(hauteur, choixRemplissage, symbole);
			break;
		case 3:
			dessinerTriangle3(hauteur, choixRemplissage, symbole);
			break;
		case 4:
			dessinerTriangle4(hauteur, choixRemplissage, symbole);
			break;
	}
}

// dessiner les triangles (triangle1, tirangle2, triangle3, triangle4)
void dessinerTriangle1(int hauteur, int choixRemplissage, char symbole)
{
	/*
	
	*****
	****
	***
	**
	*
	
	*/
	char remplissage = definirRemplissage(choixRemplissage, symbole);
	int triangle2 = hauteur;

	for (int i = 0; i < hauteur; i++) {
		for (int j = triangle2 - 1; j > 0; j--) {
			if (j == triangle2 - 1) {
				cout << "*";
			}
			else if (i == 0) {
				cout << "*";
			}
			else {
				cout << remplissage;
			}
		}
		cout << "*" << endl;
		triangle2 -= 1;
	}
}

void dessinerTriangle2(int hauteur, int choixRemplissage, char symbole)
{
	/*

	*
	**
	***
	****
	*****

	*/
	
	char remplissage = definirRemplissage(choixRemplissage, symbole);
	int triangle = 0;

	for (int i = 0; i < hauteur + 1; i++) {
		for (int k = 0; k < triangle; k++) {
			if (i == (hauteur)) {
				cout << "*";
			}
			else if (k == 0) {
				cout << "*";
			}
			else if (k == (triangle - 1)) {
				cout << "*";
			}
			else {
				cout << remplissage;
			}
		}
		cout << endl;
		triangle += 1;
	}
}

	

void dessinerTriangle3(int hauteur, int choixRemplissage, char symbole)
{
	/*
	*****
	 ****
	  ***
	   **
		*
	*/
	char remplissage = definirRemplissage(choixRemplissage, symbole);
	int triangle = 0;
	int triangle2 = hauteur;

	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < triangle; j++) {
			cout << " ";
		}
		for (int k = 0; k < triangle2; k++) {
			if (i == 0) {
				cout << "*";
			}
			else if (k == 0 || k == (triangle2 - 1)) {
				cout << "*";
			}
			else {
				cout << remplissage;
			}
		}
		triangle += 1;
		triangle2 -= 1;
		cout << endl;
	}
}


void dessinerTriangle4(int hauteur, int choixRemplissage, char symbole)
{
	/*
		*
	   **
	  ***
	 ****
	*****
	*/
	char remplissage = definirRemplissage(choixRemplissage, symbole);
	int triangle = 0;
	int triangle2 = hauteur;

	for (int i = 0; i < hauteur + 1; i++) {
		for (int j = triangle2; j > 0; j--) {
			cout << " ";
		}
		for (int k = 0; k < triangle; k++) {
			if (i == (hauteur)) {
				cout << "*";
			}
			else if (k == 0 || k == (triangle - 1)) {
				cout << "*";
			}
			else {
				cout << remplissage;
			}
		}
		cout << endl;
		triangle2 -= 1;
		triangle += 1;

	}
}
	
// Traiter le choix de l'utilisateur pour les dimensions du losange et le choix de remplissage
void traiterLosange(int choixRemplissage)
{
	int hauteur;
	char symbole;

	cout << "Entrez la hauteur du Losange : ";
	hauteur = saisirEntier();

	cout << endl;

	if (choixRemplissage == 1) {
		symbole = definirSymbole();
		cout << "Voici votre losange plein de hauteur " << hauteur << " :" << endl;
		cout << endl;
		dessinerLosange(hauteur, choixRemplissage, symbole);

	}

	else if (choixRemplissage == 2) {
		symbole = ' ';
		cout << "Voici votre losange vide de hauteur " << hauteur << " :" << endl;
		cout << endl;
		dessinerLosange(hauteur, choixRemplissage, symbole);

	}
}

// Dessiner losanges
void dessinerLosange(int hauteur, int choixRemplissage, char symbole)
{
	/*
	 *
	*#*
   *###*
  *#####*
 *#######*
  *#####*
   *###*
	*#*
	 *
	*/
	char remplissage = definirRemplissage(choixRemplissage, symbole);
	int triangle = 0;
	int triangle2 = hauteur;
	int triangle3 = 0;
	int triangle4 = hauteur;

	for (int i = 0; i < hauteur + 1; i++) {
		for (int j = triangle2; j > 0; j--) {
			cout << " ";
		}
		for (int n = 0; n < triangle; n++) {
			if (n == 1) {
				cout << "*";
			}
			else if (n < 1) {
				cout << " ";
			}
			else {
				cout << remplissage;
			}
		}
		for (int k = 0; k < triangle; k++) {
			if (k == triangle - 1) {
				cout << "*";
			}
			else {
				cout << remplissage;
			}
		}

		cout << endl;
		triangle2 -= 1;
		triangle += 1;
	}
	for (int i = 0; i < hauteur - 1; i++) {
		for (int j = 0; j < triangle3; j++) {
			cout << " ";
		}
		for (int n = 0; n < triangle4; n++) {
			if (n == 2) {
				cout << "*";
			}
			else if (n < 2) {
				cout << " ";
			}
			else {
				cout << remplissage;
			}
		}
		for (int k = 0; k < triangle4; k++) {
			if (k == triangle4 - 2) {
				cout << "*";
			}
			else if (k > triangle4 - 2) {
				cout << " ";
			}
			else {
				cout << remplissage;
			}
		}
		cout << endl;
		triangle3 += 1;
		triangle4 -= 1;
	}
}

// Traiter les dimensions du carré et son remplissage
// La fonction fait appel à dessinerRectangle()
void traiterCarre(int choixRemplissage)
{
	int hauteur;
	int largeur;
	char symbole;

	cout << "Entrez la hauteur du carré : ";
	hauteur = saisirEntier();
	cout << endl;

	largeur = hauteur * 2;

	if (choixRemplissage == 1) {
		symbole = definirSymbole();
		cout << "Voici votre carré plein de hauteur " << hauteur << " :" << endl;
		cout << endl;
		dessinerRectangle(hauteur, largeur, choixRemplissage, symbole);
	}

	else if (choixRemplissage == 2) {
		symbole = ' ';
		cout << "Voici votre carrée vide de hauteur " << hauteur <<  " :" << endl;
		cout << endl;
		dessinerRectangle(hauteur, largeur, choixRemplissage, symbole);
	}
}

// Générer un nombre aléatoire pour les positions du triangle.
int genererNombreAleatoire()
{
	srand(time(NULL));
	return rand() % 4 + 1;
	
}
