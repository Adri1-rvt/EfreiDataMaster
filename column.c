/**
 * Fichier : column.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.1
 */


#include "column.h"   // inclure le fichier d'en-tête associé

/**
 * Nom : create_column
 * Paramètre : tableau de caractères représentant le titre de la colonne
 * Sortie : pointeur sur la structure colonne créée
 * Fonctionnement : créer une colonne en allouant de l'espace mémoire et en initialisant les éléments de la structure
 */
COLUMN *create_column(char* title) {
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));   // allouer dynamiquement de l'espace mémoire pour le type COLUMN
    if (col == NULL) printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");   // vérifier si le pointeur retourné par malloc n'est pas égal à NULL (car espace insuffisant)

    col -> Title = (char*) malloc((strlen(title) + 1) * sizeof(char));   // allouer dynamiquement de l'espace mémoire pour le titre passé en paramètre
    if (col -> Title == NULL) printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");   // vérifier si le pointeur retourné par malloc n'est pas égal à NULL (car espace insuffisant)

    strcpy(col->Title, title);   // copier le titre passé en paramètre dans le nom de notre colonne
    col -> logical_size = 0;   // initialiser la taille logique de notre structure à 0
    col -> physical_size = 0;   // initialiser la taille physique de notre structure à 0
    col -> Datas = NULL;   // initialiser le tableau de valeurs de notre structure à NULL

    return col;   // retourner un pointeur sur la structure
}


/**
 * Nom : insert_value
 * Paramètre : entier représentant une valeur, pointeur sur une colonne
 * Sortie : entier pour la gestion d'erreurs
 * Fonctionnement : insérer une valeur dans la colonne passée en paramètre
 */
int insert_value(COLUMN* col, int value) {
    if (col == NULL) {   // vérifier que le pointeur sur la colonne n'est pas égal à NULL (sinon il y a eu une erreur lors de l'allocation mémoire de la structure)
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 0;
    }

    if (col -> physical_size == 0) {   // vérifier si la taille physique est égale à 0 (la colonne n'a pas encore été initialisée)
        col -> Datas = (int*) malloc(REALOC_SIZE * sizeof(int));   // allouer dynamiquement de l'espace pour le tableau de données avec la constante d'allocation
        if (col -> Datas == NULL) {   // vérifier si l'allocation a marché
            printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
            return 0;
        }
        col -> physical_size = REALOC_SIZE;   // mettre la taille physique à la valeur de la constante d'allocation
    }

    if (col -> logical_size == col -> physical_size) {   // vérifier si la taille logique = la taille physique (l'espace est épuisé)
        int *new = (int*) realloc(col -> Datas, (col -> physical_size + REALOC_SIZE) * sizeof(int));   // ré-allouer l'espace pour les données avec une taille supplémentaire de la constante d'allocation
        if (new == NULL) {   // vérifier si la ré-allocation a réussi
            printf("ERREUR 2 (voir index des erreurs sur GitHub)\n");
            return 0;
        }
        col -> Datas = new;   // faire une maj du pointeur des données avec le nouveau pointeur
        col -> physical_size += REALOC_SIZE;   // incrémenter la taille physique de la colonne avec la constante d'allocation
    }

    col -> Datas[col -> logical_size] = value;   // mettre la valeur dans la colonne à l'indice de taille logique
    col -> logical_size++;   // incrémenter la taille logique

    return 1;
}


/**
 * Nom : delete_column
 * Paramètre : double pointeur sur une colonne
 * Sortie : /
 * Fonctionnement : libérer tous les espaces mémoire des différents éléments de la structure puis de la structure elle-même
 */
void delete_column(COLUMN **col) {
    if (*col != NULL) {   // vérifier si le pointeur de la colonne n'est pas égal à NULL
        free((*col) -> Datas);   // libérer l'espace mémoire des données
        free((*col) -> Title);   // libérer l'espace mémoire du titre
        free(*col);   // libérer l'espace mémoire de la structure
        *col = NULL;   // mettre le pointeur de la colonne à NULL (pour éviter les erreurs)
    }
}


/**
 * Nom : print_col
 * Paramètre : pointeur sur une colonne
 * Sortie : /
 * Fonctionnement : afficher tout le contenu d'une colonne, avec les indices et les valeurs
 */
void print_col(COLUMN* col) {
    if (col == NULL) {   // vérifier si la colonne est viable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }

    printf("Les valeurs de la colonne \"%s\" sont :\n", col -> Title);   // afficher le titre de la colonne

    if (col -> logical_size == 0) {   // vérifier si la colonne est vide
        printf("Oh zut, la colonne est vide !\n");
        return;
    }

    for (int i = 0; i < col -> logical_size; i++) printf("[%d]\t%d\n", i, col->Datas[i]);   // parcourir chaque élément de la colonne et l'afficher à côté de son indice
}


/**
 * Nom : occurrences
 * Paramètre : pointeur vers une structure, entier à rechercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne et compter le nb d'occurrences de l'entier en paramètre
 */
int occurrences(COLUMN* col, int x) {
    if (col == NULL){
        printf("erreur");
        return 1;
    }
    int res=0;
    for(int i=0; i< col->logical_size; i++){
        if( x== col->Datas[i]){
            res++;
        }
    }
    return res;
}


/**
 * Nom : value_at_position
 * Paramètre : pointeur vers une structure, entier représentant un indice
 * Sortie : entier associé à l'indice passé en paramètre
 * Fonctionnement : parcourir une colonne pour trouver la valeur associée à une certaine position
 */
int value_at_position(COLUMN* col, int x) {
    if(col==NULL){
        printf("erreur");
        return 1;
    }
    if(x<0 || x> col->logical_size){
        printf("erreur");
        return 1;
    }
    return col->Datas[x];
}


/**
 * Nom : number_of_little_values
 * Paramètre : pointeur vers une structure, entier à chercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne pour trouver le nombre de valeurs inférieures
 */
int number_of_little_values(COLUMN* col, int x) {
    if(col==NULL){
        printf("erreur");
        return 1;
    }
    int res=0;
    for(int i=0; i<col->logical_size; i++){
        if(col->Datas[i] < x){
            res++;
        }
    }
    return res;
}


/**
 * Nom : number_of_little_values
 * Paramètre : pointeur vers une structure, entier à chercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne pour trouver le nombre de valeurs supérieures
 */
int number_of_big_values(COLUMN* col, int x) {
    if(col==NULL){
        printf("erreur");
        return 1;
    }
    int res=0;
    for(int i=0; i<col->logical_size; i++){
        if(col->Datas[i] > x){
            res++;
        }
    }
    return res;
}


/**
 * Nom : number_of_little_values
 * Paramètre : pointeur vers une structure, entier à chercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne pour trouver le nombre de valeurs égales
 */
int number_of_equal_values(COLUMN* col, int x) {
    if(col==NULL){
        printf("erreur");
        return 1;
    }
    int res=0;
    for(int i=0; i<col->logical_size; i++){
        if(col->Datas[i] == x){
            res++;
        }
    }
    return res;
}