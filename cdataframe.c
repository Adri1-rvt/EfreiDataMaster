/**
 * Fichier : cdataframe.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.1
 */


#include "cdataframe.h"   // inclure le fichier d'en-tête associé

CDATAFRAME* create_dataframe() {
    CDATAFRAME* dataframe = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    if (dataframe == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return NULL;
    }
    dataframe -> number_col = 0;
    dataframe -> number_row = 0;
    return dataframe;
}

void fill_dataframe_by_input(CDATAFRAME* dataframe) {
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &dataframe -> number_col);
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &dataframe -> number_row);

    for (int i = 0; i < dataframe -> number_row; i++) {
        char title[100];
        printf("Entrez le titre pour la colonne numero %d: ", i + 1);
        scanf("%s", title);
        COLUMN* col = create_column(title);
        dataframe -> columns[i] = col;
    }

    for (int i = 0; i < dataframe->number_col; i++) {
        printf("Entrez les valeur pour la colonne %s:\n", dataframe -> columns[i] -> Title);
        for (int j = 0; j < dataframe -> number_row; j++) {
            int value;
            printf("Ligne %d: ", j + 1);
            scanf("%d", &value);
            insert_value(dataframe -> columns[i], value);
        }
    }
}

void fill_dataframe(CDATAFRAME* dataframe) {
    dataframe -> number_col = 3;
    dataframe -> number_row = 3;

    COLUMN* col1 = create_column("Col1");
    insert_value(col1, 1);
    insert_value(col1, 2);
    insert_value(col1, 3);
    dataframe -> columns[0] = col1;

    COLUMN* col2 = create_column("Col2");
    insert_value(col2, 4);
    insert_value(col2, 5);
    insert_value(col2, 6);
    dataframe -> columns[1] = col2;

    COLUMN* col3 = create_column("Col3");
    insert_value(col3, 7);
    insert_value(col3, 8);
    insert_value(col3, 9);
    dataframe -> columns[2] = col3;
}

int main2() {
    CDATAFRAME * dataframe = create_dataframe();

    // fill_dataframe_by_input(dataframe);
    fill_dataframe(dataframe);

    for (int i = 0; i < dataframe -> number_col; i++) printf("%s\t", dataframe -> columns[i]->Title);
    printf("\n");

    for (int i = 0; i < dataframe->number_row; i++) {
        for (int j = 0; j < dataframe->number_col; j++) printf("%d\t", dataframe -> columns[j]->Datas[i]);
        printf("\n");
    }

    return 0;
}
