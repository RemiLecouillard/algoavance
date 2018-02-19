#include "dico.h"
#include <stdlib.h>
#include <stdio.h>

NTree* createNTree() {
  NTree* tree = malloc(sizeof(NTree));
  tree->letter = 2;
  tree->brother = NULL;
  tree->son = NULL;
  return tree;
}

int search(NTree* tree,char* word) {
  if(tree->letter == 2){
    if (hasSon(tree)) {
      return search(tree->son,word);
    } else {
      return 0;
    }
  }
  if (word[0] == tree->letter) {
    if(word[0] == '\0') {
      /* if we have found the word */
      return 1;
    } else  {
      if (hasSon(tree)) {
        /* if we'r on the way of finding the word */
        return search(tree->son, &word[1]);
      } else  {
        /* if there is no match */
        return 0;
      }
    }
  } else if (hasBrother(tree)) {
    /* still searching for the correct letter */
    return search(tree->brother, word);
  } else {
    /* if there is no match */
    return 0;
  }
}

void addBrother(NTree* tree,char letter) {
  NTree* new;
  new = malloc(sizeof(NTree));
  new->letter = letter;
  new->son = NULL;
  new->brother = tree->brother;
  tree->brother = new;
}
/*
NTree* getLetterInSons(NTree* tree,char letter) {
  NTree* current;
  NTree* new;
  if (hasSon(tree)) {
    current = tree->son;
    while(current->letter != letter){
      if (!hasBrother(current)) {
        addBrother(current, letter);
      } else if(current->brother->letter > letter){
        addBrother(current, letter);
      }
      current = current->brother;
    }
  } else {
    new = malloc(sizeof(NTree));
    new->letter = letter;
    new->son = NULL;
    new->brother = NULL;
    tree->son = new;
    current = new;
  }
  return current;
}


void add(NTree* tree,char* word) {
  NTree* node;
  int i;

  i = -1;
  node = tree;

  do {
    i++;
    node = getLetterInSons(node, word[i]);
  } while(word[i] != '\0');
}*/

NTree* add(NTree* tree,char* word) {
  NTree* current;
  NTree* new;

  new = NULL;
  current = NULL;
  if (!tree) {

    current = malloc(sizeof(NTree));
    current->letter = word[0];
    current->brother = NULL;
    current->son = NULL;
    new = NULL;

  } else if (word[0] == tree->letter) {
    current = tree;
    new = tree->son;
  } else if (tree->letter > word[0]){
    current = malloc(sizeof(NTree));
    current->letter = word[0];
    current->brother = tree;
    current->son = NULL;
    new = NULL;
  } else {
    current = tree;
    while(current->letter != word[0]){

      if (!hasBrother(current)) {
        addBrother(current, word[0]);
      } else if(current->brother->letter > word[0]){
        addBrother(current, word[0]);
      }
      current = current->brother;
      new = current->son;
    }
  }

  if (word[0] != '\0') {
    new = add(new, &word[1]);
    if(!hasSon(current)) {
      current->son = new;
    } else if (current->letter < tree->letter) {
      current->son = new;
    }
  }
  return current;
}


NTree* load(char* fileName) {
  FILE* file;
  NTree* tree;
  char buf[30];

  tree = NULL;
  file = fopen(fileName, "r");

  fscanf(file, "%s\n", buf);
  tree = add(tree, buf);
  if (file) {
    while(fscanf(file, "%s\n", buf) != -1) {
      add(tree, buf);
    }
    fclose(file);
  }

  return tree;
}

void display(NTree* tree,char buf[],int index){
  if (tree) {
    buf[index] = tree->letter;
    if (buf[index] == '\0') {
      printf("-> %s\n", buf);
    }
    display(tree->son, buf, index + 1);
    display(tree->brother, buf, index);
  }
}
