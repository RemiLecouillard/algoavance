#include "abr.h"
#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>

#define estFeuille(p) p->gauche == NULL && p->droit == NULL


NOEUD *arbre_vide() {
  return NULL;
}

NOEUD *insere(NOEUD *p, element x) {
  if (p == NULL){
    p = (NOEUD *)malloc(sizeof(NOEUD));
     p->valeur = x;p->gauche = NULL;p->droit = NULL;
    }
 else if (x == p->valeur){
   printf("%d est deja dans l'arbre\n",x);
 } else if (x < p->valeur){
    p->gauche = insere(p->gauche,x);
  } else {
     p->droit  = insere(p->droit,x);
  }

  return(p);
}

void affiche_arbre(NOEUD *p, int col,char truc) {
  int i;
  if (p)
    {affiche_arbre(p->droit,col+1, '/');
     for (i=0;i<col;i++) printf("   ");
     printf("%c%d\n", truc, p->valeur);
     affiche_arbre(p->gauche,col+1, '\\');
   }
}

int nbFeuilles(NOEUD *p) {
  if (estFeuille(p)) {
    return 1;
  } else {
    return ( p->gauche ? nbFeuilles(p->gauche) : 0 ) +
      ( p->droit ? nbFeuilles(p->droit) : 0 );
  }
}

int nbNoeudLargeur(NOEUD *p) {
  fifo* queue;
  int nb;

  queue = createFifo();
  enqueue(queue, p);
  nb = 0;

  while (!isEmpty(queue)) {
    dequeue(queue, &p);
    nb++;
    if (p->gauche) {
      enqueue(queue, p->gauche);
    }
    if (p->droit) {
      enqueue(queue, p->droit);
    }
  }
  return nb;
}

void getFeuilles(NOEUD *p,fifo* file) {
  if (estFeuille(p)) {
    enqueue(file, p);
  } else {
    if (p->gauche) {
      getFeuilles(p->gauche, file);
    }
    if (p->droit) {
      getFeuilles(p->droit, file);
    }
  }
}


int display(NOEUD* abr) {
   int res;

   if ( !abr) {
      return 0;
   }
   printf("%d\t", abr->valeur);

   res = display( abr->gauche) + display( abr->droit) ;

    printf("%d\t", abr->valeur);

   return ++res;

}

void destroyABR(NOEUD* abr) {
  if (abr) {
    destroyABR(abr->gauche);
    destroyABR(abr->droit);
    free(abr);
  }
}
