/**
 * Fichier : cdataframe.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "cdataframe.h"   // inclure le fichier d'en-tête associé


/**==========FONCTIONS DU CDATAFRAME==========*/
/**
 * Nom : create_dataframe
 * Paramètre : /
 * Sortie : pointeur vers une structure ccdataframe
 * Fonctionnement : créer une structure cdataframe, lui allouer de l'espace et initialiser
 */
CDATAFRAME* create_dataframe() {
    CDATAFRAME* dataframe = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));   // allouer dynamiquement de l'espace sur la structure cdataframe
    if (dataframe == NULL) {   // vérifier que le malloc s'est bien passé
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return NULL;
    }
    dataframe -> number_col = 0;
    dataframe -> number_row = 0;
    return dataframe;   // retourner un pointeur vers la structure créée
}


/**
 * Nom : fill_dataframe_by_input
 * Paramètre : pointeur vers une structure cdataframe
 * Sortie : /
 * Fonctionnement : remplir le cdataframe par saisies utilisateur
 */
void fill_dataframe_by_input(CDATAFRAME* dataframe) {
    printf("Nombre de colonnes : ");
    scanf("%d", &dataframe -> number_col);
    printf("Nombre de lignes : ");
    scanf("%d", &dataframe -> number_row);
    for (int i = 0; i < dataframe -> number_row; i++) {   // parcourir les lignes du cdataframe
        char title[50];   // créer une chaîne de 50 caractères
        printf("Titre pour la colonne [%d]: ", i + 1);
        scanf("%s", title);
        COLUMN* col = create_column(title);   // créer la colonne avec notre fonction de column.h
        dataframe -> columns[i] = col;   // ajouter la colonne au cdataframe
    }
    for (int i = 0; i < dataframe->number_col; i++) {   // parcourir les colonnes
        printf("Entrez les valeur pour la colonne %s:\n", dataframe -> columns[i] -> Title);
        for (int j = 0; j < dataframe -> number_row; j++) {   // parcourir les lignes
            printf("Ligne [%d] : ", j + 1);
            int val;
            scanf("%d", &val);
            insert_value(dataframe -> columns[i], val);   // insérer la valeur
        }
    }
}


/**
 * Nom : fill_dataframe
 * Paramètre : /
 * Sortie : pointeur vers une structure cdataframe
 * Fonctionnement : remplir le cdataframe en dur
 */
void fill_dataframe(CDATAFRAME* dataframe) {
    dataframe -> number_col = 3;   // initialiser le nombre de colonnes à 3
    dataframe -> number_row = 3;   // initialiser le nombre de lignes à 3

    COLUMN* col1 = create_column("Col1");   // créer une première colonne
    insert_value(col1, 1);
    insert_value(col1, 2);
    insert_value(col1, 3);
    dataframe -> columns[0] = col1;   // mettre la colonne dans le cdataframe

    COLUMN* col2 = create_column("Col2");   // créer une seconde colonne
    insert_value(col2, 4);
    insert_value(col2, 5);
    insert_value(col2, 6);
    dataframe -> columns[1] = col2;   // mettre la colonne dans le cdataframe

    COLUMN* col3 = create_column("Col3");   // créer une troisième colonne
    insert_value(col3, 7);
    insert_value(col3, 8);
    insert_value(col3, 9);
    dataframe -> columns[2] = col3;   // mettre la colonne dans le cdataframe
}


/**
 * Nom : print_dataframe
 * Paramètre : pointeur vers une structure cdataframe
 * Sortie : /
 * Fonctionnement : afficher l'entièreté du cdataframe
 */
void print_dataframe(CDATAFRAME* dataframe) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("--------------------\n");
    for (int i = 0; i < dataframe -> number_col; i++) printf("%s\t", dataframe -> columns[i] -> Title);   // parcourir les colonnes et afficher les titres
    printf("\n");
    printf("--------------------\n");
    for (int i = 0; i < dataframe -> number_row; i++) {   // parcourir les lignes
        for (int j = 0; j < dataframe -> number_col; j++) printf("%d\t", dataframe -> columns[j] -> Datas[i]);   // parcourir les lignes et afficher les valeurs
        printf("\n");
    }
    printf("--------------------\n");
}


