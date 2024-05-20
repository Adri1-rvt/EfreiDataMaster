/**
 * Fichier : advanced_cdataframe.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "advanced_cdataframe.h"


/**==========FONCTIONS GENERALES DU CDATAFRAME AVANCE==========*/
/**
 * Nom : create_dataframe2 (2 pour éviter les erreurs de conflit)
 * Paramètre : /
 * Sortie : pointeur sur la structure cdataframe céée
 * Fonctionnement : créer un cdataframe, lui allouer de la mémoire et initialiser ses attributs
 */
DATAFRAME2 *create_dataframe2() {
    DATAFRAME2 *dataframe = (DATAFRAME2*) malloc(sizeof(DATAFRAME2));   // allouer dynamiquement de l'espace pour notre structure
    if (dataframe == NULL) {   // vérifier s'il y a eu un problème lors de l'allocation mémoire
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return NULL;
    }
    dataframe -> columns = NULL;   // initialiser le tableau de pointeurs vers les colonnes
    dataframe -> num_columns = 0;   // initialiser le nombre de colonnes à 0
    return dataframe;   // retourner un pointeur sur la structure créée
}


/**
 * Nom : fill_dataframe_user
 * Paramètre : pointeur vers une structure
 * Sortie : /
 * Fonctionnement : faire remplir le cdataframe par saisies utilisateur
 */
void fill_dataframe_user(DATAFRAME2 *dataframe) {
    if (dataframe == NULL) {   // vérifier que le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("Saisir le nombre de colonnes : ");
    int nc;   // déclarer une variable pour le numéro de colonne
    scanf("%d", &nc);   // saisir le nombre de colonnes
    dataframe -> columns = (COLUMN2**) malloc(nc * sizeof(COLUMN2*));   // allouer dynamiquement de l'espace pour le tableau de pointeurs vers lees colonnes
    if (dataframe -> columns == NULL) {   // vérifier si le tableau est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> num_columns = nc;   // initialiser le nombre de colonne avec la saisie utilisateur
    for (int i = 0; i < nc; ++i) {   // parcourir les colonnes
        printf("Saisir le titre de la colonne %u : ", i + 1);
        char title[100];   // déclarer un tableau de caractères pour le titre
        scanf("%s", title);   // saisir le titre (on a choisi de ne pas utiliser gets en supposant que le titre serait constituer que d'un mot)
        printf("Saisir le type de données choisi pour cette colonne %u (1: UINT, 2: INT, 3: CHAR, 4: FLOAT, 5: DOUBLE, 6: STRING, 7: STRUCTURE) : ", i + 1);
        int type;   // déclarer un entier correspondant au type de données utilisé
        scanf("%d", &type);   // saisir le type (sous forme d'entier)
        dataframe -> columns[i] = create_column2(type, title);   // créer la colonne avec la fonction de advanced_column.c
        if (dataframe -> columns[i] == NULL) {   // vérifier si l'allocation mémoire a marchée
            printf("ERREUR 1 (voir index des erreurs sur GitHub)\n", i + 1);
            for (int j = 0; j < i; ++j) delete_column2(&(dataframe -> columns[j]));   // parcourir les colonnes déjà créées et les libérer
            free(dataframe -> columns);   // libérer l'espace alloué au cdataframe
            dataframe -> num_columns = 0;   // réaffecter 0 au nombre de colonnes
            return;
        }
    }
}


/**
 * Nom : fill_dataframe_harcoded
 * Paramètre : pointeur vers une structure
 * Sortie : /
 * Fonctionnement : remplir le cdataframe en dur
 */
void fill_dataframe_hardcoded(DATAFRAME2 *dataframe) {
    if (dataframe == NULL) {   // vérifier si la cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> columns = (COLUMN2**) malloc(3 * sizeof(COLUMN2*));   // allouer de l'espace mémoire pour les colonnes du cdataframe
    if (dataframe -> columns == NULL) {   // vérifier si l'allocation mémoire a échoué
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> num_columns = 3;   // initialiser le nombre de colonnes à 3
    // créer un cdataframe sur les 3 premiers joueurs de tennis au classement actuel
    dataframe -> columns[0] = create_column2(INT, "Classemnt");   // créer une première colonne d'entier avec la fonction de advanced_column.c
    insert_value2(dataframe -> columns[0], &(int){1});   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[0], &(int){2});   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[0], &(int){3});   // ajouter une valeur à la colonne

    dataframe -> columns[1] = create_column2(FLOAT, "Victoires");   // créer une seconde colonne de flottants avec la fonction de advanced_column.c
    insert_value2(dataframe -> columns[1], &(float){0.71});   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[1], &(float){0.93});   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[1], &(float){0.78});   // ajouter une valeur à la colonne

    dataframe -> columns[2] = create_column2(STRING, "Nom");   // créer une troisième colonne de chaînes de caractères avec la fonction de advanced_column.c
    insert_value2(dataframe -> columns[2], "Djokovic");   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[2], "Sinner");   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[2], "Alcaraz");   // ajouter une valeur à la colonne
}


