#ifndef LISTA_H

#define LISTA_H

typedef struct no
{
  int value;
  struct no *next;
} No;

typedef struct lista {
  struct no *head;
} Lista;

void init(Lista *l);
void insert(Lista *l, int value);
void print(Lista *l);
void push(Lista *l, int value,unsigned int index);
void pop(Lista *l, unsigned int index);
#endif