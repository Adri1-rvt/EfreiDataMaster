/**
 * Fichier : interface.c (fichier gérant l'affichage console)
 * Auteurs : Tess POIRAT, Adrien RIVET
 * Version : 1.2
 */


/**==========DIRECTIVES DU PREPROCESSEUR==========*/
#include "interface.h"   // inclure le fichier d'en-tête associé


/**==========FONCTIONS==========*/
/**
 * Nom : menu
 * Paramètre : /
 * Sortie : /
 * Fonctionnement : afficher le menu de notre programme
 */
void menu() {
    // afficher le logo en caractères ascii de notre projet (parce qu'on a du style nous !)
    printf("___________ _____               .__________          __             _____                   __                \n"
           "\\_   _____// ____\\______   ____ |__\\______ \\ _____ _/  |______     /     \\ _____    _______/  |_  ___________ \n"
           " |    __)_\\   __\\\\_  __ \\_/ __ \\|  ||    |  \\\\__  \\\\   __\\__  \\   /  \\ /  \\\\__  \\  /  ___/\\   __\\/ __ \\_  __ \\\n"
           " |        \\|  |   |  | \\/\\  ___/|  ||    `   \\/ __ \\|  |  / __ \\_/    Y    \\/ __ \\_\\___ \\  |  | \\  ___/|  | \\/\n"
           "/_______  /|__|   |__|    \\___  >__/_______  (____  /__| (____  /\\____|__  (____  /____  > |__|  \\___  >__|   \n"
           "        \\/                    \\/           \\/     \\/          \\/         \\/     \\/     \\/            \\/       \n\n");

    // afficher les informations importantes du projet (moi qui code des tools de hacking d'habitude je trouve que ça fait pro)
    printf("\t==============================================================================================\n"
           "\tAuteurs         : Tess POIRAT, Adrien RIVET                    |                             |\n"
           "\tVersion         : v1.2                                         |           Appuyez           |\n"
           "\tDerniere maj    : 20-05-2024                                   |             Sur             |\n"
           "\tLien Github     : https://github.com/Adri1-rvt/EfreiDataMaster |            Enter            |\n"
           "\t===============================================================|            Pour             |\n"
           "\tBienvenue sur EfreiDataMaster, le projet C qui va vous         |           Lancer            |\n"
           "\tpermettre de liberer la puissance des donnees !                |                             |\n"
           "\t==============================================================================================\n\n\n");

    getchar();   // mettre en pause le programme tant que l'utilisateur ne l'a pas lancé

    // afficher les fonctionnalités pour que l'utilisateur puisse choissir
    printf("=====================================================================================================================\n"
           "LES (INCROYABLES) FONCTIONNALITES D'EFREIDATAMASTER :\n\n"
           "    LANCER \n"
           "    [1] Acceder au logiciel pour utilisation\n\n"
           "    TEST \n"
           "    [2] Test des colonnes d'entier (avec fonctionnalites avancees)\n"
           "    [3] Test des colonnes de differents types (avec fonctionnalites basiques)\n"
           "    [4] Test du cdataframe simple (tableau dynamique)\n"
           "    [5] Test du cdataframe de differents types (tableau dynamique)\n\n"
           "    AUTRE \n"
           "    [6] Credits et commentaires\n"
           "    [7] Quitter le programme\n"
           "=====================================================================================================================\n\n");
}


/**
 * Nom : credits
 * Paramètre : /
 * Sortie : /
 * Fonctionnement : afficher les crédits de notre programme
 */
void credits() {
    printf("Ce programme a ete programme par Tess POIRAT & Adrien RIVET, "
           "\navec la precieuse aide de nos professeurs Mr. KLAI et Mr. KMIMECH"
           "\nOn vous invite a aller voir le depot GitHub de notre projet pour plus d'informations : "
           "\nhttps://github.com/Adri1-rvt/EfreiDataMaster"
           "\nOn espere que notre projet vous plait !"
           "\nPS : Hala Madrid !\n");
}


/**
 * Nom : mode1
 * Paramètre : /
 * Sortie : /
 * Fonctionnement : afficher les fonctionnalités de notre programme en mode 1
 */
void mode1() {
    // afficher le catalogue des fonctionnalités
    printf("===============================================================\n"
           "OPERATIONS DANS LE CDATAFRAME D'ENTIERS:\n\n"
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
           "    [13] Acceder/remplacer la val se trouvant"
           "\n         dans une cellule en utilisant ses coord\n"
           "    [14] Afficher les noms des col\n"
           "===============================================================\n\n");
}