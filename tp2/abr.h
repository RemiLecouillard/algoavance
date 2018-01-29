#ifndef _ABR_H
#define  _ABR_H


#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct noeud {
	element valeur;
	struct noeud *gauche, *droit;
} NOEUD, *ABR;


NOEUD *arbre_vide();

NOEUD *insere(NOEUD *p, element x);

void affiche_arbre(NOEUD *p, int col);

#endif
