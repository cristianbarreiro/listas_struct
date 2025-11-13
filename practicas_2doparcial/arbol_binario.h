#ifndef ARBOL_BINARIO_H_
#define ARBOL_BINARIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo_arbol *abb;

abb subizq(abb a);
abb subder(abb a);
bool vacio(abb a);
int maximo(abb a);
int suma(abb a);
int sumaMayoresQueK(abb a, int k);
int profundidad(abb a);
bool balanceado(abb a);

#endif