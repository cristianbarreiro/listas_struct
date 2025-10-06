#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct nodo_lista *lista;

// Funciones básicas de creación y acceso
lista Null();
bool isEmpty(lista l); // equivalente a IsEmpty
int Head(lista l);     // retorna el primer elemento de la lista
lista Tail(lista l);   // return una lista s/ primer elemento d/lista
void printList(lista l);
void Show(lista l, int &cont); // Muestra los elementos de la lista l separados por comas.
// Inserción y construcción
lista cons(lista l, int n);   // agrega n al principio de la lista
lista snoc(lista l, int n);   // agrega n al final de la lista
lista Insert(lista l, int n); // inserta ordenadamente n en l
// Consulta y utilidades
bool IsElement(lista l, int n); // retorna true si n pertenece a l
int HowMany(lista l, int n);    // retorna la cantidad de ocurrencias de n en l
int Length(lista l);            // retorna la cantidad de elementos de la lista
int Last(lista l);              // retorna el último elemento de la lista
int Max(lista l);               // retorna el máximo elemento de la lista
float Average(lista l);         // calcula el promedio de los elementos de la lista
int Sum(lista l);
bool IsSorted(lista l); // retorna true si la lista está ordenada de menor a mayor
// Eliminación y modificación
lista Quitar(lista l, int n);           // devuelve una lista sin el elem n
lista Remove(lista l, int n);           // elimina todas las ocurrencias de n en l
lista Delete(lista l);                  // elimina los elementos de la lista y libera la memoria
lista Change(int x, int y, lista l);    // retorna una nueva lista cambiando x por y en l
lista insOrd(int x, lista l);           // hace practicamente lo mismo que Insert
lista InsBefore(int x, int y, lista l); // inserta x antes de y en l
lista InsAround(int x, int y, lista l); // inserta x antes y después de y en l
// Operaciones entre listas
bool Equals(lista l, lista p);  // retorna true si l y p son iguales
lista Merge(lista l, lista p);  // mezcla dos listas ordenadas l y p
lista Append(lista l, lista p); // agrega la lista p al final de la lista l
// Sublistas
lista Take(int i, lista l); // retorna los primeros i elementos de l
lista Drop(int u, lista l);
#endif