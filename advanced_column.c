/**
 * Fichier : advanced_column.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "advanced_column.h"   // inclure le fichier d'en-tête associé


/**==========FONCTIONS GENERALES DES COLONNES AVANCEES==========*/
/**
 * Nom : create_column2
 * Paramètre : chaîne de carctères du titre, type de données
 * Sortie : pointeur vers une structure colonne
 * Fonctionnement : créer une colonne en allouant de l'espace mémoire et en initialisant les différends éléments de la structure
 */
COLUMN2 *create_column2(ENUM_TYPE type, char *title) {
    COLUMN2 *col = (COLUMN2*) malloc(sizeof(COLUMN2));   // allouer dynamiquement de l'espace pour la structure COLUMN2 (ajout du 2 pour éviter les erreurs de conflit du compilateur)
    if (col == NULL) {   // vérifier si l'allocation mémoire a échoué
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return NULL;
    }
    int len = strlen(title) + 1;   // définir la taille d'allocation en comptant les caractères de title
    col -> title = (char*) malloc((len) * sizeof(char));   // allouer dynamiquement de l'espace mémoire pour la chaîne de caractères
    if (col -> title == NULL) printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");   // vérifier si l'allocation a échoué
    strcpy(col -> title, title);   // copier le titre dans le titre de la structure colonne
    col -> size = 0;
    col -> max_size = 0;
    col -> column_type = type;
    col -> data = NULL;
    col -> index = NULL;
    return col;   // retourner un pointeur sur la structure créée
}


/**
 * Nom : insert_value2
 * Paramètre : pointeur sur une structure, pointeur sur une valeur
 * Sortie : entier
 * Fonctionnement : insérer une valeur à la fin de la colonne
 */
int insert_value2(COLUMN2 *col, void *value) {
    if (col == NULL) {   // vérifier que le pointeur est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 0;
    }
    if (col -> size == col -> max_size) {   // vérifier si la taille logique a atteint la taille physique
        if (col -> max_size == 0) col -> data = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(COL_TYPE*));   // si la taille physique est à 0, allouer de l'espace au tableau de données avec la constante d'allocation
        else col -> data = (COL_TYPE**) realloc(col -> data, (col -> max_size + REALOC_SIZE) * sizeof(COL_TYPE*));   // sinon réallouer de l'espace avec la constante d'allocation
        if (col -> data == NULL) {   // vérifier si l'allocation mémoire a échoué
            printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
            return 0;
        }
        col -> max_size += REALOC_SIZE;   // incrémenter la taille physique avec la constante d'allocation
    }
    switch(col -> column_type) {   // traiter tous les types de données avec un switch case
        case UINT:   // traiter les unsigned int
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(unsigned int));
            *((unsigned int*)(col -> data[col -> size])) = *((unsigned int*)value);
            break;
        case INT:   // traiter les entiers
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(int));
            *((int*)(col -> data[col -> size])) = *((int*)value);
            break;
        case CHAR:   // traiter les caractères
            col -> data[col->size] = (COL_TYPE*) malloc(sizeof(char));
            *((char*)(col -> data[col -> size])) = *((char*)value);
            break;
        case FLOAT:   // traiter les flottants
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(float));
            *((float*)(col -> data[col -> size])) = *((float*)value);
            break;
        case DOUBLE:   // traiter les doubles
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(double));
            *((double*)(col -> data[col -> size])) = *((double*)value);
            break;
        case STRING:   // traiter les chaînes de carctères
            col -> data[col -> size] = (COL_TYPE*) malloc(strlen((char*)value) + 1);
            strcpy((char*)(col -> data[col -> size]), (char*)value);
            break;
        case STRUCTURE:   // traiter les structures
            printf("ERREUR 7 (voir index des erreurs sur GitHub)\n");
            return 0;
        default:
            printf("ERREUR 7 (voir index des erreurs sur GitHub)\n");
            return 0;
    }
    col -> size++;   // incrémenter la taille logique
    return 1;   // retourner 1 si tout s'est bien passé
}


