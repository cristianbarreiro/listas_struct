#include "iterativo.h"

struct nodo_lista
{
    int dato;
    lista sig;
};

lista crear()
{
    // crear una lista de enteros Null
    return NULL;
}

lista cons(lista l, int n)
{
    // agrega n al principio de la lista
    lista aux = new (nodo_lista);
    aux->dato = n;
    aux->sig = l;
    return aux;
}

lista snoc(lista l, int n)
{
    // lista n al final de la lista
    if (Null(l))
    {
        return cons(l, n);
    }
    else
    {
        return cons(snoc(tail(l), n), head(l));
    }
}

bool Null(lista l)
{
    // retorna true si l es Null
    return (l == NULL);
}

bool IsElement(lista l, int n)
{
    if (Null(l))
    {
        return false;
    }
    else
    {
        if (head(l) == n)
        {
            return true;
        }
        else
        {
            return IsElement(tail(l), n);
        }
    }
}

int contar(lista l)
{
    if (Null(l))
    {
        return 0;
    }
    else
    {
        return 1 + contar(tail(l));
    }
}

lista quitar(lista l, int n)
{
    // devuelve una nueva lista sin el elem n
    if (Null(l))
    {
        return l;
    }
    else
    {
        if (head(l) == n)
        {
            return tail(l);
        }
        else
        {
            return cons(quitar(tail(l), n), head(l));
        }
    }
}

void imprimir(lista l)
{
    while (l != NULL)
    {
        printf("%d ", l->dato);
        l = l->sig;
    }
    printf("\n");
}

lista destruir(lista l)
{
    // elimina los elementos de la lista y libera la memoria
    lista dest;

    while (l != NULL)
    {
        dest = l;
        l = l->sig;
        delete (dest);
    }
    return NULL; // return l
}

int head(lista l)
{
    // Devuelve el valor del primer nodo de la lista.
    // PRECONDICIÓN: la lista no debe ser vacía.
    return l->dato;
}

lista tail(lista l)
{
    // Devuelve la sublista que comienza después del primer nodo.
    // PRECONDICIÓN: la lista no debe ser vacía.
    return l->sig;
}

int Length(lista l)
{
    if (Null(l))
    {
        return 0;
    }
    else
    {
        int suma = 0;
        while (l != NULL)
        {
            suma++;
            l = l->sig;
        }
        return suma;
    }
}

int Last(lista l)
{
    if (Null(l))
    {
        return 0;
    }
    else
    {
        while (l->sig != NULL)
        {
            l = l->sig;
        }
        return l->dato;
    }
}

int Max(lista l)
{
    // Retorna el máximo elemento de l.
    // Pre: l no es vacía.

    int mayor = l->dato;
    l = l->sig;
    while (l != NULL)
    {
        if (l->dato > mayor)
        {
            mayor = l->dato;
        }
        l = l->sig;
    }
    return mayor;
}

float Average(lista l)
{
    // Retorna si la lista no es vacía el promedio de sus elementos.
    // Pre: l no es vacía.

    int length = Length(l);
    int suma = 0;
    lista temp = l;

    while (temp != NULL)
    {
        suma += temp->dato;
        temp = temp->sig;
    }

    return (float)suma / length;
}

lista Insert(lista l, int n)
{
    // Inserta ordenadamente el elemento n en la lista ordenada l.
    if (Null(l) || n <= l->dato)
    {

        return cons(l, n);
    }
    else
    {

        lista actual = l;
        lista anterior = NULL;

        while (actual != NULL && n > actual->dato)
        {
            anterior = actual;
            actual = actual->sig;
        }

        lista nuevo = new nodo_lista;
        nuevo->dato = n;
        nuevo->sig = actual;

        anterior->sig = nuevo;

        return l;
    }
}

lista Remove(lista l, int n)
{
    // Elimina todas las ocurrencias de n en la lista l
    // Eliminar todas las apariciones de n al comienzo
    while (l != NULL && l->dato == n)
    {
        lista temp = l;
        l = l->sig;
        delete temp;
    }

    // Recorremos el resto
    lista actual = l;
    while (actual != NULL && actual->sig != NULL)
    {
        if (actual->sig->dato == n)
        {
            lista temp = actual->sig;
            actual->sig = actual->sig->sig;
            delete temp;
        }
        else
        {
            actual = actual->sig;
        }
    }

    return l;
}

bool Equals(lista l, lista p)
{
    if (Null(l) && Null(p))
    {
        return true;
    }
    else
    {
        while (l != NULL && p != NULL)
        {
            if (l->dato != p->dato)
            {
                return false;
            }
            l = l->sig;
            p = p->sig;
        }

        return l == NULL && p == NULL;
    }
}

lista Drop(lista l, int i)
{
    // retorna una lista sin los primeros i nodos de l
    // la lista resultado no comparte memoria con l
    // PRE: i >= 0

    while (i > 0 && l != NULL)
    {
        l = l->sig;
        i--;
    }

    lista ret = NULL;
    lista iter;
    while (l != NULL)
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = NULL;

        if (ret == NULL)
        {
            ret = nuevo;
            iter = ret;
        }
        else
        {
            iter->sig = nuevo;
            iter = iter->sig;
        }
        l = l->sig;
    }
    return ret;
}

