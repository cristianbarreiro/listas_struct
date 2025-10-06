#include "listacirc.h"

listacirc crear()
{
    // crea una lista circular vacia
    return NULL;
}

listacirc cons(listacirc l, int n)
{
    // inserta n al principio de la lista circular
    listacirc aux = new (nodo_listacirc);
    aux->dato = n;
    if (l == NULL)
    {
        aux->sig = aux;
    }
    else
    {
        listacirc iter = l;
        while (iter->sig != l)
        {
            iter = iter->sig;
        }
        iter->sig = aux;
        aux->sig = l;
    }
    return aux;
}

listacirc snoc(listacirc l, int n)
{
    // inserta n al final de la lista circular
    listacirc aux = new (nodo_listacirc);
    aux->dato = n;
    if (l == NULL)
    {
        aux->sig = aux;
    }
    else
    {
        listacirc iter = l;
        while (iter->sig != l)
        {
            iter = iter->sig;
        }
        iter->sig = aux;
        aux->sig = l;
    }
    return l;
}

bool vacia(listacirc l)
{
    return (l == NULL);
}

int contar(listacirc l)
{
    // retorna la cantidad de elementos de la lista circular
    int cont = 0;
    if (l != NULL)
    {
        listacirc iter = l;
        while (iter->sig != l)
        {
            cont++;
            iter = iter->sig;
        }
        cont++;
    }
    return cont;
}

bool pertenece(listacirc l, int n)
{
    // retorna true si n pertenece a la lista circular
    bool esta = false;
    if (l != NULL)
    {
        listacirc iter = l;
        while (iter->sig != l && !esta)
        {
            if (iter->dato == n)
            {
                esta = true;
            }
            else
            {
                iter = iter->sig;
            }
        }
        if (!esta)
        {
            if (iter->dato == n)
            {
                esta = true;
            }
        }
    }
    return esta;
}

listacirc eliminar(listacirc l, int n)
{
    // elimina la primera ocurrencia de n en la lista circular
    if (l == NULL)
        return NULL;

    listacirc actual = l;
    listacirc anterior = NULL;

    // caso especial: lista de un solo elemento
    if (l->sig == l)
    {
        if (l->dato == n)
        {
            delete l;
            return NULL;
        }
        else
        {
            return l;
        }
    }

    // buscar el nodo a eliminar
    do
    {
        if (actual->dato == n)
        {
            if (anterior == NULL)
            {
                // eliminar el primer nodo
                listacirc ultimo = l;
                while (ultimo->sig != l)
                    ultimo = ultimo->sig;
                ultimo->sig = l->sig;
                listacirc aux = l;
                l = l->sig;
                delete aux;
                return l;
            }
            else
            {
                anterior->sig = actual->sig;
                delete actual;
                return l;
            }
        }
        anterior = actual;
        actual = actual->sig;
    } while (actual != l);

    return l;
}

listacirc destruir(listacirc l)
{
    // elimina todos los nodos de la lista circular y libera memoria
    if (l == NULL)
    {
        return NULL;
    }
    else
    {
        listacirc iter = l;
        while (iter->sig != l)
        {
            listacirc aux = iter->sig;
            iter->sig = iter->sig->sig;
            delete (aux);
        }
        delete (l);
    }
    return NULL;
}