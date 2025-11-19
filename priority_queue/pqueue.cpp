#include "pqueue.h"

struct nodo_cola
{
    int dato;
    unsigned int prioridad;
    struct nodo_cola *sig;
};

// Primero / vacío (opcional, pero típico del curso)
int pqueue_first(pqueue q)
// PRE: q no vacía
{
    return q->dato;
}

bool pqueue_empty(pqueue q)
{
    return (q == NULL);
}

// Inserción con prioridad (O(n))
pqueue pqueue_insert(pqueue q, int x, unsigned int p)
{
    struct nodo_cola *nuevo = new (nodo_cola);
    nuevo->dato = x;
    nuevo->prioridad = p;
    nuevo->sig = NULL;

    // Inserta al principio si está vacía o tiene mayor prioridad
    if (q == NULL || q->prioridad > p)
    {
        nuevo->sig = q;
        return nuevo;
    }

    // Busca la posición correcta
    pqueue aux = q;
    while (aux->sig != NULL && aux->sig->prioridad <= p)
    {
        aux = aux->sig;
    }

    nuevo->sig = aux->sig;
    aux->sig = nuevo;
    return q;
}

// Borrado del elemento de mayor prioridad (O(1))
pqueue pqueue_delete(pqueue q)
{
    if (q == NULL)
        return NULL;

    pqueue aux = q;
    q = q->sig;
    delete aux;
    return q;
}

// Liberar toda la cola (O(n))
pqueue pqueue_destroy(pqueue q)
{
    if (q != NULL)
    {
        q->sig = pqueue_destroy(q->sig);
        delete q;
    }
    return NULL;
}
