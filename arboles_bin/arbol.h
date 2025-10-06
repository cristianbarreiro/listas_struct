#ifndef GENERALES_H_
#define GENERALES_H_

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
int cantidad(arbol ab);
arbolb destruir(arbol ab);
void destruir(arbolb &ab);

#endif