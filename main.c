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
int main()
{
    menu();
    int num;
    while (1) {
        do {
            printf("Tapez le numero de ce que vous voulez faire :");
            scanf("%d", &num);
        } while (num < 1 || num > 7);
        switch (num) {
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


    // test_column();

    // test_cdataframe();

    // test_advanced_column();

    // test_advanced_cdataframe();

    return 0;
}