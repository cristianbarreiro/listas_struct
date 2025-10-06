#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct nodo_lista *lista;

// Funciones básicas de creación y acceso
lista crear();
bool Null(lista l);  // equivalente a IsEmpty
int Head(lista l);   // retorna el primer elemento de la lista
lista Tail(lista l); // return una lista s/ primer elemento d/lista
void printList(lista l);
void Show(lista l); // Muestra los elementos de la lista l separados por comas.
// Inserción y construcción
lista cons(lista l, int n);
lista snocRecursivo(lista l, int n);
lista InsertRecursivo(lista l, int n);
// Consulta y utilidades
bool IsElement(lista l, int n); // retorna true si n pertenece a l
int HowMany(int x, lista l);
int Length(lista l);          // iterativo
int LengthRecursivo(lista l); // retorna la cantidad de elementos de la lista
int LastRecursivo(lista l);
int MaxRecursivo(lista l);
float AverageRecursivo(lista l);
bool IsSortedRecursivo(lista l);
// Eliminación y modificación
lista Quitar(lista l, int n); // devuelve una nueva lista sin el elem n
lista RemoveRecursivo(lista l, int n);
lista DeleteRecursivo(lista l);         // elimina los elementos de la lista y libera la memoria
lista Change(int x, int y, lista l);    // retorna una nueva lista cambiando x por y en l
lista InsBefore(int x, int y, lista l); // inserta x antes de y en l
lista InsAround(int x, int y, lista l); // inserta x antes y después de y en l
// Operaciones entre listas
bool EqualsRecursivo(lista l, lista p);
lista MergeRecursivo(lista l, lista p);
lista AppendRecursivo(lista l, lista p);
// Sublistas
lista TakeRecursivo(int i, lista l);
lista DropRecursivo(int u, lista l);

#endif