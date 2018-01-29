#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "fifo.h"


fifo* createFifo() {
  fifo* res = malloc(sizeof(fifo));
  res->first = NULL;
  res->last = NULL;
  return res;
}

int isEmpty(fifo* queue) {
  assert(queue);

  return !queue->first;
}

void enqueue(fifo* queue,elem elem) {
  node* new;
  assert(queue);

  new = malloc(sizeof(node));
  new->value = elem;
  new->next = NULL;

  if (queue->last) {
    queue->last->next = new;
    queue->last = new;
  } else {
    queue->first = new;
    queue->last = new;
  }
}

int dequeue(fifo* queue,elem* elem) {
  node* tmp;
  assert(queue);

  if (isEmpty(queue)) {
    return 0;
  }

  *elem = queue->first->value;
  if (queue->first == queue->last) {
    queue->last = NULL;
  }

  tmp = queue->first;
  queue->first = queue->first->next;

  free(tmp);

  return 1;
}

void queueDisplay(fifo* queue) {
  node* current;
  assert(queue);

  current = queue->first;
  while(current) {
    printf("-> %d", current->value);
    current = current->next;
  }
  printf("\n");
}

void concatQueue(fifo* q1,fifo* q2) {
  assert(q1);
  assert(q2);

  if(q1->last) {
    q1->last->next = q2->first;
    q1->last = q2->last;
    q2->first = q1->first;
  } else {
    q1->first = q2->first;
    q1->last = q2->last;
  }
}

void destroyQueue(fifo* queue) {
  node* current;
  node* tmp;

  current = queue->first;

  while(current) {
    tmp = current;
    current = current->next;
    free(tmp);
  }
  free(queue);
}
