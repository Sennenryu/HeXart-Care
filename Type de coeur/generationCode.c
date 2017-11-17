#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"
    //Tous les types de param.h possible � g�n�rer
void coeur(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");   //Ouverture/cr�ation/r�initialisation du fichier param.h

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n"); //fprintf ecrit dans le fichier
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");   //Dans le code arduino, il y a 2 boucles for, le type permet d'entrer dans l'un ou dans l'autre
    fprintf(fichier, "#define INIT 0\n");   //Le init se charge de l'initialisation de la boucle for
    fprintf(fichier, "#define PAS 1\n\n");  //Le pas change la boucle for

    fprintf(fichier, "#endif");

    fclose(fichier);    //Fermeture du fichier
    printf("Votre fichier param.h est pret a etre utilise.");
}
void coeur2(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT 0\n");
    fprintf(fichier, "#define PAS 2\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est pret a etre utilise.");
}
void coeur3(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT 1\n");
    fprintf(fichier, "#define PAS 3\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est pret a etre utilise.");
}
void coeur4(void)
{
    int pin = 0;
    printf("Choisissez la LED unique a clignoter, de 1 a 10 : ");
    scanf("%d",&pin);   //Demande � l'utilisateur le pin � faire clignoter
    while ((pin>10)||(pin<1))
    {
        printf("Choisissez la LED unique a clignoter, de 1 a 10 : ");   //Boucle de v�rification pour ne pas d�passer
        scanf("%d",&pin);
    }
    pin -= 1;   //Fait correspondre � nos branchements de LEDs
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 0\n");
    fprintf(fichier, "#define INIT %d\n",pin);
    fprintf(fichier, "#define PAS 0\n\n");

    fprintf(fichier, "#endif");

    fclose(fichier);
    printf("Votre fichier param.h est pret a etre utilise.");
}
void coeur5(void)
{
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w+");

    fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n");
    fprintf(fichier, "#define PARAM_H_INCLUDED\n\n");

    fprintf(fichier, "#define TYPE 1\n");
    fprintf(fichier, "#define INIT 0\n");
    fprintf(fichier, "#define PAS 1\n\n");

    fprintf(fichier, "#endif\n");

    fclose(fichier);
    printf("Votre fichier param.h est pret a etre utilise.");
}
