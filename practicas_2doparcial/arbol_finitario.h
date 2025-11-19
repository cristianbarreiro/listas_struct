#ifndef ARBOL_FINITARIO_H_
#define ARBOL_FINITARIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>

typedef struct nodo_arbol *arbol;

arbol subizq(arbol a);
arbol subder(arbol a);
bool vacio(arbol a);
int maximo(arbol a);
int suma(arbol a);
int sumaMayoresQueK(arbol a, int k);
int profundidad(arbol a);
bool balanceado(arbol a);
int MayorCantidadNivelQueue(arbol a);
void contarNodosRecursivo(arbol a, int nivel, int conteoNiveles[]);
int MayorCantidadNivel(arbol a);

#endif