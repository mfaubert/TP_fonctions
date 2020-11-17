#pragma once


void afficherMenu1();
void afficherMenu2();
int saisirEntier();
int validerMenu(int choixMenu);
char definirSymbole();
char definirRemplissage(int choixRemplissage, char symbole);
void traiterRectangle(int choixRemplissage);
void dessinerRectangle(int hauteur, int largeur, int choixRemplissage, char symbole);
void traiterTriangle(int choixRemplissage);
void dessinerTriangle1(int hauteur, int choixRemplissage, char symbole);
void dessinerTriangle2(int hauteur, int choixRemplissage, char symbole);
void dessinerTriangle3(int hauteur, int choixRemplissage, char symbole);
void dessinerTriangle4(int hauteur, int choixRemplissage, char symbole);
void traiterLosange(int choixRemplissage);
void dessinerLosange(int hauteur, int choixRemplissage, char symbole);
void traiterCarre(int choixRemplissage);
int genererNombreAleatoire();
