/**
 * Fichier : column.c
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "column.h"   // inclure le fichier d'en-tête associé


/**==========FONCTIONS GENERALES DES COLONNES==========*/
/**
 * Nom : create_column
 * Paramètre : tableau de caractères représentant le titre de la colonne
 * Sortie : pointeur sur la structure colonne créée
 * Fonctionnement : créer une colonne en allouant de l'espace mémoire et en initialisant les éléments de la structure
 */
COLUMN *create_column(char* title) {
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));   // allouer dynamiquement de l'espace mémoire pour le type COLUMN
    if (col == NULL) printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");   // vérifier si le pointeur retourné par malloc n'est pas égal à NULL (car espace insuffisant)
    int len = strlen(title) + 1;
    col -> Title = (char*) malloc((len) * sizeof(char));   // allouer dynamiquement de l'espace mémoire pour le titre passé en paramètre
    if (col -> Title == NULL) printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");   // vérifier si le pointeur retourné par malloc n'est pas égal à NULL (car espace insuffisant)
    strcpy(col -> Title, title);   // copier le titre passé en paramètre dans le nom de notre colonne
    col -> logical_size = 0;
    col -> physical_size = 0;
    col -> Datas = NULL;
    return col;   // retourner un pointeur sur la structure
}


/**
 * Nom : insert_value
 * Paramètre : entier représentant une valeur, pointeur sur une colonne
 * Sortie : entier pour la gestion d'erreurs
 * Fonctionnement : insérer une valeur dans la colonne passée en paramètre
 */
int insert_value(COLUMN* col, int val) {
    if (col == NULL) {   // vérifier que le pointeur sur la colonne n'est pas égal à NULL (sinon il y a eu une erreur lors de l'allocation mémoire de la structure)
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 0;
    }
    if (col -> physical_size == 0) {   // vérifier si la taille physique est égale à 0 (la colonne n'a pas encore été initialisée)
        col -> Datas = (int*) malloc(REALOC_SIZE * sizeof(int));   // allouer dynamiquement de l'espace pour le tableau de données avec la constante d'allocation
        if (col -> Datas == NULL) {   // vérifier si l'allocation a échoué
            printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
            return 0;
        }
        col -> physical_size = REALOC_SIZE;   // mettre la taille physique à la valeur de la constante d'allocation
    }
    if (col -> logical_size == col -> physical_size) {   // vérifier si la taille logique = la taille physique (l'espace est épuisé)
        int *new = (int*) realloc(col -> Datas, (col -> physical_size + REALOC_SIZE) * sizeof(int));   // réallouer l'espace pour les données avec une taille supplémentaire de la constante d'allocation
        if (new == NULL) {   // vérifier si la ré-allocation a réussi
            printf("ERREUR 2 (voir index des erreurs sur GitHub)\n");
            return 0;
        }
        col -> Datas = new;   // faire une maj du pointeur des données avec le nouveau pointeur
        col -> physical_size += REALOC_SIZE;   // incrémenter la taille physique de la colonne avec la constante d'allocation
    }
    col -> Datas[col -> logical_size] = val;   // mettre la valeur dans la colonne à l'indice de taille logique
    col -> logical_size++;   // incrémenter la taille logique
    return 1;   // retourner 1 si tout s'est bien passé
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
    if (col == NULL) {   // vérifier si la colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (col -> logical_size == 0) {   // vérifier si la colonne est vide
        printf("Oh zut, la colonne est vide !\n");
        return;
    }
    for (int i = 0; i < col -> logical_size; i++) printf("[%d] :   %d\n", i, col -> Datas[i]);   // arcourir chaque élément de la colonne et afficher la valeur à côté de son indice
}


/**
 * Nom : occurrences
 * Paramètre : pointeur vers une structure, entier à rechercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne et compter le nb d'occurrences de l'entier en paramètre
 */
