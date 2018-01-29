#include "abr.h"
#include <stdio.h>

int main(){
  NOEUD *a[3]; /* on peut travailler sur 3 arbres */
 char c;
 int i, j;
 element x;
 char nom_fich[20];
 FILE *fich;

 do {printf("Commande ? "); c = getchar();
     switch(c)
     {case 'v' : scanf("%d",&i); a[i] = arbre_vide(); break;
      case 'i' : scanf("%d %d",&x,&i); a[i] = insere(a[i],x); break;
      case 'a' : scanf("%d",&i); affiche_arbre(a[i],1); break;
      case 'q' : exit(0);
     }
     printf("\n"); c = getchar();
 }
while (1);
}
