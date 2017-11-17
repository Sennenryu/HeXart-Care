#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "donnees.h"

void afficher(stockageDon *don, int j)
{
    int i;
    for (i=0;i<j;i++)
    {
        printf("%d;",don[i].detectionIR);
        printf("%d\n",don[i].temps);    //Fonction permettant d'afficher le contenu du tableau de structure
    }
}


void valeurTemps(stockageDon *don, int j)
{
    int i, z = 0;

    printf("Veuillez entrer le temps desire en millisecondes : ");  //Entr�e du temps en ms
    scanf("%d",&i);
    printf("\n");

    while(i>don[z].temps && z <= j)
    {
        z++;    //Boucle cherchant le temps le plus proche de celui entr�
    }

    printf("Pour %d on a %d\n", i, don[z].detectionIR); //Affiche la fr�quence en fonction de la ligne du temps trouv�e
}

void plageTemps(stockageDon *don, int j)    //Fais la moyenne sur une plage de temps
{
    int h = 0, i = 0, temp = 0, z = 1, y = 1, sous = 0;
    double result = 0;

    printf("Veuillez entrer la premiere borne en millisecondes entre %d et %d: ", don[z-1].temps, don[j-1].temps);    //Premi�re borne
    scanf("%d",&h);
    while(h < don[z-1].temps|| h > don[j-1].temps)
    {
        printf("Veuillez entrer la premiere borne en millisecondes entre %d et %d: ", don[z-1].temps, don[j-1].temps);
        scanf("%d",&h);
    }
    printf("Veuillez entrer la seconde borne en millisecondes entre %d et %d: ", don[z-1].temps, don[j-1].temps);     //Deuxi�me borne
    scanf("%d",&i);
    while(i < don[z-1].temps|| i > don[j-1].temps)
    {
        printf("Veuillez entrer la seconde borne en millisecondes entre %d et %d: ", don[z-1].temps, don[j-1].temps);
        scanf("%d",&i);
    }
    printf("\n");

    if(h > i)
    {
        temp = h;
        h = i;
        i = temp;   //Si la premi�re borne est plus grande que la deuxi�me, inverse les 2
    }

    while(h > don[z-1].temps && z <= j)
    {
        z++;    //Compteur pour trouver le plus proche temps dans la structure
    }

    while(i > don[y-1].temps && y <= j)
    {
        y++;    //Compteur pour trouver le plus proche temps dans la structure
    }

    sous = y-z+1;   //Nombre de terme

    for(temp = z;temp <= y;temp++)
    {
        result = result + don[temp].detectionIR;  //Fr�quence totale de la premi�re � la deuxi�me borne
    }

    result = result/sous;     //Moyenne en divisant la fr�quence cumul�e par le nombre de terme

    printf("Pour une plage de %d a %d, on a en moyenne %f\n", don[z-1].temps, don[y-1].temps, result);     //Affichage
}

void maxTemps(stockageDon *don, int j)  //Cherche le temps avec la plus grande fr�quence et avec la plus petite
{
    int i = 0, z = 0;

    while(z < j)
    {
        if(don[z].detectionIR > don[i].detectionIR)
        {
            i = z;  //Compare toutes les valeurs et d�s qu'il y en a une plus grande, elle prend la place du maximum
        }
        z++;
    }

    printf("\nLa frequence cardiale maximale est de %d avec un temps de %d.\n", don[i].detectionIR,don[i].temps);

    i = 0, z = 0;

    while(z < j)
    {
        if(don[z].detectionIR < don[i].detectionIR)
        {
            i = z; //Compare toutes les valeurs et d�s qu'il y en a une plus petite, elle prend la place du minimum
        }
        z++;
    }

    printf("La frequence cardiale minimale est de %d avec un temps de %d.\n", don[i].detectionIR,don[i].temps);
}

void fusion(stockageDon tableau[], int deb1, int fin1, int fin2)
{
    stockageDon *table1;
    int deb2 = fin1+1;
    int compt1 = deb1;
    int compt2 = deb2;
    int i;

    table1 = malloc((fin1-deb1+1)*sizeof(stockageDon));

    //on recopie les �l�ments du d�but du tableau
    for(i=deb1; i<=fin1; i++)
    {
        table1[i-deb1] = tableau[i];
    }

    for(i=deb1; i<= fin2; i++)
    {
        if (compt1 == deb2) //c'est que tous les �l�ments du premier tableau ont �t� utilis�s
        {
            break; //tous les �l�ments ont donc �t� class�s
        }
        else if (compt2 == (fin2 + 1)) //c'est que tous les �l�ments du second tableau ont �t� utilis�s
        {
            tableau[i] = table1[compt1-deb1]; //on ajoute les �l�ments restants du premier tableau
            compt1++;
        }
        else if (table1[compt1-deb1].detectionIR<tableau[compt2].detectionIR)
        {
            tableau[i] = table1[compt1-deb1]; //on ajoute un �l�ment du premier tableau
            compt1++;
        }
        else
        {
            tableau[i] = tableau[compt2]; //on ajoute un �l�ment du second tableau
            compt2++;
        }
    }
    free(table1);
}


void tri_fusion_bis(stockageDon tableau[],int deb,int fin)
{
    if (deb != fin)
    {
        int milieu=(fin + deb) / 2;
        tri_fusion_bis(tableau, deb, milieu);
        tri_fusion_bis(tableau, milieu+1, fin);
        fusion(tableau, deb, milieu, fin);
    }
}

void tri_fusion(stockageDon tableau[],int longueur)
{
    if (longueur > 0)
    {
        tri_fusion_bis(tableau, 0, longueur-1);
    }
}
