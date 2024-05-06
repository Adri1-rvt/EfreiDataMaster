#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REALOC_SIZE 256   // constante d'allocation paramétrée sur 256 octets

// Définition de l'énumération pour les types de colonne
enum enum_type {
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};

typedef enum enum_type ENUM_TYPE;

// Définition de l'union pour stocker les différentes valeurs possibles dans une colonne
union column_type {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE;

// Définition de la structure pour une colonne
struct column {
    char *title;
    unsigned int size; // taille logique
    unsigned int max_size; // taille physique
    ENUM_TYPE column_type;
    COL_TYPE **data; // tableau de pointeurs vers les données stockées
    unsigned long long int *index; // tableau d'entiers
};
typedef struct column COLUMN2;






int main3();