/**
 * Nom : delete_column2
 * Paramètre : double pointeur vers une structure
 * Sortie : /
 * Fonctionnement : libérer la mémoire de toutes les variables eet supprimer la structure
 */
void delete_column2(COLUMN2 **col) {
    if (*col != NULL) {   // vérifier que la colonne existe
        for (unsigned int i = 0; i < (*col) -> size; ++i) {
            free((*col) -> data[i]);
        }
        free((*col) -> data);   // libérer l'espace mémoire du tableau de pointeurs de données
        free((*col) -> title);   // libérer l'espace mémoire du titre
        free(*col);   // libérer l'espace mémoire de la structure
        *col = NULL;   // mettre le pointeur de la colonne à NULL
    }
}


/**
 * Nom : convert_value
 * Paramètre : pointeur sur une structure, entier i, chaîne de caractères, entier taille
 * Sortie : /
 * Fonctionnement : convertir tout type de données en chaîne de caractère afin de faciliter l'affichage
 */
void convert_value(COLUMN2 *col, int i, char *str, int size) {
    if (col == NULL) {   // vérifier que le pointeur est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (i >= col -> size) {   // vérifier si l'indice de ligne est cohérent
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    switch (col -> column_type) {   // traiter tous les types de données avec un switch case
        case UINT:   // traiter les unsigned int
            snprintf(str, size, "%u", *((unsigned int*)(col -> data[i])));
            break;
        case INT:   // traiter les entiers
            snprintf(str, size, "%d", *((int*)(col -> data[i])));
            break;
        case CHAR:   // traiter les caractères
            snprintf(str, size, "%c", *((char*)(col -> data[i])));
            break;
        case FLOAT:   // traiter les flottants
            snprintf(str, size, "%f", *((float*)(col -> data[i])));
            break;
        case DOUBLE:   // traiter les doubles
            snprintf(str, size, "%lf", *((double*)(col -> data[i])));
            break;
        case STRING:   // traiter les chaînes de carctères
            snprintf(str, size, "%s", (char*)(col -> data[i]));
            break;
        default:
            printf("ERREUR : Type de colonne non pris en charge.\n");
            break;
    }
}


/**
 * Nom : print_col2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers la structure
 * Sortie : /
 * Fonctionnement : afficher la colonne fournie
 */
void print_col2(COLUMN2 *col) {
    if (col == NULL) {   // vérifier que la colonne est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    for (int i = 0; i < col -> size; ++i) {   // parcourir la colonne
        char str[100];
        convert_value(col, i, str, sizeof(str));   // convertir en str
        printf("[%u] %s\n", i, str);   // afficher l'élément de la colonne
    }
}


/**
 * Nom : occurrences2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, pointeur sur un entier
 * Sortie : entier
 * Fonctionnement : trouver le nombre d'occurrence d'un élément dans la colonne
 */
int occurrences2(COLUMN2 *col, void *x) {
    if (col == NULL || x == NULL) return 0;   // vérifier que les paramètres sont valides
    int cpt = 0;   // initialiser un compteur à 0
    switch (col -> column_type) {
        case INT:
            for (int i = 0; i < col -> size; i++) if (*((int *)col -> data[i]) == *((int *)x)) cpt++;
            break;
        case CHAR:
            for (int i = 0; i < col -> size; i++) if (*((char *)col -> data[i]) == *((char *)x)) cpt++;
            break;
        case FLOAT:
            for (int i = 0; i < col -> size; i++) if (*((float *)col -> data[i]) == *((float *)x)) cpt++;
            break;
        case DOUBLE:
            for (int i = 0; i < col -> size; i++) if (*((double *)col -> data[i]) == *((double *)x)) cpt++;
            break;
        case STRING:
            for (int i = 0; i < col -> size; i++) if (*((char *)col -> data[i]) == *((char *)x)) cpt++;
            break;
        default:
            printf("ERREUR 7 (voir index des erreurs sur GitHub)\n");
            break;
    }
    return cpt;   // retourner le compteur
}


/**
 * Nom : value_at_position2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, entier
 * Sortie : /
 * Fonctionnement : trouver la valeur à la position x
 */
void *value_at_position2(COLUMN2 *col, int x) {
    if (col == NULL || x >= col -> size) return NULL;   // vérifier que les paramètres sont valides
    return col -> data[x];   // retourner la valeur à la position x
}


/**
 * Nom : number_of_big_values2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, entier
 * Sortie : entier
 * Fonctionnement : trouver le nombre de valeurs supérieures à x
 */
int number_of_big_values2(COLUMN2 *col, void *x) {
    if (col == NULL || x == NULL) return 0;   // vérifier que les paramètres sont valides

    int cpt = 0;
    switch (col -> column_type) {
        case INT:
            for (unsigned int i = 0; i < col -> size; i++) {
                if (*((int *)col -> data[i]) > *((int *)x)) {
                    cpt++;
                }
            }
            break;
        case CHAR:
            // Comparaisons pour le type char
            break;


            /**---------------------------------------------
            // Ajouter les autres cas pour les autres types de données
             ------------------------------------------------*/


        default:
            printf("Type de colonne non pris en charge\n");
            break;
    }

    return cpt;
}

// Retourner le nombre de valeurs qui sont inférieures à x
int number_of_little_values2(COLUMN2 *col, void *x) {
    if (col == NULL || x == NULL) return 0;   // vérifier que les paramètres sont valides

    int cpt = 0;
    switch (col -> column_type) {
        case INT:
            for (unsigned int i = 0; i < col -> size; i++) {
                if (*((int *)col -> data[i]) < *((int *)x)) {
                    cpt++;
                }
            }
            break;
        case CHAR:
            // Comparaisons pour le type char
            break;
            // Ajouter les autres cas pour les autres types de données
        default:
            printf("Type de colonne non pris en charge\n");
            break;
    }

    return cpt;
}

// Retourner le nombre de valeurs qui sont égales à x
int number_of_equal_values2(COLUMN2 *col, void *x) {
    if (col == NULL || x == NULL) return 0;   // vérifier que les paramètres sont valides

    int count = 0;
    switch (col -> column_type) {
        case INT:
            for (unsigned int i = 0; i < col -> size; i++) {
                if (*((int *)col -> data[i]) == *((int *)x)) {
                    count++;
                }
            }
            break;
        case CHAR:
            // Comparaisons pour le type char
            break;
            // Ajouter les autres cas pour les autres types de données
        default:
            printf("Type de colonne non pris en charge\n");
            break;
    }

    return count;
}













int test_advanced_column() {
    // Création d'une colonne de type CHAR
    COLUMN2 *char_col = create_column2(CHAR, "Char column");
    if (char_col == NULL) {
        printf("Erreur lors de la création de la colonne\n");
        return 1;
    }

    // Insertion de quelques valeurs dans la colonne
    char x = 'a', y = 'b', z = 'c';
    insert_value2(char_col, &x);
    insert_value2(char_col, &y);
    insert_value2(char_col, &z);

    // Affichage du contenu de la colonne
    printf("Contenu de la colonne CHAR :\n");
    print_col2(char_col);

    // Test de la fonction occurrences
    char search_char = 'b';
    printf("Nombre d'occurrences de '%c' : %d\n", search_char, occurrences2(char_col, &search_char));

    // Test de la fonction value_at_position
    int pos = 1;
    void *val = value_at_position2(char_col, pos);
    if (val != NULL) {
        printf("Valeur a la position %llu : %c\n", pos, *((char *)val));
    } else {
        printf("Aucune valeur a la position %llu\n", pos);
    }

    // Libération de la mémoire
    delete_column2(&char_col);

    return 0;
}