#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstddef>  // Para NULL


struct nodo_lista //necesario para el funcionamiento  de alisarAbb
{
    int dato;
    lista sig;
};


typedef struct nodo_lista *lista;
typedef struct nodo_abb* abb;

abb crear();
abb Insertar(int x, abb a);
int raiz(abb a);
abb subizq(abb a);
abb subder(abb a);
bool vacio(abb a);
bool pertenece(int x, abb a);
int min_der(abb a);
int max_izq (abb a);
int max(int x, int y);
int cantidad(abb a);
int profundidad(abb a);
abb eliminar(int x, abb a);
abb destruir(abb a);
void alisarAbb(abb a, lista &s, lista &l);
int contarHojas(abb a);

#endif