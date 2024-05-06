/**
 * Fichier : interface.c (fichier gérant l'affichage console)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "interface.h"   // inclure le fichier d'en-tête associé


/**==========FONCTIONS==========*/
void menu() {
    // afficher le logo en caractères ascii de notre projet (parce qu'on a du style !)
    printf("___________ _____               .__________          __             _____                   __                \n"
           "\\_   _____// ____\\______   ____ |__\\______ \\ _____ _/  |______     /     \\ _____    _______/  |_  ___________ \n"
           " |    __)_\\   __\\\\_  __ \\_/ __ \\|  ||    |  \\\\__  \\\\   __\\__  \\   /  \\ /  \\\\__  \\  /  ___/\\   __\\/ __ \\_  __ \\\n"
           " |        \\|  |   |  | \\/\\  ___/|  ||    `   \\/ __ \\|  |  / __ \\_/    Y    \\/ __ \\_\\___ \\  |  | \\  ___/|  | \\/\n"
           "/_______  /|__|   |__|    \\___  >__/_______  (____  /__| (____  /\\____|__  (____  /____  > |__|  \\___  >__|   \n"
           "        \\/                    \\/           \\/     \\/          \\/         \\/     \\/     \\/            \\/       \n\n");

    // afficher les inforlattions importantes du projet
    printf("\t==============================================================================================\n"
           "\tAuteurs         : Tess POIRAT, Adrien RIVET                 |                                |\n"
           "\tVersion         : v1.1                                      |             Appuyez            |\n"
           "\tDerniere maj    : 15-04-2024                                |               Sur              |\n"
           "\tLien Github     : https://github.com/Adri1-rvt/CDataframe   |              Enter             |\n"
           "\t============================================================|              Pour              |\n"
           "\tBienvenue sur EfreiDataMaster, le projet C qui va vous      |             Lancer             |\n"
           "\tpermettre de liberer la puissance des donnees !             |                                |\n"
           "\t==============================================================================================\n\n\n");
    getchar();   // mettre en pause le programme tant que l'utilisateur ne l'a pas lancé

    // afficher le catalogue des fonctionnalités
    printf("=====================================================================================================================\n"
           "OPERATIONS DANS LE CDATAFRAME:\n\n"
           "    ALIMENTATION :                                            AFFICHAGE :\n"
           "    [01] Creer                                                [04] Afficher\n"
           "    [02] Remplir par saisies                                  [05] Afficher une partie des lig selon une limite\n"
           "    [03] Remplir en dur                                       [06] Afficher une partie des col selon une limite\n\n"
           "    OPERATIONS USUELLES :                                     ANALYSE ET STATISTIQUES :\n"
           "    [07] Ajouter une lig de val                               [15] Afficher le nb de lig\n"
           "    [08] Supprimer une lig de val                             [16] Afficher le nb de col\n"
           "    [09] Ajouter une col                                      [17] Nb de cellules contenant une val = x\n"
           "    [10] Supprimer une col                                    [18] Nb de cellules contenant une val > x\n"
           "    [11] Renommer le titre d une col                          [19] Nb de cellules contenant une val < x\n"
           "    [12] Verifier l existence d une val\n"
           "    [13] Acceder/remplacer la val se trouvant "
           "\n         dans une cellule en utilisant ses coord\n"
           "    [14] Afficher les noms des col\n\n"
           "=====================================================================================================================\n\n\n");
}