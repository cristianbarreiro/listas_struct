#ifndef GENERALES_H_
#define GENERALES_H_

#include <stdio.h>
#include <stdbool.h>

// Definición completa de la lista simple
struct nodo_lista
{
    int dato;
    lista sig;
};
// Definición opaca de la lista general
typedef struct nodo_listagral *listagral;
typedef struct nodo_lista *lista;

// ==== Funciones para lista simple ====
bool isEmpty(lista l);
int Head(lista l);   // Pre: l no vacía
lista Tail(lista l); // Pre: l no vacía
int Length(lista l);
void Show(lista l);
void ShowLG(listagral lg);

// ==== Funciones para lista general ====
listagral Null();
listagral ConsLG(listagral lg, lista l);
bool IsEmptyLG(listagral lg);
int Head(lista l);
lista HeadLG(listagral lg); // Pre: lg no vacía
lista Tail(lista l);
listagral TailLG(listagral lg); // Pre: lg no vacía
int LengthLG(listagral lg);
void ShowLG(listagral lg);

#endif