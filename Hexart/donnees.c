#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

int taille()
{
    int c = 0, i = 0, j = 0, comptage = 0;

    FILE* fichier = NULL;
    fichier = fopen("Battements.csv","r");  //Ouverture en read du fichier csv

    while ((c = fgetc(fichier) != EOF))
    {
        if (c!=';')
        {
            if (i == 0)
            {
                fscanf(fichier, "%d", &comptage);
                i ++;
            }
            else
            {
                fscanf(fichier, "%d", &comptage);   //Compteur de lignes en incrémentant j
                i = 0;
                j++;
            }
        }
    }
    fclose(fichier);

    return j;   //Fonction permettant de calculer le nombre de ligne, en sortant la variable j
}


void stockageDonnees(stockageDon *don)
{
    int c, i = 0, j = 0, poul = 0, tmps = 0;

    FILE* fichier = NULL;
    fichier = fopen("Battements.csv","r");  ////Ouverture en read du fichier csv

    while ((c = fgetc(fichier) != EOF))
    {
        if (c!=';') //Ignore le caractère ';' lors de la lecture
        {
            if (i == 0)
            {
                fscanf(fichier, "%d", &poul);
                don[j].detectionIR = poul;  //Enregistre dans le detectionIR la fréquence cardiaque
                i ++;
            }
            else
            {
                fscanf(fichier, "%d", &tmps);
                don[j].temps = tmps;    //Enregistre dans temps le temps en ms
                i = 0;
                j++;
            }
        }
    }
    fclose(fichier);    //fonction permettant de remplir le tableau de structures
}
