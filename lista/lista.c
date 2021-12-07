#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void init(Lista *l){
  l->head = NULL;
}
void insert(Lista *l, int value){
  No *n = (No*)malloc(sizeof(No));
  n->value = value;
  No *aux;
  aux = l->head;
  if(l->head == NULL){
    l->head = n;
    n->next = NULL;
  }
  else{
    while(aux->next != NULL){
      aux = aux->next;
    }
    aux->next = n;
    n->next = NULL;
  }
}
void print(Lista *l){
  No *aux;
  aux = l->head;
  while(aux != NULL){
    printf("%d >", aux->value);
    aux = aux->next;
  }
}

void push(Lista *l, int value,  unsigned int index){
  No *n = (No*)malloc(sizeof(No));
  n->value = value;
  No *aux;
  aux = l->head;
  if(l->head == NULL){
    l->head = n;
    n->next = NULL;
  }
  else if( index == 0){
    n->next = l->head;
    l->head = n;
  }
  else{
    for(int i = 0; i < index-1; i++){
      if(aux->next == NULL){
        aux->next = n;
        n->next = NULL;
        return;
      }
      aux = aux->next;
    }
    n->next = aux->next;
    aux->next = n;
    return;
  }
}

void pop(Lista *l,unsigned int index){
  No *aux;
  aux = l->head;
  if(l->head == NULL){
    printf("Lista vazia");
  }
  else{
    for(int i = 0; i < index; i++){
      aux = aux->next;
    }
    aux->next = aux->next->next;
  }

}
