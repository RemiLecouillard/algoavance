#ifndef _ABR_H
#define  _ABR_H

typedef int element;

typedef struct noeud NOEUD, *ABR;

#include "fifo.h"

struct noeud {
	element valeur;
	struct noeud *gauche, *droit;
};

NOEUD *arbre_vide();

NOEUD *insere(NOEUD *p, element x);

void affiche_arbre(NOEUD *p, int col, char truc);

int nbFeuilles(NOEUD *p);

int nbNoeudLargeur(NOEUD *p);

void getFeuilles(NOEUD *p,fifo* file);

int display(NOEUD* abr);

void destroyABR(NOEUD* abr);

#endif
