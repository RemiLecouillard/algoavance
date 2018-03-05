#include "dico.h"
#include <stdlib.h>
#include <stdio.h>

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

void saveRec(NTree* tree,char buf[],int index,FILE* file) {
  if (tree) {
    buf[index] = tree->letter;
    if (buf[index] == '\0') {
      fprintf(file, "%s\n", buf);
    }
    saveRec(tree->son, buf, index + 1, file);
    saveRec(tree->brother, buf, index, file);
  }
}

void save(NTree* tree,char* fileName) {
  FILE* file;
  char buf[30];

  file = fopen(fileName, "w+");

  if (file) {
    saveRec(tree, buf, 0, file);
    fclose(file);
  } else {
    printf("Impossible d'ouvrir le fichier %s\n", fileName);
  }
}

NTree* getLetterInBrother(NTree* tree,char letter) {
  if (tree) {
    if (tree->letter == letter) {
      return tree;
    } else {
      return getLetterInBrother(tree->brother, letter);
    }
  } else {
    return NULL;
  }
}

int nbWords(NTree* tree) {
  if (tree) {
    if (tree->letter == '\0') {
      return 1 + nbWords(tree->brother);
    }
    return nbWords(tree->son) + nbWords(tree->brother);
  } else {
    return 0;
  }
}

int nbWordsBeginsBy(NTree* tree,char letter) {
  tree = getLetterInBrother(tree, letter);

  if (tree) {
    return nbWords(tree->son);
  } else {
    return 0;
  }
}
