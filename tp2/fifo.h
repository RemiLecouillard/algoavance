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

/**
  * Creates a queue
  * @return a pointer of a queue.
  */
fifo* createFifo();

/**
  * @param queue the fifo to use.
  * @return 1 if empty 0 OTHERWISE
  */
int isEmpty(fifo* queue);

/**
  * @param queue the fifo to use.
  * @param elem the element to enqueue
  */
void enqueue(fifo* queue,elem elem);

/**
  * @param queue the fifo to use.
  * @param elemn a pointer to an element that will be change to the top element.
  * @return 0 if it has not been remove, 1 otherwise
  */
int dequeue(fifo* queue,elem* elem);

/**
  * @param queue the fifo to use.
  */
void queueDisplay(fifo* queue);

/**
  * @param q1 the first fifo to use.
  * @param q2 the second fifo to concat.
  */
void concatQueue(fifo* q1,fifo* q2);

/**
  * @param queue the fifo to use.
  */
void destroyQueue(fifo* queue);


#endif
