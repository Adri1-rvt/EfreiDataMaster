/**
 * Fichier : cdataframe.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.1
 */


#include "cdataframe.h"   // inclure le fichier d'en-tête associé

/**
 * Nom : create_dataframe
 * Paramètre : /
 * Sortie : pointeur vers une structure ccdataframe
 * Fonctionnement : créer une structure cdataframe, lui allouer de l'espace et initialiser
 */
CDATAFRAME* create_dataframe() {
    CDATAFRAME* dataframe = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));   // allouer dynamiquement de l'espace sur les structures cdataframe
    if (dataframe == NULL) {   // vérifier que le malloc c'est bien passé
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return NULL;
    }

    dataframe -> number_col = 0;   // initialiser le nombre de colonnes à 0
    dataframe -> number_row = 0;   // initialiser le nombre de lignes à 0

    return dataframe;   // retourner un pointeur vers la structure créée
}


/**
 * Nom : fill_dataframe_by_input
 * Paramètre : pointeur vers une structure cdataframe
 * Sortie : /
 * Fonctionnement : remplir le cdataframe par saisies utilisateur
 */
void fill_dataframe_by_input(CDATAFRAME* dataframe) {
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &dataframe -> number_col);
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &dataframe -> number_row);

    for (int i = 0; i < dataframe -> number_row; i++) {   // parcourir les lignes
        char title[100];
        printf("Entrez le titre pour la colonne numero %d: ", i + 1);
        scanf("%s", title);
        COLUMN* col = create_column(title);   // créer la colonne
        dataframe -> columns[i] = col;
    }

    for (int i = 0; i < dataframe->number_col; i++) {   // parcourir les colonnes
        printf("Entrez les valeur pour la colonne %s:\n", dataframe -> columns[i] -> Title);
        for (int j = 0; j < dataframe -> number_row; j++) {   // parcourir les lignes
            int value;
            printf("Ligne %d: ", j + 1);
            scanf("%d", &value);
            insert_value(dataframe -> columns[i], value);   // insérer la valeur
        }
    }
}


/**
 * Nom : fill_dataframe
 * Paramètre : /
 * Sortie : pointeur vers une structure cdataframe
 * Fonctionnement : remplir le cdataframe par saisies utilisateur en dur
 */
void fill_dataframe(CDATAFRAME* dataframe) {
    dataframe -> number_col = 3;   // initialiser le nombre de colonnes à 3
    dataframe -> number_row = 3;   // initialiser le nombre de lignes à 3

    COLUMN* col1 = create_column("Col1");   // créer une colonne
    insert_value(col1, 1);   // insérer une valeur
    insert_value(col1, 2);   // insérer une valeur
    insert_value(col1, 3);   // insérer une valeur
    dataframe -> columns[0] = col1;   // mettre la colonne dans le cdataframe

    COLUMN* col2 = create_column("Col2");   // créer une colonne
    insert_value(col2, 4);   // insérer une valeur
    insert_value(col2, 5);   // insérer une valeur
    insert_value(col2, 6);   // insérer une valeur
    dataframe -> columns[1] = col2;   // mettre la colonne dans le cdataframe

    COLUMN* col3 = create_column("Col3");   // créer une colonne
    insert_value(col3, 7);   // insérer une valeur
    insert_value(col3, 8);   // insérer une valeur
    insert_value(col3, 9);   // insérer une valeur
    dataframe -> columns[2] = col3;   // mettre la colonne dans le cdataframe
}


int main2() {
    CDATAFRAME * dataframe = create_dataframe();

    // fill_dataframe_by_input(dataframe);
    fill_dataframe(dataframe);

    for (int i = 0; i < dataframe -> number_col; i++) printf("%s\t", dataframe -> columns[i] -> Title);   // afficher le titre des colonnes
    printf("\n");

    for (int i = 0; i < dataframe -> number_row; i++) {
        for (int j = 0; j < dataframe -> number_col; j++) printf("%d\t", dataframe -> columns[j] -> Datas[i]);   // afficher les valeurs du cdataframe
        printf("\n");
    }

    printf("\n\n\n");
    for (int i = 0; i < dataframe -> number_col; i++) {   // parcourir les colonnes
        printf("Contenu de la colonne \"%s\":\n", dataframe -> columns[i]->Title);
        print_col(dataframe -> columns[i]);   // Afficher le contenu de la colonne
        printf("\n");
    }

    return 0;
}