#include "recursivo.h"

struct nodo_lista
{
    int dato;
    lista sig;
};

lista Null()
{
    // crear una lista de enteros Null
    return NULL;
}

bool isEmpty(lista l)
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

void Show(lista l, int &cont)
{
    if (cont == 0)
    {
        printf("(");
        cont++;
    }
    if (isEmpty(l))
    {
        printf(")\n");
        return;
    }
    printf("%d", Head(l));
    if (!isEmpty(Tail(l)))
    {

        printf(", ");
        Show(Tail(l), cont);
    }
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
    if (isEmpty(l))
    {
        return cons(l, n);
    }
    else
    {
        return cons(snoc(Tail(l), n), Head(l));
    }
}

lista Insert(lista l, int n)
{
    // Inserta ordenadamente el elemento n en la lista ordenada l de forma recursiva.
    if (isEmpty(l) || n <= l->dato)
    {
        return cons(l, n);
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = Insert(l->sig, n);
        return nuevo;
    }
}

bool IsElement(lista l, int n)
{
    if (isEmpty(l))
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

int HowMany(lista l, int n)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else if (Head(l) == n)
    {
        return 1 + HowMany(Tail(l), n);
    }
    else
    {
        return HowMany(Tail(l), n);
    }
}

int Length(lista l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + Length(Tail(l));
    }
}

int Last(lista l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else if (l->sig == NULL)
    {
        return l->dato;
    }
    else
    {
        return Last(Tail(l));
    }
}

int Max(lista l)
{
    if (isEmpty(l))
    {
        return 0; // O un valor mínimo adecuado según tu contexto
    }
    else if (l->sig == NULL)
    {
        return l->dato;
    }
    else
    {
        int maxTail = Max(l->sig);
        return (l->dato > maxTail) ? l->dato : maxTail;
    }
}

float Average(lista l)
{
    if (isEmpty(l))
    {

        return 0;
    }
    return (float)Sum(l) / Length(l);
}

// Función auxiliar para sumar los elementos
int Sum(lista l)
{
    if (isEmpty(l))
    {

        return 0;
    }
    return Head(l) + Sum(Tail(l));
}

bool IsSorted(lista l)
{
    if (l == NULL || l->sig == NULL)
    {
        return true;
    }
    if (l->dato > l->sig->dato)
    {
        return false;
    }
    return IsSorted(l->sig);
}

lista Quitar(lista l, int n)
{
    // Devuelve una nueva lista sin el elemento n
    if (isEmpty(l))
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

lista Remove(lista l, int n)
{
    // Elimina todas las ocurrencias de n en la lista l de forma recursiva y devuelve una copia
    if (isEmpty(l))
    {
        return NULL;
    }
    if (Head(l) == n)
    {
        return Remove(Tail(l), n);
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = Head(l);
        nuevo->sig = Remove(Tail(l), n);
        return nuevo;
    }
}

lista Delete(lista l)
{
    // elimina los elementos de la lista y libera la memoria de forma recursiva
    if (isEmpty(l))
    {
        return NULL;
    }
    lista sig = l->sig;
    delete l;
    return Delete(sig);
}

lista Change(int x, int y, lista l)
{
    // Retorna una nueva lista fruto de cambiar x por y en l.
    // l no comparte memoria con la lista resultado.
    if (isEmpty(l))
    {
        return NULL;
    }
    else
    {
        lista aux = new (nodo_lista);
        if (Head(l) == x)
        {
            aux->dato = y;
        }
        else
        {
            aux->dato = Head(l);
        }
        aux->sig = Change(x, y, Tail(l));
        return nuevo;
    }
}

lista insOrd(int x, lista l)
{
    // hace lo mismo que Insert practicamente
    if (isEmpty(l))
    {
        return cons(l, x);
    }
    else if (x <= Head(l))
    {
        return cons(l, x);
    }
    else
    {
        return cons(insOrd(x, Tail(l)), Head(l));
    }
}
lista InsBefore(int x, int y, lista l)
{
    // Retorna una nueva lista fruto de insertar x antes de y en l.
    // l no comparte memoria con la lista resultado.
    if (isEmpty(l))
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
    if (isEmpty(l))
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

bool Equals(lista l, lista p)
{
    if (isEmpty(l) && isEmpty(p))
    {
        return true;
    }
    else if (isEmpty(l) || isEmpty(p))
    {
        return false;
    }
    else if (l->dato != p->dato)
    {
        return false;
    }
    else
    {
        return Equals(l->sig, p->sig);
    }
}

lista Merge(lista l, lista p)
{
    // retorna una nueva lista con los elementos de l y p intercalados de menor a mayor
    // la nueva lista no comparte memoria ni con l ni con p
    if (isEmpty(l) && isEmpty(p))
    {
        return NULL;
    }
    else if (isEmpty(p))
    {
        lista aux = new (nodo_lista);
        aux->dato = l->dato;
        aux->sig = Merge(l->sig, NULL);
        return aux;
    }
    else if (isEmpty(l))
    {
        lista aux = new (nodo_lista);
        aux->dato = p->dato;
        aux->sig = Merge(NULL, p->sig);
        return aux;
    }
    else
    {
        lista aux = new (nodo_lista);
        if (l->dato < p->dato)
        {
            aux->dato = l->dato;
            aux->sig = Merge(l->sig, p);
        }
        else
        {
            aux->dato = p->dato;
            aux->sig = Merge(l, p->sig);
        }
        return aux;
    }
}

lista Append(lista l, lista p)
{
    // Agrega la lista p al final de la lista l.
    // l y p no comparten memoria con la lista resultado.

    if (isEmpty(l) && isEmpty(p))
    {
        return NULL;
    }
    else if (isEmpty(l))
    {
        lista aux = new (nodo_lista);
        aux->dato = p->dato;
        aux->sig = Append(NULL, p->sig);
        return aux;
    }
    else
    {
        lista aux = new (nodo_lista);
        aux->dato = l->dato;
        aux->sig = Append(l->sig, p);
        return aux;
    }
}

lista Take(int i, lista l)
{
    // Retorna la lista resultado de tomar los primeros i elementos.
    // l no comparte memoria con la lista resultado.
    // PRE: i >= 0

    if (i <= 0 || isEmpty(l))
    {
        return NULL;
    }

    lista nuevo = new (nodo_lista);
    nuevo->dato = l->dato;
    nuevo->sig = Take(i - 1, l->sig);
    return nuevo;
}

lista Drop(int u, lista l)
{
    // Retorna la lista resultado de no tomar los primeros u elementos.
    // l no comparte memoria con la lista resultado.
    // PRE: u >= 0

    if (isEmpty(l))
    {
        return NULL;
    }

    if (u > 0)
    {
        return Drop(u - 1, l->sig);
    }
    else
    {
        lista nuevo = new (nodo_lista);
        nuevo->dato = l->dato;
        nuevo->sig = Drop(0, l->sig);
        return nuevo;
    }
}
