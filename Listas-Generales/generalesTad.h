#ifndef GENERALESTAD_H_
#define GENERALESTAD_H_

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

// Prototipos de funciones para lista general
listagral NullLG();
listagral ConsLG(listagral lg, lista l);
bool IsEmptyLG(listagral lg);
lista HeadLG(listagral lg);     // Pre: lg no vacía
listagral TailLG(listagral lg); // Pre: lg no vacía
int LengthLG(listagral lg);
void ShowLG(listagral lg);

#endif