/**
 * Nom : print_somme_rows
 * Paramètre : pointeur vers une structure cdataframe, valeur entière
 * Sortie : /
 * Fonctionnement :  afficher une partie des ligness du CDataframe selon une valeur limite
 */
void print_somme_rows(CDATAFRAME* dataframe, int val) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("--------------------\n");
    for (int i = 0; i < dataframe -> number_col; i++) printf("%s\t", dataframe -> columns[i] -> Title);   // afficher les titres des colonnes associées aux lignes
    printf("\n");
    printf("--------------------\n");
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < dataframe -> number_col; j++) printf("%d\t", dataframe -> columns[j] -> Datas[i]);   // afficher les valeurs
        printf("\n");
    }
    printf("--------------------\n");
}


/**
 * Nom : print_somme_columns
 * Paramètre : pointeur vers une structure cdataframe, valeur entière
 * Sortie : /
 * Fonctionnement : afficher une partie des colonnes du CDataframe selon une valeur limite
 */
void print_somme_columns(CDATAFRAME* dataframe, int val) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("--------------------\n");
    for (int i = 0; i < val; i++) printf("%s\t", dataframe -> columns[i] -> Title);   // afficher les titres des colonnes
    printf("\n");
    printf("--------------------\n");
    for (int i = 0; i < dataframe -> number_row; i++) {   // parcourir les colonnes du cdataframe
        for (int j = 0; j < val; j++) printf("%d\t", dataframe -> columns[j] -> Datas[i]);   // afficher les valeurs
        printf("\n");
    }
    printf("--------------------\n");
}


/**
 * Nom : add_row
 * Paramètre : pointeur vers une structure cdataframe, pointeur vers une valeur
 * Sortie : /
 * Fonctionnement : ajouter une ligne à la fin du cdataframe
 */
void add_row(CDATAFRAME* dataframe, int* val) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (dataframe -> number_row >= ROW_MAX) {   // vérifier si notre cdataframe n'a pas déjà atteint son nombre de lignes maaximum
        printf("ERREUR 5 (voir index des erreurs sur GitHub)\n");
        return;
    }
    for (int i = 0; i < dataframe -> number_col; i++) insert_value(dataframe -> columns[i], val[i]);   // utiliser notre fonction insert_value de column.h pour rajouter une nouvelle valeur à la fin de chaque colonne
    dataframe -> number_row++;   // incrémenter le nombre de lignes par 1
}


/**
 * Nom : remove_row
 * Paramètre : pointeur vers une structure cdataframe, index entier
 * Sortie : /
 * Fonctionnement : supprimer une ligne du cdataframe avec son index
 */
void remove_row(CDATAFRAME* dataframe, int index) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (index < 0 || index >= dataframe -> number_row) {   // parcourir les lignes de notre cdataframe
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    for (int i = 0; i < dataframe -> number_col; i++) for (int j = index; j < dataframe -> number_row - 1; j++) dataframe -> columns[i] -> Datas[j] = dataframe -> columns[i] -> Datas[j + 1];      // décaler toutes les valeurs vers le haut à partir de l'index
    dataframe -> number_row--;   // décrémenter le nombre de lignes de 1
}


/**
 * Nom : add_column
 * Paramètre : pointeur vers une structure cdataframe, chaîne de caractères du titre
 * Sortie : /
 * Fonctionnement : ajouter une colonne à la fin du cdataframe
 */
