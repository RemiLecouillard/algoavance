#include "abr.h"


#include <stdio.h>
#include <stdlib.h>


/*****************************************************************************/
NOEUD *arbre_vide() {return NULL; }
/*****************************************************************************/
NOEUD *insere(NOEUD *p, element x)
{if (p == NULL)
    {p = (NOEUD *)malloc(sizeof(NOEUD));
     p->valeur = x;p->gauche = NULL;p->droit = NULL;
    }
 else if (x == p->valeur) printf("%d est deja dans l'arbre\n",x);
      else if (x < p->valeur)  p->gauche = insere(p->gauche,x);
                          else p->droit  = insere(p->droit,x);

return(p);
}
/*****************************************************************************/
void affiche_arbre(NOEUD *p, int col)
{int i;
 if (p)
    {affiche_arbre(p->droit,col+1);
     for (i=0;i<col;i++) printf("   ");
     printf("%d\n",p->valeur);
     affiche_arbre(p->gauche,col+1);
    }
}