/**
 * Nom : delete_dataframe
 * Paramètre : double pointeur vers une structure
 * Sortie : /
 * Fonctionnement : libérer l'espace alloué aux éléments du cdataframe et le supprimer
 */
void delete_dataframe(DATAFRAME2 **dataframe) {
    if (*dataframe != NULL) {   // vérifier que le cdataframe n'est pas vide
        for (int i = 0; i < (*dataframe) -> num_columns; ++i) delete_column2(&((*dataframe) -> columns[i]));   // parcourir les colonnes et libérer leur mémoire allouée
        free((*dataframe) -> columns);   // libérer la mémoire allouée pour le tableau de pointeurs de colonnes
        free(*dataframe);   // libérer la mémoire du dataframe
        *dataframe = NULL;   // mettre le pointeur sur la structure à NULL (* car double pointeur)
    }
}


/**
 * Nom : print-dataframe2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure
 * Sortie : /
 * Fonctionnement : afficher tout le cdataframe
 */
void print_dataframe2(DATAFRAME2 *dataframe) {
    if (dataframe == NULL) {   // vérifier que le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < dataframe -> num_columns; ++i) printf("%-15s", dataframe -> columns[i] -> title);   // parcourir les colonnes et afficher leurs titres
    printf("\n");
    printf("-------------------------------------------------------\n");
    int max_size = 0;   // initialiser une variable qui représente la taille max
    for (int i = 0; i < dataframe -> num_columns; ++i) if (dataframe -> columns[i] -> size > max_size) max_size = dataframe -> columns[i] -> size;   // parcourir les colonnes et trouver la taille max
    for (int i = 0; i < max_size; ++i) {   // parcourir à partir de la taille max
        for (int j = 0; j < dataframe -> num_columns; ++j) {   // parcourir les colonnes
            char str[100];   // définir un tableau pour stocker la valeur convertie en chaîne
            if (i < dataframe -> columns[j] -> size) {
                convert_value(dataframe -> columns[j], i, str, sizeof(str));   // convertir la valeur en str pour l'afficher
                printf("%-15s", str);   // écrire la valeur qui a été convertie en chaîne de caractères
            }
            else printf("");   // écrire une chaîne vide si l'index est hors limites pour cette colonne
        }
        printf("\n");   // retourner à la ligne
    }
    printf("-------------------------------------------------------\n");
}


/**
 * Nom : print_partial_rows2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, entier de début, entier de fin
 * Sortie : /
 * Fonctionnement : afficher qu'une partie des lignes
 */
void print_partial_rows2(DATAFRAME2 *dataframe, int start, int end) {
    if (dataframe == NULL) {   // vérifier si la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (start >= dataframe -> columns[0] -> size || end >= dataframe -> columns[0] -> size) {   // vérifier si les coordonnées renseignées sont cohérentes
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("CDataframe des lignes %d a %d) :\n", start, end);
    printf("-------------------------------------------------------\n");
    for (unsigned int i = 0; i < dataframe -> num_columns; ++i) printf("%-15s", dataframe -> columns[i] -> title);   // parcourir les colonnes et afficher leur titre
    printf("\n");   // retourner à la ligne
    printf("-------------------------------------------------------\n");
    for (int i = start; i <= end; ++i) {   // parcourir les lignes spécifiées
        for (int j = 0; j < dataframe -> num_columns; ++j) {   // parcourir les colonnes
            char value_str[100];   // définir un tableau pour stocker la valeur convertie en chaîne
            if (i < dataframe -> columns[j] -> size) convert_value(dataframe -> columns[j], i, value_str, sizeof(value_str));   // convertir la valeur en str pour l'afficher
            else sprintf(value_str, "%s", "");   // afficher une chaîne vide si l'index est hors limites pour cette colonne
            printf("%-15s", value_str);   // afficher la valeur
        }
        printf("\n");   // retourner à la ligne
    }
    printf("-------------------------------------------------------\n");
}


/**
 * Nom : print_partial_columns2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, entier de début, entier de fin
 * Sortie : /
 * Fonctionnement : afficher qu'une partie des colonnes
 */
void print_partial_columns2(DATAFRAME2 *dataframe, int start, int end) {
    if (dataframe == NULL) {   // vérifier si notre structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (start >= dataframe -> num_columns || end >= dataframe -> num_columns) {   // vérifier si les coordonnées renseignées sont cohérentes
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("CDataframe des colonnes %u a %u) :\n", start, end);
    printf("-------------------------------------------------------\n");
    for (int i = start; i <= end; ++i) printf("%-15s", dataframe->columns[i]->title);   // parcourir les colonnes et afficher leur titre
    printf("\n");   // retourner à la ligne
    printf("-------------------------------------------------------\n");
    int max_size = 0;   // initialiser une variable qui représente la taille max
    for (int i = 0; i < dataframe -> num_columns; ++i) if (dataframe -> columns[i] -> size > max_size) max_size = dataframe -> columns[i] -> size;   // parcourir les colonnes et trouver la taille max
    for (int i = 0; i < max_size; ++i) {   // parcourir à partir de la taille max
        for (int j = start; j <= end; ++j) {   // parcourir entre le début et la fin
            char value_str[100];   // définir un tableau pour stocker la valeur convertie en chaîne
            if (i < dataframe -> columns[j] -> size) convert_value(dataframe -> columns[j], i, value_str, sizeof(value_str));   // convertir la valeur en str pour l'afficher
            else sprintf(value_str, "%s", "");   // afficher une chaîne vide si l'index est hors limites pour cette colonne
            printf("%-15s", value_str);   // afficher la valeur
        }
        printf("\n");   // retourner à la ligne
    }
    printf("-------------------------------------------------------\n");
}


/**
 * Nom : add_row2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur sur une structure, double pointeur sur une valeur
 * Sortie : /
 * Fonctionnement : rajouter une ligne à notre cdataframe
 */
void add_row2(DATAFRAME2 *dataframe, void **values) {
    if (dataframe == NULL) {   // vérifier que notre structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (values == NULL) {   // vérifier que le tableau de valeur n'est pas vide
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    for (int i = 0; i < dataframe -> num_columns; ++i) insert_value2(dataframe -> columns[i], values[i]);  // parcourir les colonnes et insérer les valeurs
}


/**
 * Nom : delete_row
 * Paramètre : pointeur vers une structure, position entier
 * Sortie : /
 * Fonctionnement : supprimer une colonne à partir de sa position dans le cdataframe
 */
void delete_row(DATAFRAME2 *dataframe, int pos) {
    if (dataframe == NULL) {   // vérifier que notre structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (pos >= dataframe -> columns[0] -> size) {   // vérifier que la position n'est pas hors limite du CDataframe
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    for (int i = 0; i < dataframe -> num_columns; ++i) {   // parcourir les colonnes
        free(dataframe -> columns[i] -> data[pos]);   // supprimer la valeur à l'indice spécifié
        for (int j = pos; j < dataframe -> columns[i] -> size - 1; ++j) dataframe -> columns[i] -> data[j] = dataframe -> columns[i] -> data[j + 1];   // décaler les autres valeurs dans la colonne
        dataframe -> columns[i] -> size--;   // décrémenter la taille de 1
    }
}


/**
 * Nom : add_column2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, énumération de types, chaîne de caractères du titre
 * Sortie : /
 * Fonctionnement : ajouter une colonne au cdataframe
 */
void add_column2(DATAFRAME2 *dataframe, ENUM_TYPE type, char *title) {
    if (dataframe == NULL) {   // vérifier que notre structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> columns = (COLUMN2**) realloc(dataframe -> columns, (dataframe -> num_columns + 1) * sizeof(COLUMN2*));  // réallouer de l'espace pour stocker un pointeur de plus vers une colonne
    if (dataframe -> columns == NULL) {   // vérifier s'il y a eu un problème lors de la réallocation mémoire
        printf("ERREUR 2 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> columns[dataframe -> num_columns] = create_column2(type, title);   // créer une nouvelle colonne avec la fonction de advanced_column.c
    if (dataframe -> columns[dataframe -> num_columns] == NULL) {   // vérifier s'il y a eu un problème lors de la création de la nouvelle colonne
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> num_columns++;   // incrémenter le nombre de colonnes
}


/**
 * Nom : delete_column3 (3 pour éviter les erreurs de conflit)
 * Paramètre : pointeur vers une structure, position entière
 * Sortie : /
 * Fonctionnement : supprimer une colonne
 */
void delete_column3(DATAFRAME2 *dataframe, int pos) {
    if (dataframe == NULL) {   // vérifie que le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (pos >= dataframe -> num_columns) {   // vérifier si la position est cohérente
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    delete_column2(&(dataframe -> columns[pos]));   // supprimer la colonne grâce à la fonction de advanced-column.c
    for (int i = pos; i < dataframe -> num_columns - 1; ++i) dataframe -> columns[i] = dataframe -> columns[i + 1];   // parcourir et décaler les pointeurs des colonnes suivantes dans le tableau
    dataframe -> num_columns--;   // décrémenter le nombre de colonne de 1
}


/**
 * Nom : rename_column2 (2 pour éviter les erreurs de conflit)
 * Paramètre : structure vers une colonne, index entier, titre chaîne de caractères
 * Sortie : /
 * Fonctionnement : renommer une colonne
 */
void rename_column2(DATAFRAME2 *dataframe, int index, char *new_title) {
    if (dataframe == NULL) {   // vérifie que le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (index >= dataframe -> num_columns) {   // vérifier si la position est cohérente
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    free(dataframe -> columns[index] -> title);   // libérer l'espace de l'ancien titre
    dataframe -> columns[index] -> title = (char*) malloc((strlen(new_title) + 1) * sizeof(char));   // allouer de l'espace por le nom
    if (dataframe -> columns[index] -> title == NULL) {   // vérifier si l'allocation mémoire a réussi
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    strcpy(dataframe -> columns[index] -> title, new_title);   // copier le nouveau titre
}


/**
 * Nom : search_value2 (2 pour éviter les erreurs de conflit)
 * Paramètre : pointeur sur une structure, pointeur vers une valeur (void pour pouvoir être de tt type)
 * Sortie : entier
 * Fonctionnement : chercher une valeur
 */
int search_value2(DATAFRAME2 *dataframe, void *value) {
    if (dataframe == NULL) {   // vérifier si le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return -1;
    }
    for (int i = 0; i < dataframe -> num_columns; ++i) if (occurrences2(dataframe -> columns[i], value)) return i;   // parcourir le cdataframe, utiliser la fonction occurences et retourner l'indice de la colonne où la valeur a été trouvée
    return -1;   // retourner -1 si la valeur n'a pas été trouvée dans le CDataframe
}


/**
 * Nom : print_column_names2
 * Paramètre : pointeur vers une structure
 * Sortie : /
 * Fonctionnement : afficher le nom des colonnes
 */
void print_column_names2(DATAFRAME2 *dataframe) {
    if (dataframe == NULL) {   // vérifier si notre cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    for (int i = 0; i < dataframe -> num_columns; ++i) printf("%s\n", dataframe -> columns[i] -> title);   // parcourir les titres des colonnes et afficher les titres
}


/**
 * Nom : get_num_rows
 * Paramètre :   pointeur sur une colonne
 * Sortie : entier
 * Fonctionnement : obtenir le nombre de lignes d'une colonne
 */
int get_num_rows(COLUMN2 *column) {
    if (column == NULL) {   // vérifier que la colonne est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 0;
    }
    return column -> size;   // retourner la taille
}


/**
 * Nom : print_num_rows2
 * Paramètre : pointeur sur une structure
 * Sortie : /
 * Fonctionnement : afficher le nombre de lignes
 */
void print_num_rows2(DATAFRAME2 *dataframe) {
    if (dataframe == NULL) {   // vérifier si le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    int num_rows = 0;
    for (int i = 0; i < dataframe -> num_columns; ++i) num_rows = (get_num_rows(dataframe -> columns[i]) > num_rows) ? get_num_rows(dataframe->columns[i]) : num_rows;   // avoir le nombre de lignes
    printf("Nombre de lignes du CDataframe : %llu\n", num_rows);
}


/**
 * Nom : print_num_columns2
 * Paramètre : pointeur vers une structure
 * Sortie : /
 * Fonctionnement : afficher le nombre de colonnes
 */
void print_num_columns2(DATAFRAME2 *dataframe) {
    if (dataframe == NULL) {   // vérifier si le cdataframe est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("Nombre de colonnes du CDataframe : %u\n", dataframe -> num_columns);   // afficher le nombre de colonnes
}





/**==========FONCTION DE TEST DU CDATAFRAME AVANCE==========*/
int test_advanced_cdataframe() {
    // Créer un CDataframe vide
    DATAFRAME2 *dataframe = create_dataframe2();   // créer un cdataframe vide
    if (dataframe == NULL) {   // vérifier si l'allocation mémoire a marché
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    else printf("Test de la creation de notre CDataframe reussi !\n");
    printf("\n");

    // Remplir le CDataframe en dur
    fill_dataframe_hardcoded(dataframe);
    printf("Test du remplissage en dur de notre CDataframe reussi !\n");
    printf("\n");

    // Afficher le contenu complet du CDataframe
    printf("Test de l'affichage complet de notre CDataframe :\n");
    print_dataframe2(dataframe);
    printf("\n");

    // Test de l'ajout d'une ligne de valeurs
    printf("Test de l'ajout d'une ligne de valeurs au CDataframe :\n");
    void *values[] = {&(int){4}, &(float){0.77}, "Medvedev"};
    add_row2(dataframe, values);
    print_dataframe2(dataframe);
    printf("\n");

    // Test de la suppression d'une ligne de valeurs
    printf("Test de suppression d'une ligne du CDataframe (ici la seconde) :\n");
    delete_row(dataframe, 1); // Suppression de la deuxième ligne (index 1)
    print_dataframe2(dataframe);
    printf("\n");

    // Test de l'ajout d'une colonne
    printf("Test de l'ajout d'une colonne de valeurs au CDataframe :\n");
    add_column2(dataframe, CHAR, "Initiale");
    insert_value2(dataframe -> columns[3], "N");   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[3], "C");   // ajouter une valeur à la colonne
    insert_value2(dataframe -> columns[3], "D");   // ajouter une valeur à la colonne
    print_dataframe2(dataframe);
    printf("\n");

    // Test de la suppression d'une colonne
    printf("Test de suppression d'une colonne du CDataframe (ici la seconde) :\n");
    delete_column3(dataframe, 1); // Suppression de la deuxième colonne (index 1)
    print_dataframe2(dataframe);
    printf("\n");

    // Test du renommage d'une colonne
    printf("Test de renommage d'une colonne du CDataframe (ici 'Classement' -> 'Numero') :\n");
    rename_column2(dataframe, 0, "Numero");
    print_dataframe2(dataframe);
    printf("\n");

    // Tester la recherche d'une valeur dans le CDataframe
    printf("Test de la recherche d'une valeur dans le CDataframe (ici 4) :\n");
    int four = 4;
    int* ptr = &four;
    int column_index = search_value2(dataframe, ptr);
    if (column_index != -1) printf("Youpi, 4 a ete trouve dans la colonne %d\n", column_index);
    else printf("Zut, 4 n'a pas été trouvée dans le CDataframe\n");
    printf("\n");

    // Test de l'affichage des noms des colonnes
    printf("Test de l'affichage des noms des colonnes du CDataframe :\n");
    print_column_names2(dataframe);
    printf("\n");

    // Test de l'affichage partiel des lignes
    printf("Test de l'affichage partiel des lignes du CDataframe :\n");
    print_partial_rows2(dataframe, 0, 1);
    printf("\n");

    // Test de l'affichage partiel des colonnes
    printf("Test de l'affichage partiel des colonnes du CDataframe :\n");
    print_partial_columns2(dataframe, 0, 1);
    printf("\n");

    // Test des statistiques
    printf("Test des fonctionnalites statistiques :\n");
    print_num_rows2(dataframe);
    print_num_columns2(dataframe);

    // Libérer la mémoire allouée pour le CDataframe
    delete_dataframe(&dataframe);

    return 0;
}