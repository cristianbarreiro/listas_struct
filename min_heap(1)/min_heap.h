#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo_minheap* minheap;

minheap minheap_crear();
minheap minheap_insertar(minheap h, int valor);
int minheap_minimo(minheap h);
bool minheap_lleno(minheap h);
minheap minheap_eliminar_minimo(minheap h);
minheap minheap_destruir(minheap h);
void minheap_imprimir(minheap h);

#endif