lista Take(lista l, int n)
{
    // retorna una lista con los primeros n nodos de l
    // la lista resultado no comparte memoria con l
    // PRE: n >= 0

    lista ret = NULL;
    lista iter;
    int cont = 0;

    while (l != NULL && cont < n)
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = NULL;

        if (ret == NULL)
        {
            ret = nuevo;
            iter = ret;
        }
        else
        {
            iter->sig = nuevo;
            iter = iter->sig;
        }

        l = l->sig;
        cont++;
    }

    return ret;
}

lista Merge(lista l, lista p)
{
    // Intercala l y p en forma ordenada, retornando una lista que no comparte memoria
    // Pre: l y p ordenadas
    lista aux;
    lista m = crear();
    lista ultimo = NULL;
    while (l != NULL && p != NULL)
    {
        aux = new (nodo_lista);
        aux->sig = NULL;
        if (l->dato < p->dato)
        {
            aux->dato = l->dato;
            l = l->sig;
        }
        else
        {
            aux->dato = p->dato;
            p = p->sig;
        }
        if (m == NULL)
        {
            m = aux;
            ultimo = aux;
        }
        else
        {
            ultimo->sig = aux;
            ultimo = aux;
        }
    }

    while (l != NULL)
    {
        aux = new (nodo_lista);
        aux->dato = l->dato;
        aux->sig = NULL;
        if (m == NULL)
        {
            m = aux;
            ultimo = aux;
        }
        else
        {
            ultimo->sig = aux;
            ultimo = aux;
        }
        l = l->sig;
    }
    while (p != NULL)
    {
        aux = new (nodo_lista);
        aux->dato = p->dato;
        aux->sig = NULL;
        if (m == NULL)
        {
            m = aux;
            ultimo = aux;
        }
        else
        {
            ultimo->sig = aux;
            ultimo = aux;
        }
        p = p->sig;
    }
    return m;
}

lista Append(lista l, lista p)
{
    // retorna una nueva lista con los nodos de l y p
    // la lista resultado no comparte memoria ni con l ni con p

    lista ret = NULL;
    lista iter;

    while (l != NULL)
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = NULL;

        if (ret == NULL)
        {
            ret = nuevo;
            iter = ret;
        }
        else
        {
            iter->sig = nuevo;
            iter = iter->sig;
        }
        l = l->sig;
    }

    while (p != NULL)
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = p->dato;
        nuevo->sig = NULL;

        if (ret == NULL)
        {
            ret = nuevo;
            iter = ret;
        }
        else
        {
            iter->sig = nuevo;
            iter = iter->sig;
        }
        p = p->sig;
    }

    return ret;
}

lista TakeRecursivo(int i, lista l)
{
    // Retorna la lista resultado de tomar los primeros i elementos.
    // l no comparte memoria con la lista resultado.
    // PRE: i >= 0

    if (i <= 0 || l == NULL)
    {
        return NULL;
    }

    lista nuevo = new (nodo_lista);
    nuevo->dato = l->dato;
    nuevo->sig = TakeRecursivo(i - 1, l->sig);
    return nuevo;
}

lista DropRecursivo(int u, lista l)
{
    // Retorna la lista resultado de no tomar los primeros u elementos.
    // l no comparte memoria con la lista resultado.
    // PRE: u >= 0

    if (l == NULL)
    {
        return NULL;
    }

    if (u > 0)
    {
        return DropRecursivo(u - 1, l->sig);
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = DropRecursivo(0, l->sig);
        return nuevo;
    }
}

lista MergeRecursivo(lista l, lista p)
{
    // retorna una nueva lista con los elementos de l y p intercalados de menor a mayor
    // la nueva lista no comparte memoria ni con l ni con p
    if (l == NULL && p == NULL)
    {
        return NULL;
    }
    else if (p == NULL)
    {
        lista aux = new (nodo_lista);
        aux->dato = l->dato;
        aux->sig = MergeRecursivo(l->sig, NULL);
        return aux;
    }
    else if (l == NULL)
    {
        lista aux = new (nodo_lista);
        aux->dato = p->dato;
        aux->sig = MergeRecursivo(NULL, p->sig);
        return aux;
    }
    else
    {
        lista aux = new (nodo_lista);
        if (l->dato < p->dato)
        {
            aux->dato = l->dato;
            aux->sig = MergeRecursivo(l->sig, p);
        }
        else
        {
            aux->dato = p->dato;
            aux->sig = MergeRecursivo(l, p->sig);
        }
        return aux;
    }
}

lista AppendRecursivo(lista l, lista p)
{
    // Agrega la lista p al final de la lista l.
    // l y p no comparten memoria con la lista resultado.

    if (l == NULL && p == NULL)
    {
        return NULL;
    }
    else if (l == NULL)
    {
        lista aux = new (nodo_lista);
        aux->dato = p->dato;
        aux->sig = AppendRecursivo(NULL, p->sig);
        return aux;
    }
    else
    {
        lista aux = new (nodo_lista);
        aux->dato = l->dato;
        aux->sig = AppendRecursivo(l->sig, p);
        return aux;
    }
}

lista RemoveRecursivo(lista l, int n)
{
    // Elimina todas las ocurrencias de n en la lista l de forma recursiva y devuelve una copia
    if (l == NULL)
    {
        return NULL;
    }
    if (l->dato == n)
    {
        return RemoveRecursivo(l->sig, n);
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = RemoveRecursivo(l->sig, n);
        return nuevo;
    }
}