void add_column(CDATAFRAME* dataframe, char* title) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (dataframe -> number_col >= COL_MAX) {   // vérifier si notre cdataframe n'a pas déjà atteint son nombre de colonnes maaximum
        printf("ERREUR 6 (voir index des erreurs sur GitHub)\n");
        return;
    }
    COLUMN* col = create_column(title);   // créer une nouvelle colonne avec notre fonction de column.h
    int pos = dataframe -> number_col;
    dataframe -> columns[pos] = col;   // ajouter la colonne créée à notre cdataframa
    dataframe -> number_col++;   // incrémenter le nombre de colonnes par 1
}


/**
 * Nom : remove_column
 * Paramètre : pointeur vers une structure cdataframe, index entier
 * Sortie : /
 * Fonctionnement : accéder à une colonne avec son index et la supprimer
 */
void remove_column(CDATAFRAME* dataframe, int index) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (index < 0 || index >= dataframe -> number_col) {   // parcourir les colones du cdataframe
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    delete_column(&(dataframe -> columns[index]));   // supprimer la colonne grâcee à notre fonction dans column.h
    for (int i = index; i < dataframe -> number_col - 1; i++) dataframe -> columns[i] = dataframe -> columns[i + 1];   // décaler toutes les colonnes vers le haut à partir de l'index
    dataframe -> number_col--;   // décrémenter le nombre de colonnes de 1
}


/**
 * Nom : rename_column
 * Paramètre : pointeur vers une structure cdataframe, index entier, chaîne de caractères du noueau titre
 * Sortie : /
 * Fonctionnement : accéder à la colonne avec l'index et changer son nom
 */
void rename_column(CDATAFRAME* dataframe, int index, char* title2) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (index < 0 || index >= dataframe -> number_col) {   // parcourir les colones du cdataframe
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    free(dataframe -> columns[index] -> Title);   // libérer l'espace alloué au tritre original
    strcpy(dataframe -> columns[index] -> Title, title2);   // utiliser la fonction strcpy pour copier le nouveau titre à la place du premier
}


/**
 * Nom : search_value
 * Paramètre : pointeur vers une structure cdataframe, valeur entière
 * Sortie : entier bolléen de recherche
 * Fonctionnement : parcourir lee cdataframe et vérifier l’existence d’une valeur
 */
int search_value(CDATAFRAME* dataframe, int val) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    int bool = 0;   // initialiser la variable de recherche à 0 (valeur non trouvée)
    for (int i = 0; i < dataframe -> number_col; i++) for (int j = 0; j < dataframe -> number_row; j++) if (dataframe -> columns[i] -> Datas[j] == val) bool = 1;   // parcourir les colonnes, puis les valeurs des lignes et comparer avec la valeur cherchée
    return bool;   // retourner la variable de recherche
}


/**
 * Nom : get_value
 * Paramètre : pointeur vers une structure cdataframe, valeur entière, entier colonnes, entier lignes
 * Sortie : valeur entière
 * Fonctionnement : parcourir le cdataframe pour accéder à la valeur se trouvant dans une cellule du cdataframe en utilisant son numéro de ligne et de colonne
 */
int get_value(CDATAFRAME* dataframe, int row, int col) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    if (row < 0 || row >= dataframe -> number_row || col < 0 || col >= dataframe -> number_col) {   // vérifier que la ligne et la colonne fournis sont valides
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    int val = dataframe -> columns[col] -> Datas[row];   // initialiser la valeur
    return val;   // retourner la valeur obtenue
}


/**
 * Nom : set_value
 * Paramètre : pointeur vers une structure cdataframe, valeur entière, entier colonnes, entier lignes
 * Sortie : /
 * Fonctionnement : parcourir le cdataframe remplacer la valeur se trouvant dans une cellule du cdataframe en utilisant son numéro de ligne et de colonne
 */
void set_value(CDATAFRAME* dataframe, int row, int col, int val) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (row < 0 || row >= dataframe -> number_row || col < 0 || col >= dataframe -> number_col) {   // vérifier que la ligne et la colonne fournies sont valides
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return;
    }
    dataframe -> columns[col] -> Datas[row] = val;   // accéder à la valeur pointée et la remplacer par notre valeur de remplacement
}


