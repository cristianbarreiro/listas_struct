#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstddef>  // Para NULL


typedef struct nodo_abb* abb;

abb crear();
abb Insertar(int x, abb a);
bool pertenece1(int x, abb a);
int cantidad(abb a);
int max(int x, int y);

#endif