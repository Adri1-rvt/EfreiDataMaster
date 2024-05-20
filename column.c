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
 * Function: partition
 * Purpose: Partitioner for quicksort
 */
int partition(int Tab[], int left, int right, long* index) {
    int pivot = Tab[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (Tab[j] <= pivot) {
            i++;
            int tmp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = tmp;

            long tmp_idx = index[i];
            index[i] = index[j];
            index[j] = tmp_idx;
        }
    }
    int tmp = Tab[i + 1];
    Tab[i + 1] = Tab[right];
    Tab[right] = tmp;

    long tmp_idx = index[i + 1];
    index[i + 1] = index[right];
    index[right] = tmp_idx;

    return (i + 1);
}

/**
 * Function: quicksort
 * Purpose: Quick sort algorithm
 */
void quicksort(int Tab[], int left, int right, long* index) {
    if (left < right) {
        int pi = partition(Tab, left, right, index);
        quicksort(Tab, left, pi - 1, index);
        quicksort(Tab, pi + 1, right, index);
    }
}

/**
 * Function: insertion
 * Purpose: Insertion sort algorithm
 */
void insertion(int Tab[], int n, long* index) {
    for (int i = 1; i < n; i++) {
        int k = Tab[i];
        long idx = index[i];
        int j = i - 1;

        while (j >= 0 && Tab[j] > k) {
            Tab[j + 1] = Tab[j];
            index[j + 1] = index[j];
            j--;
        }
        Tab[j + 1] = k;
        index[j + 1] = idx;
    }
}


/**
 * Function: sort
 * Purpose: Sort a column according to a given order
 */
void sort(COLUMN* col, int sort_dir) {
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }

    if (col->logical_size <= 1) {
        printf("La colonne est déjà triée.\n");
        return;
    }

    if (col->valid_index == 1 && col->sort_dir == sort_dir) {
        printf("La colonne est déjà triée dans cet ordre.\n");
        return;
    }

    if (col->valid_index == -1) {
        printf("La colonne est partiellement triée. Réindexation nécessaire.\n");
        // Réindexation nécessaire ici si vous décidez de réindexer la colonne après un tri partiel
    }

    // Allouer et initialiser le tableau d'index
    if (col->index == NULL) {
        col->index = (long*)malloc(col->logical_size * sizeof(long));
    }
    for (int i = 0; i < col->logical_size; i++) {
        col->index[i] = i;
    }

    // Tri du tableau de données
    if (col->valid_index == 0) {
        quicksort(col->Datas, 0, col->logical_size - 1, col->index);   // utiliser le tri rapide (Quicksort)
    } else if (col->valid_index == -1) {
        insertion(col->Datas, col->logical_size, col->index);   // utiliser le tri par insertion
    }

    // Mise à jour de valid_index et sort_dir
    col->valid_index = 1;
    col->sort_dir = sort_dir;
}


/**
 * Function: print_col_by_index
 * Purpose: Display the content of a sorted column
 */
void print_col_by_index(COLUMN* col) {
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }

    if (col->valid_index != 1) {
        printf("ERREUR : La colonne n'est pas triée ou l'index est invalide.\n");
        return;
    }

    printf("Contenu de la colonne \"%s\" après le tri :\n", col->Title);

    for (int i = 0; i < col->logical_size; i++) {
        printf("[%d] %d\n", i, col->Datas[col->index[i]]);
    }
}

/**
 * Function: erase_index
 * Purpose: Remove the index of a column
 */
void erase_index(COLUMN* col) {
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return;
    }

    if (col->valid_index != 0) {
        free(col->index);   // libérer la mémoire du tableau des index
        col->index = NULL;    // mettre le pointeur à NULL
        col->valid_index = 0;    // mettre l'attribut valid_index à 0
        printf("SUCCESS : L'index de la colonne a été effacé avec succès.\n");
    } else {
        printf("ERREUR : La colonne n'a pas d'index associé.\n");
    }
}

/**
 * Function: check_index
 * Purpose: Check if an index is correct
 */
int check_index(COLUMN* col) {
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 0;
    }

    if (col->valid_index == 1) {
        printf("L'index de la colonne est correct.\n");
        return 1;
    } else if (col->valid_index == -1) {
        printf("L'index de la colonne existe mais est invalide.\n");
        return -1;
    } else {
        printf("La colonne n'a pas d'index associé.\n");
        return 0;
    }
}

/**
 * Function: update_index
 * Purpose: Update the index
 */
void update_index(COLUMN* col) {
    sort(col, col->sort_dir);   // appeler la fonction de tri pour mettre à jour l'index
}

/**
 * Function: search_value_in_column
 * Purpose: Check if a value exists in a column
 */
int search_value_in_column(COLUMN* col, void* val) {
    if (col == NULL) {
        printf("ERREUR 1 (voir index des erreurs sur GitHub)\n");
        return 0;
    }

    if (col->valid_index != 1) {
        printf("ERREUR : La colonne n'est pas triée.\n");
        return -1;
    }

    int left = 0;
    int right = col->logical_size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (col->Datas[col->index[mid]] == (int)val)
            return 1; // La valeur a été trouvée
        else if (col->Datas[col->index[mid]] < (int)val)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0; // La valeur n'a pas été trouvée
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







    printf("\n");
    printf("\n");
    printf("\n");
    // Exemple d'utilisation
    COLUMN* mycol = create_column("Exemple");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    insert_value(mycol, 18);
    printf("Contenu de la colonne avant le tri :\n");
    print_col(mycol);

    sort(mycol, ASC);
    printf("Contenu de la colonne après le tri :\n");
    print_col_by_index(mycol);

// Exemple avec des chaînes de caractères
    COLUMN* strcol = create_column("Strings");
    insert_value(strcol, 72);
    insert_value(strcol, 44);
    insert_value(strcol, 95);
    insert_value(strcol, 18);

    printf("Contenu de la colonne de chaînes de caractères avant le tri :\n");
    print_col(strcol);

    sort(strcol, DESC);
    printf("Contenu de la colonne de chaînes de caractères après le tri :\n");
    print_col_by_index(strcol);

// Vérification de l'index
    check_index(strcol);

// Recherche d'une valeur
    int search_value = 72;
    int found = search_value_in_column(strcol, &search_value);
    if (found)
        printf("La valeur %d a été trouvée dans la colonne.\n", search_value);
    else
        printf("La valeur %d n'a pas été trouvée dans la colonne.\n", search_value);

// Suppression de l'index
    erase_index(strcol);
    check_index(strcol);

// Libération de la mémoire
    free(mycol->Datas);
    free(mycol->Title);
    free(mycol->index);
    free(mycol);

    free(strcol->Datas);
    free(strcol->Title);
    free(strcol->index);
    free(strcol);

    return 0;
}