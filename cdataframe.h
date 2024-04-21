/**
 * Fichier : cdataframe.h (fichier d'en-tête de cdataframe.c)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.1
 */


#include <stdio.h>
#include <stdlib.h>
#include "column.h"   // inclure le fichier d'en-tête column.h

#define COL_MAX 100   // constante de colonne max définie sur 100
#define ROW_MAX 1000   // constante de ligne max définie sur 1000

typedef struct {   // structure des cdataframe
    int number_col;
    int number_row;
    COLUMN* columns[COL_MAX];
} CDATAFRAME;

CDATAFRAME* create_dataframe();   // prototype de la fonction de création d'un cdataframe vide
void fill_dataframe_by_input(CDATAFRAME* dataframe);   // prototype de la fonction de remplissage du dataframe par saisies utilisateur
void fill_dataframe(CDATAFRAME* dataframe);   // prototype de la fonction de remplissage du dataframe en dur
int main2();   // prototype de la fonction de test du cdataframe