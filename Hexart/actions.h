#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

void afficher(stockageDon *a, int j);

void fusion(stockageDon tableau[],int deb1,int fin1,int fin2);
void tri_fusion_bis(stockageDon tableau[],int deb,int fin);
void tri_fusion(stockageDon tableau[],int longueur);

void plageTemps(stockageDon *don, int j);
void valeurTemps(stockageDon *don, int j);
void maxTemps(stockageDon *don, int j);

#endif
