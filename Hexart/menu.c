#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


void affichageMenu(int *menu)
{
    *menu = 8;
    while(*menu < 1 || *menu > 7)
    {
        *menu = selectionMenu();    //Fonction pour rester ou sortir du menu
    }

}

int selectionMenu()
{
    int input = 0;

    system("cls");
    printf("#######################################################################\n");
    printf("                 AFFICHAGE ET CLASSEMENT DES DONNEES\n");
    printf("#######################################################################\n");
    printf("\n   1 - Afficher donnees dans l'ordre\n   2 - Affiche donnees dans l'ordre croissant\n   3 - Rechercher et afficher les donnees pour un temps particulier\n   4 - Affiche la moyenne de la frequence cardiaque sur un temps donne\n   5 - Affiche le nombre de lignes de donnees en memoire\n   6 - Rechercher et afficher frequence card. max/min + temps associe\n   7 - Quitter");
    printf("\n\nSelectionnez l'option que vous desirez utiliser: ");
    scanf("%d",&input);

    return input;   //Fonction pour afficher le menu, demander et renvoyer le choix de l'utilisateur
}
