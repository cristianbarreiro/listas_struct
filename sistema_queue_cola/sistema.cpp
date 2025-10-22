#include "sistema.h"

struct nodo_queue
{
    cola first;
    cola last;
};

struct nodo_cola
{
    int dato;
    cola sig;
};

queue crear_queue()
{
    queue aux = new (nodo_queue);
    aux->first = NULL;
    aux->last = NULL;
    return aux;
}

bool vacia_queue(queue q)
{
    return (q->first == NULL && q->last == NULL);
}

bool vacia_cola(cola c)
{
    return (c == NULL);
}

queue enqueue(queue q, int x)
{
    cola aux = new (nodo_cola);
    aux->dato = x;
    aux->sig = NULL;
    if (vacia_queue(q))
    {
        q->first = aux;
        q->last = aux;
    }
    else
    {
        q->last->sig = aux;
        q->last = aux;
    }
    return q;
}

int primero(queue q)
{
    // pre: !vacio_queue(q)
    return q->first->dato;
}

int ultimo(queue q)
{
    // pre: !vacio_queue(q)
    return q->last->dato;
}

queue dequeue(queue q)
{
    // pos: elimina el primer elemento de la queue
    // y libera la memoria
    if (!vacia_queue(q))
    {
        if (q->first == q->last)
        {
            delete q->first;
            q->first = NULL;
            q->last = NULL;
        }
        else
        {
            cola aux = q->first;
            q->first = q->first->sig;
            delete aux;
        }
    }
    return q;
}

queue destruir_queue(queue q)
{
    if (!vacia_queue(q))
    {
        q->first = destruir_cola(q->first);
    }
    delete (q);
    q = NULL;
    return q;
}

cola destruir_cola(cola c)
{
    // pos: elimina todos los elementos  y libera la memoria
    if (vacia_cola(c))
    {
        return c;
    }
    else
    {
        c->sig = destruir_cola(c->sig);
        delete (c);
        return NULL;
    }
}

cola destruir_cola_iter(cola c)
{
    // pos: elimina todos los elementos  y libera la memoria (iterativa)
    if (vacia_cola(c))
    {
        return c;
    }
    else
    {
        while (c != NULL)
        {
            cola aux = c;
            c = c->sig;
            delete aux;
        }
        return NULL;
    }
}

void destruir(cola &c)
{
    if (!vacia_cola(c))
    {
        c = destruir_cola(c->sig);
        delete (c);
        c = NULL;
    }
}
