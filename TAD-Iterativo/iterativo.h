#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct nodo_lista *lista;

lista crear();
lista cons(lista l, int n);
lista snoc(lista l, int n);
bool Null(lista l);
lista quitar(lista l, int n);
void imprimir(lista l);
bool IsElement(lista l, int n);
int contar(lista l);
lista destruir(lista l);
int head(lista l);   // retorna el primer elemento de la lista
lista tail(lista l); // return una lista s/ primer elemento d/lista
int Length(lista l);
int Last(lista l);
int Max(lista l);
float Average(lista l);
lista Insert(lista l, int n);
lista Remove(lista l, int n);
bool Equals(lista l, lista p);
lista Drop(lista l, int i);
lista Take(lista l, int n);
lista Merge(lista l, lista p);
lista Append(lista l, lista p);
lista TakeRecursivo(int i, lista l);
lista DropRecursivo(int u, lista l);
lista MergeRecursivo(lista l, lista p);
lista AppendRecursivo(lista l, lista p);
lista RemoveRecursivo(lista l, int n);

#endif