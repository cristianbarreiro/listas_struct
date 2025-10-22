#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_queue *queue;
typedef struct nodo_cola *cola;

queue crear_queue();
queue enqueue(queue q, int x);
int primero(queue q);
int ultimo(queue q);
bool vacia_queue(queue q);
bool vacia_cola(cola c);
queue dequeue(queue q);
queue destruir_queue(queue q);
cola destruir_cola(cola c);
cola destruir_cola_iter(cola c);
void destruir(cola &c);

#endif // SISTEMA_H_