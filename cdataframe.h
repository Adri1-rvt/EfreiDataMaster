/**
 * Fichier : cdataframe.h (fichier d'en-tête de cdataframe.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include <stdio.h>
#include <stdlib.h>
#include "column.h"   // inclure le fichier d'en-tête column.h
#define COL_MAX 100   // constante de colonne max définie sur 100
#define ROW_MAX 1000   // constante de ligne max définie sur 1000


/**==========STRUCTURE==========*/
typedef struct {   // structure des cdataframe
    int number_col;   // nombre de colonnes
    int number_row;   // nombre de lignes
    COLUMN* columns[COL_MAX];   // tableau de pointeur vers les colonnes (taille physique définie sur la constante COL_MAW)
} CDATAFRAME;   // alias CDATAFRAME attribué à notre structure


/**==========PROTOTYPES DES FONCTIONS==========*/
// Fonctions d'alimentation
CDATAFRAME* create_dataframe();   // prototype de la fonction de création d'un cdataframe vide
void fill_dataframe_by_input(CDATAFRAME* dataframe);   // prototype de la fonction de remplissage du dataframe par saisi utilisateur
void fill_dataframe(CDATAFRAME* dataframe);   // prototype de la fonction de remplissage du dataframe en dur

// Fonctions d'affichage
void print_dataframe(CDATAFRAME* dataframe);   // prototype de la fonction permettant d'afficher le cdataframe
void print_somme_rows(CDATAFRAME* dataframe, int val);   // prototype de la fonction permettant d'afficher un certain nombre de lignes
void print_somme_columns(CDATAFRAME* dataframe, int val);   // prototype de la fonction permettant d'afficher un certain nombre de colonnes

// Opérations usuelles
void add_row(CDATAFRAME* dataframe, int* val);   // prototype de la fonction permettant d'ajouter une ligne
void remove_row(CDATAFRAME* dataframe, int index);   // prototype de la fonction permettant de supprimer une ligne
void add_column(CDATAFRAME* dataframe, char* title);   // prototype de la fonction permettant d'ajouter une colonne
void remove_column(CDATAFRAME* dataframe, int index);   // prototype de la fonction permettant de supprimer une colonne
void rename_column(CDATAFRAME* dataframe, int index, char* title2);   // prototype de la fonction permettant de renommer une colonne
int search_value(CDATAFRAME* dataframe, int val);   // prototype de la fonction permettant de chercher une valeur
int get_value(CDATAFRAME* dataframe, int row, int col);   // prototype de la fonction permettant d'accéder à une valeur
void set_value(CDATAFRAME* dataframe, int row, int col, int val);   // prototype de la fonction permettant de remplacer une valeur
void print_column_names(CDATAFRAME* dataframe);   // prototype de la fonction permettant d'afficher le nom des colonnes

// Analyse et statistiques
int count_rows(CDATAFRAME* dataframe);   // prototype de la fonction permettant de compter les lignes
int count_columns(CDATAFRAME* dataframe);   // prototype de la fonction permettant de compter les colonnes
int count_cells_equal(CDATAFRAME* dataframe, int val);   // prototype de la fonction permettant de compter les cellules = x
int count_cells_sup(CDATAFRAME* dataframe, int val);   // prototype de la fonction permettant de compter les cellules > x
int count_cells_inf(CDATAFRAME* dataframe, int val);   // prototype de la fonction permettant de compter les cellules < x

int test_cdataframe();   // prototype de la fonction de test du cdataframe