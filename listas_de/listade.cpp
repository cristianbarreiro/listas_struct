#include "listade.h"

struct nodo_listade
{
    int dato;
    listade sig;
    listade ant;
};

listade Null()
{
    // Crea la lista doblemente encadenada vacia.
    return NULL;
}

bool isEmpty(listade l)
{
    // Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

listade cons(listade l, int n)
{
    // Inserta n al inicio de l.
    listade aux = new (nodo_listade);
    aux->dato = n;
    aux->ant = NULL;
    if (isEmpty(l))
    {
        aux->sig = NULL;
        return aux;
    }
    else
    {
        listade iter = l;
        while (iter->ant != NULL)
            iter = iter->ant;
        iter->ant = aux;
        aux->sig = iter;
        return l;
    }
}

listade snoc(listade l, int n)
{
    // Inserta n al final de l.
    listade aux = new (nodo_listade);
    aux->dato = n;
    aux->sig = NULL;
    if (isEmpty(l))
    {
        aux->ant = NULL;
        return aux;
    }
    else
    {
        listade iter = l;
        while (iter->sig != NULL)
            iter = iter->sig;
        iter->sig = aux;
        aux->ant = iter;
        return l;
    }
}

listade insOrd(listade l, int n)
{
    // Inserta ordenadamente en l.
    // Pre: l ordenada.
    listade aux = new (nodo_listade);
    aux->dato = n;
    if (isEmpty(l))
    {
        aux->ant = NULL;
        aux->sig = NULL;
        return aux;
    }
    else
    {
        listade iter = l;
        while (iter->ant != NULL)
            iter = iter->ant;
        while ((iter->sig != NULL) && (n > iter->dato))
            iter = iter->sig;
        if (n < iter->dato)
        {
            aux->sig = iter;
            aux->ant = iter->ant;
            iter->ant = aux;
            if (aux->ant != NULL)
                aux->ant->sig = aux;
        }
        else
        {
            aux->sig = NULL;
            aux->ant = iter;
            iter->sig = aux;
        }
        return l;
    }
}

int cant(listade l)
{
    // Retorna la cantidad de elementos de l.
    if (isEmpty(l))
        return 0;
    else
        return 1 + cant_ant(l->ant) + cant_sig(l->sig);
}

int cant_ant(listade l)
{
    // Retorna la cantidad de elementos de l.
    if (isEmpty(l))
        return 0;
    else
        return 1 + cant_ant(l->ant);
}

int cant_sig(listade l)
{
    // Retorna la cantidad de elementos de l.
    if (isEmpty(l))
        return 0;
    else
        return 1 + cant_sig(l->sig);
}

bool pertenece(listade l, int n)
{
    // Retorna true si n pertenece a l, false en caso contrario.
    if (isEmpty(l))
        return false;
    else
    {
        while (l->ant != NULL)
            l = l->ant;
        while ((l != NULL) && (l->dato != n))
            l = l->sig;
        if (l == NULL)
            return false;
        else
            return true;
    }
}

int primero(listade l)
{
    // Retorna el primer elemento de la lista.
    // Pre: l no vacía.
    if (isEmpty(l))
        return 0; // o lanzar error
    while (l->ant != NULL)
        l = l->ant;
    return l->dato;
}

int ultimo(listade l)
{
    // Retorna el último elemento de la lista.
    // Pre: l no vacía.
    if (isEmpty(l))
        return 0; // o lanzar error
    while (l->sig != NULL)
        l = l->sig;
    return l->dato;
}

int actual(listade l)
{
    // Retorna el elemento "actual" de la lista.
    // Pre: l no vacia.
    return l->dato;
}

listade ant(listade l)
{
    // Retorna los "anteriores" al nodo actual de la lista.
    // Pre: l no vacia.
    return l->ant;
}

listade sig(listade l)
{
    // Retorna los "siguientes" al nodo actual de la lista.
    // Pre: l no vacia.
    return l->sig;
}

listade eliminar(listade l, int n)
{
    // elimina el nodo con valor n, en la lita l y libera memoria
    if (isEmpty(l))
    {
        return NULL;
    }
    else
    {
        listade iter = l;
        while (iter->ant != NULL)
        {
            iter = iter->ant;
        }
        while (iter->dato != n && iter->sig != NULL)
        {
            iter = iter->sig;
        }
        if (iter->sig == NULL)
        {
        }
    }
}

listade destruir(listade l)
{
    // elimina todos los nodos de la lista y libera la mem
    if (isEmpty(l))
    {
        return NULL;
    }
    else
    {
        while (l->ant != NULL)
        {
            l = l->ant;
        }
        while (l != NULL)
        {
            listade actual = l;
            l = l->sig;
            delete (actual);
        }
        return NULL;
    }
}

void imprimir(listade l)
{
    // imprime los elementos de la lista comenzando en el elemento
    // cuyo anterior es NULL
    if (!isEmpty(l))
    {
        while (l->ant != NULL)
        {
            l = l->ant;
        }
        while (l != NULL)
        {
            printf("%d ", l->dato);
            l = l->sig;
        }
        printf("\n");
    }
}

/**
 * @brief Imprime los elementos de una lista doblemente enlazada en orden invertido.
 *
 * Esta función recorre la lista doblemente enlazada hasta el último nodo
 * y luego imprime los datos de cada nodo desde el final hasta el principio,
 * separados por espacios. Al finalizar, imprime un salto de línea.
 *
 * @param l Puntero al primer nodo de la lista doblemente enlazada.
 */

void imprimirInvertido(listade l)
{

    if (!isEmpty(l))
    {
        while (l->sig != NULL)
        {
            l = l->sig;
        }
        while (l != NULL)
        {
            printf("%d ", l->dato);
            l = l->ant;
        }
        printf("\n");
    }
}