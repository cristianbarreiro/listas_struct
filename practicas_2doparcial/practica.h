#ifndef PRACTICA_H_
#define PRACTICA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo_cola *cola;

typedef struct nodo_queue *queue;

queue insertar(queue q, int x);
queue eliminar(queue q);




#endif  // PRACTICA_H_
