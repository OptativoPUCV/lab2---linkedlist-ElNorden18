#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *vectorTmp = (List *) malloc(sizeof(List));
  vectorTmp->head = NULL;
  vectorTmp->tail = NULL;
  vectorTmp->current = NULL;
     return vectorTmp;
}

void * firstList(List * list) {
  if(list->head == NULL)
    return NULL;
  list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) {
  if(list->current == NULL || list->current == list->tail)
    return NULL;
  list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
  if(list->tail == NULL)
    return NULL;
  list->current = list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
  if(list->current == NULL || list->current == list->head)
    return NULL;
  list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *nuevoDato;
  nuevoDato = createNode(data);
  if(list->head== NULL)
  {
    list->head = nuevoDato;
    list->tail = nuevoDato;
  }
  nuevoDato->next = list->head;
  list->head->prev = nuevoDato;
  list->head = nuevoDato;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *nuevoDato;
  nuevoDato = createNode(data);
  if(list->current == list->tail)
  {
    list->tail = nuevoDato;
  }
  nuevoDato->next = list->current->next;
  nuevoDato->prev = list->current;
  list->current->next= nuevoDato;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if(list == NULL)
    return NULL;
  void * aux = list->current->data;
  if(list->current == list->head)
  {
    list->current = list->head->next;
    list->head = list->head->next;
    list->head->prev = NULL;
    return aux;
  }
  if(list->current == list->tail)
  {
    list->current = list->tail->prev;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    return aux;
  }
  list->current = list->current->next;
  
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}