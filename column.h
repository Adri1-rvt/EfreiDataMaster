/**
 * Fichier : column.h (fichier d'en-tête de function.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // librairie string.h permettant de traiter les chaînes de caractères
#define REALOC_SIZE 256   // constante d'allocation paramétrée sur 256 octets
#define ASC 0   // constante de sens de tri ascendant paramétrée sur 0
#define DESC 1   // constante de sens de tri descendant paramétrée sur 0


/**==========STRUCTURES==========*/
typedef struct {   // structure de nos colonnes
    // variables générales
    int logical_size;   // taille logique de notre colonne
    int physical_size;   // taille physique de notre colonne
    int* Datas;   // tableau de données de notre colonne
    char* Title;   // chaîne de caractères du nom de notre colonne

    // variables pour les fonctionnalités avancées
    long *index;   // tableau d'index associé à notre colonne
    int valid_index;   // attribut de tri (0 si la colonne n’est pas du tout triée, -1 si la colonne est partiellement triée, 1 si la colonne triée)
    int index_size;   // taille de l'index
    int sort_dir;   // attribut de sens de tri effectuée (0: ASC, 1: DESC)
} COLUMN;   // alias COLUMN attribué à notre structure


/**==========PROTOTYPES DES FONCTIONS GENERALES==========*/
COLUMN *create_column(char* title);   // prototype de la fonction permettant de créer une nouvelle colonne vide
int insert_value(COLUMN* col, int value);   // prototype de la fonction permettant d'insérer une valeur dans une colonne
void delete_column(COLUMN **col);   // prototype de la fonction permettant de supprimer une colonne
void print_col(COLUMN* col);   // prototype de la fonction permettant d'afficher une colonne
int occurrences(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre d'occurrences
int value_at_position(COLUMN* col, int position);   // prototype de la fonction permettant de trouver la valeur à une position
int number_of_little_values(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre de valeurs inférieures
int number_of_big_values(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre de valeurs supérieures
int number_of_equal_values(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre de valeurs égales


/**==========PROTOTYPES DES FONCTIONS AVANCEES==========*/
void sort_column(COLUMN *col, int order);   // prototype de la fonction permettant trier une colonne
int binary_search(COLUMN *col, int value);   // prototype de la fonction permettant dee faire une recherche dichotomique


/**==========PROTOTYPE DE LA FONCTION DE TEST==========*/
int test_column();   // prototype de la fonction de test