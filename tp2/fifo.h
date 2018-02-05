#ifndef _FIFO_H
#define  _FIFO_H

typedef struct fifo fifo;

typedef struct node node;

#include "abr.h"

typedef NOEUD* elem;

struct fifo {
  struct node* first;
  struct node* last;
};

struct node {
  elem value;
  struct node* next;
};

fifo* createFifo();

int isEmpty(fifo* queue);

void enqueue(fifo* queue,elem elem);

int dequeue(fifo* queue,elem* elem);

void queueDisplay(fifo* queue);

void concatQueue(fifo* q1,fifo* q2);

void destroyQueue(fifo* queue);


#endif