int occurrences(COLUMN* col, int x) {
    int cpt = 0;
    if (col == NULL) {   // vérifier si la colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < col -> logical_size; i++) if (col -> Datas[i] == x) cpt++;   // parcourir le tableau de valeur et compter le nombre d'occurrences
    return cpt;   // retourner le compteur
}


/**
 * Nom : value_at_position
 * Paramètre : pointeur vers une structure, entier représentant un indice
 * Sortie : entier associé à l'indice passé en paramètre
 * Fonctionnement : parcourir une colonne pour trouver la valeur associée à une certaine position
 */
int value_at_position(COLUMN* col, int pos) {
    if (col == NULL) {   // vérifier si la colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    if (pos < 0 || pos >= col -> logical_size) {   // vérifier que la position existe
        printf("ERREUR 3 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    int val = col -> Datas[pos];
    return val;   // retourner la valeur à la position passée en paramètre du tableau de valeurs
}


/**
 * Nom : number_of_little_values
 * Paramètre : pointeur vers une structure, entier à chercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne pour trouver le nombre de valeurs inférieures
 */
int number_of_little_values(COLUMN* col, int x) {
    int cpt = 0;
    if (col == NULL) {   // vérifier si la colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < col -> logical_size; i++) if (col -> Datas[i] < x) cpt++;   // parcourir le tableau de valeur et compter le nombre de valeurs inférieures
    return cpt;   // retourner le compteur
}


/**
 * Nom : number_of_big_values
 * Paramètre : pointeur vers une structure, entier à chercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne pour trouver le nombre de valeurs supérieures
 */
int number_of_big_values(COLUMN* col, int x) {
    int cpt = 0;
    if (col == NULL) {   // vérifier si la colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < col -> logical_size; i++) if (col -> Datas[i] > x) cpt++;   // parcourir le tableau de valeur et compter le nombre de valeurs supérieures
    return cpt;   // retourner le compteur
}


/**
 * Nom : number_of_little_values
 * Paramètre : pointeur vers une structure, entier à chercher
 * Sortie : entier représentant un compteur
 * Fonctionnement : parcourir une colonne pour trouver le nombre de valeurs égales
 */
int number_of_equal_values(COLUMN* col, int x) {
    int cpt = 0;
    if (col == NULL) {   // vérifier si la colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 1;
    }
    for (int i = 0; i < col -> logical_size; i++) if (col -> Datas[i] == x) cpt++;   // parcourir le tableau de valeur et compter le nombre de valeurs égales
    return cpt;   // retourner le compteur
}





/**==========FONCTIONS AVANCEES DES COLONNES==========*/
/**
 * Nom : compare_asc
 * Paramètre : deux pointeurs constants vers void représentant les éléments à comparer
 * Sortie : un entier représentant la comparaison (négatif si a < b, positif si a > b, 0 si a == b)
 * Fonctionnement : comparer deux entiers en ordre ascendant
 */
int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);   // convertir les pointeurs void en pointeurs vers int et soustraire les valeurs pointées
}


/**
 * Nom : compare_desc
 * Paramètre : deux pointeurs constants vers void représentant les éléments à comparer
 * Sortie : un entier représentant la comparaison (négatif si a > b, positif si a < b, 0 si a == b)
 * Fonctionnement : comparer deux entiers en ordre descendant
 */
int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);   // convertir les pointeurs void en pointeurs vers int et soustraire les valeurs pointées dans l'ordre inverse
}


/**
 * Nom : sort_column
 * Paramètre : pointeur vers une structure, entier représentant le sens du tri (0 pour ascendant, 1 pour descendant)
 * Sortie : /
 * Fonctionnement : trier la colonne en place selon l'ordre spécifié
 */
void sort_column(COLUMN *col, int order) {
    if (col == NULL) {   // vérifier que notre colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (col -> logical_size == 0) {   // vérifier que notre colonne n'est pas vide
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }
    if (order == ASC) qsort(col -> Datas, col -> logical_size, sizeof(int), compare_asc);   // utiliser qsort pour trier la colonne
    else if (order == DESC) qsort(col -> Datas, col -> logical_size, sizeof(int), compare_desc);   // utiliser qsort pour trier la colonne
    else {
        printf("ERREUR 4 (voir index des erreurs sur GitHub)\n");   // erreur pour ordre de tri invalide
        return;
    }
    col -> valid_index = 1;   // marquer la colonne comme triée
    col -> sort_dir = order;   // mettre à jour le sens du tri
}


/**
 * Nom : binary_search
 * Paramètre : pointeur vers une structure, entier représentant la valeur à rechercher
 * Sortie : entier représentant l'indice de la valeur trouvée ou -1 si la valeur n'est pas trouvée
 * Fonctionnement : effectuer une recherche dichotomique pour trouver la valeur dans une colonne triée
 */
int binary_search(COLUMN *col, int value) {
    if (col == NULL) {   // vérifier que notre colonne est exploitable
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return -1;
    }
    if (col -> logical_size == 0) {   // vérifier que notre colonne n'est pas vide
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return -1;
    }
    if (col -> valid_index != 1) {   // vérifier que la colonne est triée
        printf("ERREUR 8 (voir index des erreurs sur GitHub)\n");
        return -1;
    }
    int left = 0;   // initialiser la borne gauche à 0
    int right = col -> logical_size - 1;   // initialiser la borne droite à la dernière position du tableau
    while (left <= right) {    // Effectuer tant que la borne gauche est inférieure ou égale à la borne droite
        int middle = left + (right - left) / 2;   // calculer la position du milieu pour éviter l'overflow
        if (col -> Datas[middle] == value) {
            return middle;   // retourner la valeur trouvée
        }
        if (col -> Datas[middle] < value) {
            if (col -> sort_dir == ASC) left = middle + 1;
            else right = middle - 1;
        } else {
            if (col->sort_dir == ASC) right = middle - 1;
            else left = middle + 1;
        }
    }
    return -1;
}





/**==========FONCTION DE TEST DES COLONNES==========*/
int test_column() {
    // Créer notre colonne
    COLUMN *col = create_column("Colonne 1");
    if (col != NULL) printf("Test de la creation de notre colonne reussi !\n");
    printf("\n");

    // Insérer des valeurs dans notre colonne
    insert_value(col, 52);
    insert_value(col, 44);
    insert_value(col, 15);
    insert_value(col, 52);
    printf("Test de l'insertion de 4 valeurs dans notre colonne :\n");
    print_col(col);
    printf("\n");

    // Trouver le nombre d'occurrences d'une valeur dans notre colonne
    printf("Test du nombre d'occurrences d'une valeur dans notre colonne (ici 52) :\n");
    int count = occurrences(col, 52);
    printf("Le nombre d'occurrences de %d dans la colonne est : %d\n", 52, count);
    printf("\n");

    // Trouver la valeur à une certaine position
    printf("Test de la valeur a une certaine position (ici 2) :\n");
    int value = value_at_position(col, 2);
    printf("La valeur a la position %d est : %d\n", 2, value);
    printf("\n");

    // Trouver le rapport entre les val
    int cpt = 0;
    printf("Test des valeurs inferieures a une certaine valeur (ici 40) :\n");
    cpt = number_of_little_values(col, 40);
    printf("Il y a %d valeurs inferieures a %d\n", cpt, 40);
    printf("\n");
    printf("Test des valeurs superieures a une certaine valeur (ici 10) :\n");
    cpt = number_of_big_values(col, 10);
    printf("Il y a %d valeurs superieures a %d\n", cpt, 10);
    printf("\n");
    printf("Test des valeurs egales a une certaine valeur (ici 15) :\n");
    cpt = number_of_equal_values(col, 15);
    printf("Il y a %d valeurs egales a %d\n", cpt, 15);
    printf("\n");

    // Créer une nouvelle colonne
    COLUMN *coln = create_column("Colonne 2");
    insert_value(coln, 5);
    insert_value(coln, 3);
    insert_value(coln, 8);
    insert_value(coln, 1);

    printf("Test des tris de la colonne :\n");
    printf("Colonne avant le tri :\n");
    print_col(coln);

    // Trier dans l'ordre
    sort_column(coln, ASC);

    printf("Colonne apres le tri (ascendant) :\n");
    print_col(coln);

    // Trier dans l'ordre descendant
    sort_column(coln, DESC);

    printf("Colonne apres le tri (descendant) :\n");
    print_col(coln);
    printf("\n");

    // Rechercher dichotomiquement
    printf("Test des recherches par dichotomie :\n");
    int val = 3;
    int index = binary_search(coln, val);
    if (index != -1) printf("Valeur %d trouvee a l'indice %d\n", val, index);
    else printf("Valeur %d non trouvee\n", val);
    printf("\n");

    // Supprimer la colonne
    delete_column(&coln);
    printf("Test de la suppression de laa colonne reussi !\n");

    return 0;
}