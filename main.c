#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main()
{
    system("title Traitement de données"); //Nom de le fenêtre

    int j = taille(), menu = 8;  //Initialisation des valeurs
    stockageDon *don, tableauDon[j];
    don = malloc(sizeof(stockageDon) * j+1);    //Initialisation des tableaux de structures et allocations de mémoires

    stockageDonnees(don);   //Definition de la structure don contenant le contenu du fichier csv

    for (int i=0;i<j;i++)
    {
        tableauDon[i] = don[i]; //Rempli tableauDon de don, pour sauvegarder
    }

    affichageMenu(&menu);   //Affiche le menu

    while (menu != 7)   //Boucle du menu et selection
    {
        for (int i=0;i<j;i++)
        {
            don[i] = tableauDon[i]; //Réaffectation à chaque boucle de don
        }

        switch(menu)    //Un case pour chaque option
        {
        case 1:
            {
                afficher(don, j);
                system("pause");
                affichageMenu(&menu);
                break;
            }
        case 2:
            {
                tri_fusion(don,j);
                tri_fusion(don,j);
                afficher(don, j);
                system("pause");
                affichageMenu(&menu);
                break;
            }

        case 3:
            {
                valeurTemps(don,j);
                system("pause");
                affichageMenu(&menu);
                break;
            }

        case 4:
            {
                plageTemps(don,j);
                system("pause");
                affichageMenu(&menu);
                break;
            }

        case 5:
            {
                printf("Il y a %d lignes dans les donnees de memoire.\n", j);
                system("pause");
                affichageMenu(&menu);
                break;
            }

        case 6:
            {
                maxTemps(don,j);
                system("pause");
                affichageMenu(&menu);
                break;
            }

        default:
            break;
        }
    }
    free(don);  //libération de la mémoire
}
