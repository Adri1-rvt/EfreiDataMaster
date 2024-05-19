/**
 * Fichier : advanced_column.h (fichier d'en-tête de avanced_column.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // librairie string.h permettant de traiter les chaînes de caractères
#define REALOC_SIZE 256   // constante d'allocation paramétrée sur 256 octets


/**==========STRUCTURES ET ENUMERATION==========*/
enum enum_type {   // énumération pour les types de données des colonnes
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;   // définir le nom de la structure sur ENUM_TYPE

union column_type {   // union pour stocker les différents types de données possibles dans une colonne
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE;   // définir le nom de l'union sur COL_TYPE

struct column {   // structure pour une colonne
    char *title;   // chaîne de caractères du nom de notre colonne
    unsigned int size;   // taille logique
    unsigned int max_size;   // taille physique
    ENUM_TYPE column_type;   // énumération du type de données
    COL_TYPE **data;   // tableau de pointeurs vers les données stockées
    unsigned long long int *index;   // tableau d'entiers
};
typedef struct column COLUMN2;   // définir le nom de la structure sur COLUMN2 (ajout du 2 pour éviter les erreurs de conflit avec column.h)


/**==========PROTOTYPES DES FONCTIONS==========*/
COLUMN2 *create_column2(ENUM_TYPE type, char *title);   // prototype de la fonction permettant de créer une colonne
int insert_value2(COLUMN2 *col, void *value);   // prototype de la fonction permettant d'insérer une valeurs dans la colonne
void delete_column2(COLUMN2 **col);   // prototype de la fonction permettant de supprimer une colonne
void convert_value(COLUMN2 *col, int i, char *str, int size);
void print_col2(COLUMN2 *col);   // prototype de la fonction permettant d'afficher une colonne
int occurrences2(COLUMN2 *col, void *x);   // prototype de la fonction permettant de retourner le nombre d'occurrence d'une valeur dans la colonne
void *value_at_position2(COLUMN2 *col, int pos);
int number_of_little_values2(COLUMN2 *col, void *x);
int number_of_big_values2(COLUMN2 *col, void *x);
int number_of_equal_values2(COLUMN2 *col, void *x);

int test_advanced_column();   // prototype de la fonction permettant de tester les fonctionnalités des colonnes avancées