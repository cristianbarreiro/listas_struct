#include "recursivo.h"

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

bool Null(lista l)
{
    // retorna true si l es Null
    return (l == NULL);
}

int Head(lista l)
{
    // Devuelve el valor del primer nodo de la lista.
    // PRECONDICIÓN: la lista no debe ser vacía.
    return l->dato;
}

lista Tail(lista l)
{
    // Devuelve la sublista que comienza después del primer nodo.
    // PRECONDICIÓN: la lista no debe ser vacía.
    return l->sig;
}

void printList(lista l)
{
    while (l != NULL)
    {
        printf("%d ", l->dato);
        l = l->sig;
    }
    printf("\n");
}

lista cons(lista l, int n)
{
    // agrega n al principio de la lista
    lista aux = new (nodo_lista);
    aux->dato = n;
    aux->sig = l;
    return aux;
}

void Show(lista l)
{
    // Muestra los elementos de la lista l separados por comas.
    if (Null(l))
    {
        printf("\n");
        return;
    }
    printf("%d", l->dato);
    if (l->sig != NULL)
    {
        printf(", ");
        Show(l->sig);
    }
    else
    {
        printf("\n");
    }
}

lista snocRecursivo(lista l, int n)
{
    // lista n al final de la lista
    if (Null(l))
    {
        return cons(l, n);
    }
    else
    {
        return cons(snocRecursivo(Tail(l), n), Head(l));
    }
}

lista InsertRecursivo(lista l, int n)
{
    // Inserta ordenadamente el elemento n en la lista ordenada l de forma recursiva.
    if (Null(l) || n <= l->dato)
    {
        return cons(l, n);
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = InsertRecursivo(l->sig, n);
        return nuevo;
    }
}

bool IsElement(lista l, int n)
{
    if (Null(l))
    {
        return false;
    }
    else
    {
        if (Head(l) == n)
        {
            return true;
        }
        else
        {
            return IsElement(Tail(l), n);
        }
    }
}

int HowMany(int x, lista l)
{
    if (Null(l))
    {
        return 0;
    }
    else if (Head(l) == x)
    {
        return 1 + HowMany(x, Tail(l));
    }
    else
    {
        return HowMany(x, Tail(l));
    }
}

int Length(lista l)
{
    if (Null(l))
    {
        return 0;
    }
    else
    {
        return 1 + Length(Tail(l));
    }
}

int LengthRecursivo(lista l)
{
    if (l == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + LengthRecursivo(l->sig);
    }
}

int LastRecursivo(lista l)
{
    if (Null(l))
    {
        return 0;
    }
    else if (l->sig == NULL)
    {
        return l->dato;
    }
    else
    {
        return LastRecursivo(l->sig);
    }
}

int MaxRecursivo(lista l)
{
    if (Null(l))
    {
        return 0; // O un valor mínimo adecuado según tu contexto
    }
    else if (l->sig == NULL)
    {
        return l->dato;
    }
    else
    {
        int maxTail = MaxRecursivo(l->sig);
        return (l->dato > maxTail) ? l->dato : maxTail;
    }
}

float AverageRecursivo(lista l)
{
    // Calcula el promedio de los elementos de la lista de forma recursiva
    if (Null(l))
    {
        return 0;
    }
    else
    {
        // Suma todos los elementos y divide por la cantidad
        int suma = l->dato + (int)AverageRecursivo(l->sig) * LengthRecursivo(l->sig);
        int cantidad = 1 + LengthRecursivo(l->sig);
        return (float)suma / cantidad;
    }
}

bool IsSortedRecursivo(lista l)
{
    if (l == NULL || l->sig == NULL)
    {
        return true;
    }
    if (l->dato > l->sig->dato)
    {
        return false;
    }
    return IsSortedRecursivo(l->sig);
}

lista Quitar(lista l, int n)
{
    // devuelve una nueva lista sin el elem n
    if (Null(l))
    {
        return l;
    }
    else
    {
        if (Head(l) == n)
        {
            return Tail(l);
        }
        else
        {
            return cons(Quitar(Tail(l), n), Head(l));
        }
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

lista DeleteRecursivo(lista l)
{
    // elimina los elementos de la lista y libera la memoria de forma recursiva
    if (l == NULL)
    {
        return NULL;
    }
    lista sig = l->sig;
    delete l;
    return DeleteRecursivo(sig);
}

lista Change(int x, int y, lista l)
{
    // Retorna una nueva lista fruto de cambiar x por y en l.
    // l no comparte memoria con la lista resultado.
    if (Null(l))
    {
        return NULL;
    }
    else
    {
        lista nuevo = new (nodo_lista);
        if (l->dato == x)
        {
            nuevo->dato = y;
        }
        else
        {
            nuevo->dato = l->dato;
        }
        nuevo->sig = Change(x, y, l->sig);
        return nuevo;
    }
}

lista InsBefore(int x, int y, lista l)
{
    // Retorna una nueva lista fruto de insertar x antes de y en l.
    // l no comparte memoria con la lista resultado.
    if (Null(l))
    {
        return NULL;
    }
    else if (l->dato == y)
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = x;
        nuevo->sig = new (nodo_lista);
        nuevo->sig->dato = l->dato;
        nuevo->sig->sig = InsBefore(x, y, l->sig);
        return nuevo;
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = InsBefore(x, y, l->sig);
        return nuevo;
    }
}

lista InsAround(int x, int y, lista l)
{
    // Retorna una nueva lista fruto de insertar x antes y después de y en l.
    // l no comparte memoria con la lista resultado.
    if (Null(l))
    {
        return NULL;
    }
    else if (l->dato == y)
    {
        lista antes = new (nodo_lista);
        antes->dato = x;
        antes->sig = new (nodo_lista);
        antes->sig->dato = l->dato;
        antes->sig->sig = new (nodo_lista);
        antes->sig->sig->dato = x;
        antes->sig->sig->sig = InsAround(x, y, l->sig);
        return antes;
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = InsAround(x, y, l->sig);
        return nuevo;
    }
}

bool EqualsRecursivo(lista l, lista p)
{
    if (Null(l) && Null(p))
    {
        return true;
    }
    else if (Null(l) || Null(p))
    {
        return false;
    }
    else if (l->dato != p->dato)
    {
        return false;
    }
    else
    {
        return EqualsRecursivo(l->sig, p->sig);
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