/**
 * Nom : print_column_names
 * Paramètre : pointeur vers une structure cdataframe
 * Sortie : /
 * Fonctionnement : parcourir les colonnes et afficher leurs titres
 */
void print_column_names(CDATAFRAME* dataframe) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return;
    }
    printf("Les titres des colonnes de notre CDataframe sont : \n");
    for (int i = 0; i < dataframe -> number_col; i++) printf("%s\t", dataframe -> columns[i] -> Title);   // parcourir les colonnes du cdataframe et afficher les titres
    printf("\n");
}


/**
 * Nom : count_rows
 * Paramètre : pointeur vers une structure cdataframe
 * Sortie : compteur entier
 * Fonctionnement : compter puis afficher le nombre de lignes
 */
int count_rows(CDATAFRAME* dataframe) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    int cpt = dataframe -> number_row;   // initialiser le compteur à partir de l'attribut du nombre de lignes de la structure
    return cpt;   // retourner le nombre de lignes du cdataframe
}


/**
 * Nom : count_columns
 * Paramètre : pointeur vers une structure cdataframe
 * Sortie : compteur entier
 * Fonctionnement : compter puis afficher le nombre de colonnes
 */
int count_columns(CDATAFRAME* dataframe) {
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    int cpt = dataframe -> number_col;   // initialiser le compteur à partir de l'attribut du nombre de colonnes de la structure
    return cpt;   // retourner le nombre de colonnes du cdataframe
}


/**
 * Nom : count_cells_equal
 * Paramètre : pointeur vers une structure cdataframe, valeur entière
 * Sortie : compteur entier
 * Fonctionnement : retourner le nombre de cellules qui ont des valeurs égales à x (x donné en paramètre)
 */
int count_cells_equal(CDATAFRAME* dataframe, int val) {
    int cpt = 0;  // initialiser le compteur à 0
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < dataframe -> number_col; i++) for (int j = 0; j < dataframe -> number_row; j++) if (dataframe -> columns[i] -> Datas[j] == val) cpt++;   // parcourir les colonnes, puis les valeurs des lignes et comparer avec la valeur cherchée
    return cpt;   // retourner le compteur
}


/**
 * Nom : count_cells_sup
 * Paramètre : pointeur vers une structure cdataframe, valeur entière
 * Sortie : compteur entier
 * Fonctionnement : retourner le nombre de cellules qui ont des valeurs supérieures à x (x donné en paramètre)
 */
int count_cells_sup(CDATAFRAME* dataframe, int val) {
    int cpt = 0;  // initialiser le compteur à 0
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < dataframe -> number_col; i++) for (int j = 0; j < dataframe -> number_row; j++) if (dataframe -> columns[i] -> Datas[j] > val) cpt++;   // parcourir les colonnes, puis les valeurs des lignes et comparer avec la valeur cherchée
    return cpt;   // retourner le compteur
}


/**
 * Nom : count_cells_inf
 * Paramètre : pointeur vers une structure cdataframe, valeur entière
 * Sortie : compteur entier
 * Fonctionnement : retourner le nombre de cellules qui ont des valeurs inférieures à x (x donné en paramètre)
 */
int count_cells_inf(CDATAFRAME* dataframe, int val) {
    int cpt = 0;   // initialiser le compteur à 0
    if (dataframe == NULL) {   // vérifier que la structure est exploitable
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < dataframe -> number_col; i++) for (int j = 0; j < dataframe -> number_row; j++) if (dataframe -> columns[i] -> Datas[j] < val) cpt++;   // parcourir les colonnes, puis les valeurs des lignes et comparer avec la valeur cherchée
    return cpt;   // retourner le compteur
}





