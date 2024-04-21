/**
 * Fichier : column.h (fichier d'en-tête de function.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.1
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // librairie string.h permettant de traiter les chaînes de caractères

#define REALOC_SIZE 256   // constante d'allocation paramétrée sur 256 octets

typedef struct {   // structure de nos colonnes
    int logical_size;
    int physical_size;
    int* Datas;
    char* Title;
} COLUMN;

COLUMN *create_column(char* title);   // prototype de la fonction permettant de créer une nouvelle colonne vide
int insert_value(COLUMN* col, int value);   // prototype de la fonction permettant d'insérer une valeur dans une colonne
void delete_column(COLUMN **col);   // prototype de la fonction permettant de supprimer une colonne
void print_col(COLUMN* col);   // prototype de la fonction permettant d'afficher une colonne
int occurrences(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre d'occurrences
int value_at_position(COLUMN* col, int position);   // prototype de la fonction permettant de trouver la valeur à une position
int number_of_little_values(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre de valeurs inférieures
int number_of_big_values(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre de valeurs supérieures
int number_of_equal_values(COLUMN* col, int x);   // prototype de la fonction permettant de trouver le nombre de valeurs égales