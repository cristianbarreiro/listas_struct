#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstddef>  // Para NULL


typedef struct nodo_abb* abb;

abb crear();
abb Insertar(int x, abb a);

#endif