/**
 * Fichier : advanced_column.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "advanced_column.h"   // inclure le fichier d'en-tête associé


/**==========FONCTIONS GENERALES DES COLONNES==========*/
COLUMN2 *create_column2(ENUM_TYPE type, char *title) {   // ajouter 2 pour ne pas avoir erreur du compilateur
    // Allouer de l'espace mémoire pour la structure COLUMN
    COLUMN2 *col = (COLUMN2*) malloc(sizeof(COLUMN2));
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return NULL;
    }
    int len = strlen(title) + 1;
    col -> title = (char*) malloc((len) * sizeof(char));
    if (col->title == NULL) printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
    strcpy(col -> title, title);
    col -> size = 0;
    col -> max_size = 0;
    col -> column_type = type;
    col -> data = NULL; // Le tableau de données sera alloué ultérieurement
    col -> index = NULL;
    return col;
}


int insert_value2(COLUMN2 *col, void *value) {
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 0;
    }
    if (col -> size == col -> max_size) {
        if (col -> max_size == 0) col -> data = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(COL_TYPE*));
        else col -> data = (COL_TYPE**) realloc(col -> data, (col -> max_size + REALOC_SIZE) * sizeof(COL_TYPE*));
        if (col -> data == NULL) {
            printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
            return 0;
        }
        col -> max_size += REALOC_SIZE;
    }
    switch(col -> column_type) {
        case UINT:
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(unsigned int));
            *((unsigned int*)(col -> data[col -> size])) = *((unsigned int*)value);
            break;
        case INT:
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(int));
            *((int*)(col -> data[col -> size])) = *((int*)value);
            break;
        case CHAR:
            col -> data[col->size] = (COL_TYPE*) malloc(sizeof(char));
            *((char*)(col -> data[col -> size])) = *((char*)value);
            break;
        case FLOAT:
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(float));
            *((float*)(col -> data[col -> size])) = *((float*)value);
            break;
        case DOUBLE:
            col -> data[col -> size] = (COL_TYPE*) malloc(sizeof(double));
            *((double*)(col -> data[col -> size])) = *((double*)value);
            break;
        case STRING:
            col -> data[col -> size] = (COL_TYPE*) malloc(strlen((char*)value) + 1);
            strcpy((char*)(col -> data[col -> size]), (char*)value);
            break;
        case STRUCTURE:
            printf("ERREUR : Insertion pour le type de structure n'est pas encore implémentée.\n");
            return 0;
            break;
        default:
            printf("ERREUR : Type de colonne non pris en charge.\n");
            return 0;
    }
    col -> size++;   // oncrémenter la taille logique
    return 1;
}



void delete_column2(COLUMN2 **col) {
    if (*col != NULL) {
        // Libérer l'espace mémoire des données de la colonne
        for (unsigned int i = 0; i < (*col)->size; ++i) {
            free((*col)->data[i]);
        }
        free((*col)->data); // Libérer l'espace mémoire du tableau de pointeurs de données
        free((*col)->title); // Libérer l'espace mémoire du titre de la colonne
        free(*col); // Libérer l'espace mémoire de la structure de la colonne
        *col = NULL; // Mettre le pointeur de la colonne à NULL pour éviter les erreurs
    }
}

void convert_value(COLUMN2 *col, unsigned long long int i, char *str, int size) {
    if (col == NULL) {
        printf("ERREUR : La colonne n'existe pas.\n");
        return;
    }

    if (i >= col->size) {
        printf("ERREUR : L'indice de ligne est hors limites.\n");
        return;
    }

    switch (col->column_type) {
        case UINT:
            snprintf(str, size, "%u", *((unsigned int*)(col->data[i])));
            break;
        case INT:
            snprintf(str, size, "%d", *((int*)(col->data[i])));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)(col->data[i])));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float*)(col->data[i])));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double*)(col->data[i])));
            break;
        case STRING:
            snprintf(str, size, "%s", (char*)(col->data[i]));
            break;
        case STRUCTURE:
            // Implémentez la conversion pour le type de structure si nécessaire
            printf("ERREUR : Conversion pour le type de structure n'est pas encore implémentée.\n");
            break;
        default:
            printf("ERREUR : Type de colonne non pris en charge.\n");
            break;
    }
}

void print_col2(COLUMN2 *col) {
    if (col == NULL) {
        printf("ERREUR : La colonne n'existe pas.\n");
        return;
    }

    printf("Contenu de la colonne \"%s\":\n", col->title);
    for (unsigned int i = 0; i < col->size; ++i) {
        char value_str[100]; // Définir une taille suffisamment grande pour stocker la valeur convertie en chaîne
        convert_value(col, i, value_str, sizeof(value_str));
        printf("[%u] %s\n", i, value_str);
    }
}





int main3() {
    // Création d'une colonne de type entier
    COLUMN2 *int_column = create_column2(INT, "Integer Column");

    // Insertion de quelques valeurs dans la colonne entière
    int val1 = 10, val2 = 20, val3 = 30;
    insert_value2(int_column, &val1);
    insert_value2(int_column, &val2);
    insert_value2(int_column, &val3);

    // Affichage du contenu de la colonne entière
    printf("Contenu de la colonne entière :\n");
    print_col2(int_column);

    // Libération de l'espace mémoire alloué pour la colonne entière
    delete_column2(&int_column);

    // Création d'une colonne de type caractère
    COLUMN2 *char_column = create_column2(CHAR, "Char Column");

    // Insertion de quelques valeurs dans la colonne de caractères
    char char1 = 'A', char2 = 'B', char3 = 'C';
    insert_value2(char_column, &char1);
    insert_value2(char_column, &char2);
    insert_value2(char_column, &char3);

    // Affichage du contenu de la colonne de caractères
    printf("\nContenu de la colonne de caractères :\n");
    print_col2(char_column);

    // Libération de l'espace mémoire alloué pour la colonne de caractères
    delete_column2(&char_column);

    return 0;
}
