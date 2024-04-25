/**
 * Fichier : main.c (fichier principal)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.1
 */


#include "cdataframe.h"   // inclure le fichier d'en-tête cdataframe.h (column.h en inclu dedans)
#include "interface.h"   // inclure le fichier d'en-tête interface.h

int main()
{
    menu();

    /** TEST DES FONCTIONS


    char title[50], title2[50];
    printf("Saisir le titre de la structure : ");
    scanf("%s", title);
    COLUMN *col1 = create_column(title);

    printf("\n");
    printf("Titre : %s\n", col1 -> Title);
    printf("Taille logique : %d\n", col1 -> logical_size);
    printf("Taille physique : %d\n", col1 -> physical_size);

    printf("\n");
    printf("\n");
    printf("Saisir le titre de la seconde structure : ");
    scanf("%s", title2);
    COLUMN *col2 = create_column(title2);

    printf("\n");
    printf("Titre : %s\n", col2 -> Title);
    printf("Taille logique : %d\n", col2 -> logical_size);
    printf("Taille physique : %d\n", col2 -> physical_size);


    printf("\n");
    printf("\n");
    printf("\n");

    COLUMN *col = create_column("Colonne 1");
    insert_value(col, 52);
    insert_value(col, 44);
    insert_value(col, 15);
    insert_value(col, 52);
    print_col(col);

    int val = 52;
    int count = occurrences(col, val);
    printf("Le nombre d'occurrences de %d dans la colonne est : %d\n", val, count);

    int pos = 2;
    int value = value_at_position(col, pos);
    printf("La valeur a la position %d est : %d\n", pos, value);

    int cpt = 0;
    cpt = number_of_little_values(col, 40);
    printf("Il y a %d valeurs inferieures a %d\n", cpt, 40);
    cpt = number_of_big_values(col, 10);
    printf("Il y a %d valeurs superieures a %d\n", cpt, 10);
    cpt = number_of_equal_values(col, 15);
    printf("Il y a %d valeurs egales a %d\n", cpt, 15);

    main2();

    */

    return 0;
}