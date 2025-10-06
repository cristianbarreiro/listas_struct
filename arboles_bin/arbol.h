#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_arbolb* arbolb;

arbolb crear();
arbolb Insertar(int x, arbolb aizq, arbolb ader);
int raiz(arbolb ab);
arbolb subizq(arbolb ab);
arbolb subder(arbolb ab);
bool vacio(arbolb ab);
bool pertenece1(int x, arbolb ab);
bool pertenece2(int x, arbolb ab);
int max(int x, int y);
int profundidad(arbolb ab);
int cantidad(arbolb ab);
arbolb destruir(arbolb ab);
void destruir1(arbolb &ab);

#endif