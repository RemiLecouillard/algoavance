#ifndef _DICO_H
#define  _DICO_H

#define hasBrother(node) node->brother
#define hasSon(node) node->son

typedef struct node NTree;

struct node {
  char letter;
  struct node* son;
  struct node* brother;
};

int search(NTree* tree,char* word);

NTree* add(NTree* tree,char* word);

NTree* load(char* fileName);

void display(NTree* tree,char* buf,int index);

void save(NTree* tree,char* fileName);

NTree* getLetterInBrother(NTree* tree,char letter);

int nbWords(NTree* tree);

int nbWordsBeginsBy(NTree* tree,char letter);


#endif
