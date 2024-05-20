/**
 * Fichier : cdataframe.h (fichier d'en-tête de advanced_cdataframe.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "advanced_column.h"


/**==========STRUCTURE==========*/
struct dataframe {
    COLUMN2 **columns; // Tableau de pointeurs vers les colonnes
    int num_columns; // Nombre de colonnes dans le dataframe
};
typedef struct dataframe DATAFRAME2;


/**==========PROTOTYPES DES FONCTIONS==========*/
// Fonctions d'alimentation
DATAFRAME2 *create_dataframe2();   // prototype de la fonction de création d'un cdataframe vide
void fill_dataframe_user(DATAFRAME2 *dataframe);   // prototype de la fonction de remplissage du dataframe par saisi utilisateur
void fill_dataframe_hardcoded(DATAFRAME2 *dataframe);   // prototype de la fonction de remplissage du dataframe en dur
void delete_dataframe(DATAFRAME2 **dataframe);   //prototype de la fonction pour libérer la mémoire allouée pour le CDataframe

// Fonctions d'affichage
void print_dataframe2(DATAFRAME2 *dataframe);   // prototype de la fonction permettant d'afficher le cdataframe
void print_partial_rows2(DATAFRAME2 *dataframe, int start, int end);   // prototype de la fonction permettant d'afficher un certain nombre de lignes
void print_partial_columns2(DATAFRAME2 *dataframe, int start, int end);   // prototype de la fonction permettant d'afficher un certain nombre de colonnes

// Opérations usuelles
void add_row2(DATAFRAME2 *dataframe, void **values);   // prototype de la fonction permettant d'ajouter une ligne
void delete_row(DATAFRAME2 *dataframe, int pos);   // prototype de la fonction permettant de supprimer une ligne
void add_column2(DATAFRAME2 *dataframe, ENUM_TYPE type, char *title);   // prototype de la fonction permettant d'ajouter une colonne
void delete_column3(DATAFRAME2 *dataframe, int pos);   // prototype de la fonction permettant de supprimer une colonne
void rename_column2(DATAFRAME2 *dataframe, int index, char *new_title);   // prototype de la fonction permettant de renommer une colonne
int search_value2(DATAFRAME2 *dataframe, void *value);   // prototype de la fonction permettant de chercher une valeur
void print_column_names2(DATAFRAME2 *dataframe);   // prototype de la fonction permettant d'afficher le nom des colonnes

// Analyse et statistiques
int get_num_rows(COLUMN2 *column);
void print_num_rows2(DATAFRAME2 *dataframe);   // prototype de la fonction permettant de compter les lignes
void print_num_columns2(DATAFRAME2 *dataframe);   // prototype de la fonction permettant de compter les colonnes

// Test
int test_advanced_cdataframe();   // prototype de la fonction de test du cdataframe avancé