/**==========FONCTION DE TEST DU CDATAFRAME==========*/
int test_cdataframe() {
    // Créer notre CDataframe
    CDATAFRAME* dataframe = create_dataframe();
    if (dataframe != NULL) printf("Test de la creation de notre CDataframe reussi !\n");
    printf("\n");

    // Remplir le CDataframe en dur
    fill_dataframe(dataframe);
    printf("Test du remplissage en dur de notre CDataframe reussi !\n");
    printf("\n");

    // Afficher des noms des colonnes
    printf("Test de l'affichage des noms de colonnes :\n");
    print_column_names(dataframe);
    printf("\n");

    // Afficher le CDataframe complet
    printf("Test de l'affichage complet de notre CDataframe :\n");
    print_dataframe(dataframe);
    printf("\n");

    printf("Test du comptage des cellules (ici avec la valeur 4) :\n");
    printf("Nombre de cellules contenant la valeur %d : %d\n", 4, count_cells_equal(dataframe, 4));
    printf("Nombre de cellules contenant une valeur superieure a %d : %d\n", 4, count_cells_sup(dataframe, 4));
    printf("Nombre de cellules contenant une valeur inferieure a %d : %d\n", 4, count_cells_inf(dataframe, 4));
    printf("\n");

    // Tester la recherche de valeur
    printf("Test de la recherche d'une valeur dans le CDataframe :\n");
    if (search_value(dataframe, 4)) printf("Youpi, la valeur %d est bien dans le CDataframe !\n", 4);
    else printf("Oh zut, la valeur %d n'est pas dans le CDataframe.\n", 4);
    printf("\n");

    // Tester l'accès à une valeur
    printf("Test de l'acces a une valeur dans le CDataframe :\n");
    printf("Valeur a l'index (%d, %d) : %d\n", 1, 1, get_value(dataframe, 1, 1));
    printf("\n");

    // Tester la modification d'une valeur
    set_value(dataframe, 1, 1, 99);
    printf("Test de la modification d'une valeur dans le CDataframe (ici on va remplacer 5 par 99) :\n");
    print_dataframe(dataframe);
    printf("\n");

    // Afficher un certain nombre de lignes
    printf("Test de l'affichage d'un certain nombre de lignes du CDataframe (ici 2) :\n");
    print_somme_rows(dataframe, 2);
    printf("\n");

    // Afficher un certain nombre de colonnes
    printf("Test de l'affichage d'un certain nombre de colonnes du CDataframe (ici 2) :\n");
    print_somme_columns(dataframe, 2);
    printf("\n");

    // Ajouter une nouvelle ligne au CDataframe
    int new_row_values[] = {10, 20, 30}; // Les valeurs de la nouvelle ligne
    add_row(dataframe, new_row_values);
    printf("Test de l'ajout d'une nouvelle ligne au CDataframe :\n");
    print_dataframe(dataframe);
    printf("\n");

    // Supprimer une ligne du CDataframe
    remove_row(dataframe, 1);
    printf("Test de la suppression d'une ligne au CDataframe (ici la seconde ligne) :\n");
    print_dataframe(dataframe);
    printf("\n");

    // Ajouter une nouvelle colonne au CDataframe
    add_column(dataframe, "Col4");
    printf("Test de l'ajout d'une nouvelle colonne au CDataframe :\n");
    print_column_names(dataframe);
    printf("\n");

    // Supprimer une colonne du CDataframe
    remove_column(dataframe, 1);
    printf("Test de la suppression d'une colonne au CDataframe (ici la seconde colonne) :\n");
    print_column_names(dataframe);
    printf("\n");

    // Renommer de la première colonne
    rename_column(dataframe, 2, "New");
    printf("Test du renommage d'une colonne au CDataframe :\n");
    print_column_names(dataframe);
    printf("\n");

    // Afficher le nombre de lignes
    printf("Test du comptage de nombre de lignes du CDataframe :\n");
    printf("Nombre de lignes dans le CDataframe : %d\n", count_rows(dataframe));
    printf("\n");
    // Afficher le nombre de colonnes
    printf("Test du comptage de nombre de colonnes du CDataframe :\n");
    printf("Nombre de colonnes dans le CDataframe : %d\n", count_columns(dataframe));
    printf("\n");

    return 0;
}