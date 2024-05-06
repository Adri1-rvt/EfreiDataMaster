/**
 * Fichier : interface.h (fichier d'en-tête de interface.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include <stdio.h>


/**==========PROTOTYPES DES FONCTIONS==========*/
void menu();   // prototype de la fonction permettant d'afficher le menu de notre programme






/**
 * Créer une nouvelle colonne vide avec le titre spécifié
 * @param type: type de la colonne (ENUM_TYPE)
 * @param title: titre de la colonne (char*)
 * @return: pointeur vers la colonne créée (COLUMN*)
 */