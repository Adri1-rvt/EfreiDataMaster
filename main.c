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


/**==========FONCTION MAIN==========*/
int classic_run() {
    int n, n1, n2;
    printf("Choisir d'utiliser le CDataframe d'entiers (1) ou de tout types de donnees (2) :");
    scanf("%d", &n);
    if (n == 1) {
        mode1();
        while (1) {
            do {
                printf("Tapez le numero de ce que vous voulez faire (de 01 a 25) :");
                scanf("%d", &n1);
            } while (n1 < 1 || n1 > 25);
            switch (n1) {
                case 01:
                    classic_run();
                    printf("\n==============================================================================================\n");
                    break;
                case 02:
                    test_column();
                    printf("\n==============================================================================================\n");
                    break;
            }
        }
        printf("\n==============================================================================================\n");
    }
    if (n == 2) {
        mode2();
        while (1) {
            do {
                printf("Tapez le numero de ce que vous voulez faire (de 01 a 20) :");
                scanf("%d", &n2);
            } while (n2 < 1 || n2 > 20);
            switch (n2) {
                case 01:
                    classic_run();
                    printf("\n==============================================================================================\n");
                    break;
                case 02:
                    test_column();
                    printf("\n==============================================================================================\n");
                    break;
            }
        }
        printf("\n==============================================================================================\n");
    }
}


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
                printf("Merci et a bientot !");
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}