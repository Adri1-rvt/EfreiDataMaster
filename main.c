/**
 * Fichier : main.c (fichier principal de notre programme)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
// Note : certains fichiers d'en-tête sont inclus dans les autres, ainsi nous ne les importons pas tous dans le fichier main pour avoir un code fonctionnel (sans erreur de conflits)
#include "cdataframe.h"   // inclure le fichier d'en-tête cdataframe.h (le fichier column.h est inclu dedans)
#include "interface.h"   // inclure le fichier d'en-tête interface.h
#include "advanced_cdataframe.h"   // inclure le fichier d'en-tête advanced_cdataframe.h (le fichier advanced_column.h est inclu dedans)


/**==========FONCTION==========*/
/**
 * Nom : classic_run
 * Paramètre : /
 * Sortie : /
 * Fonctionnement : scénario d'utilisation de notre outil en mode classic
 */
void classic_run() {
    int n;
    int running = 1;
    printf("Voici notre programme CDataframe d'entiers :");
    mode1();
    CDATAFRAME* dataframe = NULL;
    while (running) {
        printf("Tapez le numero de ce que vous voulez faire (de 1 a 25) :");
        scanf("%d", &n);
        switch (n) {
            case 1:
                dataframe = create_dataframe();
                if (dataframe != NULL) printf("CDataframe cree avec succes !\n");
                break;
                case 2:
                    if (dataframe != NULL) fill_dataframe_by_input(dataframe);
                    else printf("Erreur : CDataframe non cree.\n");
                    break;
                case 3:
                    if (dataframe != NULL) {
                        fill_dataframe(dataframe);
                        printf("Test du remplissage en dur de notre CDataframe reussi !\n");
                    }
                    else printf("Erreur : CDataframe non cree.\n");
                    break;
                case 4:
                    if (dataframe != NULL) {
                        printf("Test de l'affichage complet de notre CDataframe :\n");
                        print_dataframe(dataframe);
                    }
                    else printf("Erreur : CDataframe non cree.\n");
                    break;
                case 5: {
                    printf("Affichage d'un certain nombre de lignes du CDataframe :\n");
                    printf("Nombre de lignes a afficher : ");
                    int nb;
                    scanf("%d", &nb);
                    print_somme_rows(dataframe, nb);
                    break;
                }
                case 6: {
                    printf("Affichage d'un certain nombre de colonnes du CDataframe :\n");
                    printf("Nombre de colonnes a afficher : ");
                    int nb;
                    scanf("%d", &nb);
                    print_somme_columns(dataframe, nb);
                    break;
                }
                case 7: {
                    int new_row_values[] = {10, 20, 30};
                    add_row(dataframe, new_row_values);
                    printf("Ajout d'une nouvelle ligne au CDataframe :\n");
                    break;
                }
                case 8: {
                    printf("Suppression d'une ligne au CDataframe :\n");
                    printf("Ligne a supprimer : ");
                    int nb;
                    scanf("%d", &nb);
                    remove_row(dataframe, nb);
                    break;
                }
                case 9:
                    printf("Ajout d'une nouvelle colonne au CDataframe :\n");
                    printf("Nom de la nouvelle colonne : ");
                    char Tab[20];
                    scanf("%s", &Tab);
                    add_column(dataframe, Tab);
                    break;
                case 10:
                    printf("Suppression d'une colonne au CDataframe :\n");
                    printf("Colonne a supprimer : ");
                    int nb;
                    scanf("%d", &nb);
                    remove_column(dataframe, nb);
                    break;
                case 11: {
                    printf("Renommage d'une colonne au CDataframe :\n");
                    printf("Index de la colonne a modifier : ");
                    int nb;
                    scanf("%d", &nb);
                    printf("Nouveau nom de la colonne : ");
                    char Tab[20];
                    scanf("%s", &Tab);
                    rename_column(dataframe, nb, Tab);
                    break;
                }
                case 12: {
                    printf("Recherche d'une valeur dans le CDataframe :\n");
                    printf("Valeur a rechercher : ");
                    int nb;
                    scanf("%d", &nb);
                    if (search_value(dataframe, nb)) printf("Youpi, la valeur %d est bien dans le CDataframe !\n", 4);
                    else printf("Oh zut, la valeur %d n'est pas dans le CDataframe.\n", 4);
                    break;
                }
                case 13: {
                    printf("Acces a une valeur dans le CDataframe :\n");
                    printf("Index de la valeur a rechercher (x,y) : ");
                    int nb, nb2;
                    scanf("%d,%d", &nb, nb2);
                    printf("Nouvelle valeur : ");
                    int nb3;
                    scanf("%d", &nb3);
                    printf("Valeur a l'index (%d, %d) : %d\n", nb, nb2, get_value(dataframe, nb, nb2));
                    set_value(dataframe, nb, nb2, nb3);
                    printf("Modification d'une valeur dans le CDataframe (ici on va remplacer 5 par 99) :\n");
                    print_dataframe(dataframe);
                    break;
                }
                case 14:
                    printf("Afficher les noms des colonnes :\n");
                    print_column_names(dataframe);
                    break;
                case 15:
                    printf("Comptage de nombre de lignes du CDataframe :\n");
                    printf("Nombre de lignes dans le CDataframe : %d\n", count_rows(dataframe));
                    break;
                case 16:
                    printf("Comptage de nombre de colonnes du CDataframe :\n");
                    printf("Nombre de colonnes dans le CDataframe : %d\n", count_columns(dataframe));
                    break;
                case 17: {
                    printf("Comptage des cellules contenant une valeur :\n");
                    printf("Valeur a rechercher : ");
                    int nb;
                    scanf("%d", &nb);
                    printf("Nombre de cellules contenant la valeur %d : %d\n", nb, count_cells_equal(dataframe, nb));
                    break;
                }
                case 18: {
                    printf("Comptage des cellules contenant une valeur superieure :\n");
                    printf("Valeur a rechercher : ");
                    int nb;
                    scanf("%d", &nb);
                    printf("Nombre de cellules contenant une valeur superieure a %d : %d\n", nb,
                           count_cells_sup(dataframe, nb));
                    break;
                }
                case 19: {
                    printf("Comptage des cellules contenant une valeur inferieure :\n");
                    printf("Valeur a rechercher : ");
                    int nb;
                    scanf("%d", &nb);
                    printf("Nombre de cellules contenant une valeur inferieure a %d : %d\n", nb, count_cells_inf(dataframe, nb));
                    break;
                }
                case 26:
                    printf("Quitter le programme\n");
                    printf("Merci et a bientot !");
                    running = 0;
                    break;
                case 27:
                    printf("Sortir du mode classic\n");
                    running = 0;
                    break;
                default:
                    printf("Option non valide\n");
        }
        printf("\n==============================================================================================\n");
    }
}



/**==========FONCTION MAIN==========*/
int main() {
    menu();
    int num;
    while (1) {
        do {
            printf("Tapez le numero de ce que vous voulez faire :");
            scanf("%d", &num);
        } while (num < 1 || num > 7);
        switch (num) {
            case 1:
                classic_run();
                printf("\n==============================================================================================\n");
                break;
            case 2:
                test_column();
                printf("\n==============================================================================================\n");
                break;
            case 3:
                test_advanced_column();
                printf("\n==============================================================================================\n");
                break;
            case 4:
                test_cdataframe();
                printf("\n==============================================================================================\n");
                break;
            case 5:
                test_advanced_cdataframe();
                printf("\n==============================================================================================\n");
                break;
            case 6:
                credits();
                printf("\n==============================================================================================\n");
                break;
            case 7:
                printf("Merci et a bientot ! \nHala Madrid !");
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}