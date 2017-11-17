#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct stockageDon
{
    int detectionIR, temps;
} stockageDon;

int taille();
void stockageDonnees(stockageDon *don);

#endif
