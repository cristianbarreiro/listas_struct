#include "practica.h"

typedef struct nodo_cola *cola;

struct nodo_cola
{
    int dato;
    cola sig;
};

typedef struct nodo_queue *queue;

struct nodo_queue
{
    cola primero;
    cola ultimo;
    int suma;
};

queue insertar(queue q, int x)
{
    // Inserta x al final de q
    cola aux = new (nodo_cola);
    aux->dato = x;
    aux->sig = NULL;

    if (q->primero != NULL && q->ultimo != NULL)
    {
        q->ultimo->sig = aux;
        q->ultimo = aux;
    }
    else
    {
        q->primero = aux;
        q->ultimo = aux;
    }
    q->suma += x;
    return q;
}

queue eliminar(queue q)
{
    // Elimina el primer q y libera la memoria reservada
    if (q->primero != NULL && q->ultimo != NULL)
    {
        cola aux = q->primero;
        q->primero = q->primero->sig;
        if (q->primero == NULL)
        {
            q->ultimo = NULL;
        }
        q->suma = q->suma - aux->dato;
        delete (aux);
    }
    return q;
}