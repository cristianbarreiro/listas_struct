#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>  // Para malloc, free
#include <cstddef>  // Para NULL

typedef struct nodo_arbol *arbol; // tipo opaco

arbol crear();
arbol primer_hijo(arbol a);
arbol siguiente_hermano(arbol a);
int cantidad(arbol a);
bool pertenece(int x, arbol a);
int profundidad(arbol a);   
bool vacio(arbol a);
arbol destruir(arbol a);
arbol insertar(int x, int padre, arbol a);

#endif