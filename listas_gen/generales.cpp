#include "generales.h"
// Definición de la estructura nodo_lista y nodo_listagral (por compatibilidad)

struct nodo_listagral
{
    lista dato;
    listagral sig;
};

// Crea la lista general vacía
listagral Null()
{
    return NULL;
}

// Inserta la lista elemento l al principio de la lista general lg
listagral ConsLG(listagral lg, lista l)
{
    listagral aux = new nodo_listagral;
    aux->dato = l;
    aux->sig = lg;
    return aux;
}

bool isEmpty(lista l)
{
    // retorna true si l es Null
    return (l == NULL);
}

// Verifica si la lista general está vacía
bool IsEmptyLG(listagral lg)
{
    return lg == NULL;
}

int Head(lista l)
{
    // Devuelve el valor del primer nodo de la lista.
    // PRECONDICIÓN: la lista no debe ser vacía.
    return l->dato;
}

// Retorna la primer lista elemento. Pre: lg no vacía
lista HeadLG(listagral lg)
{
    return lg->dato;
}

lista Tail(lista l)
{
    // Devuelve la sublista que comienza después del primer nodo.
    // PRECONDICIÓN: la lista no debe ser vacía.
    return l->sig;
}

// Retorna lg sin su primer elemento. Pre: lg no vacía
listagral TailLG(listagral lg)
{
    return lg->sig;
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

// Retorna la cantidad de naturales de la lista general lg (recursivo)
int LengthLG(listagral lg)
{
    if (IsEmptyLG(lg))
    {
        return 0;
    }
    else
    {
        return Length(HeadLG(lg)) + LengthLG(TailLG(lg));
    }
}

void Show(lista l)
{
    // imprime los elementos separados por comas con paréntesis al principio y final
    if (isEmpty(l))
    {
        printf(")");
    }
    else
    {
        printf("%d", Head(l));
        Show(Tail(l));
    }
}

void ShowLG(listagral lg)
{
    // imprime las listas con sus enteros separadas por comas
    if (!IsEmptyLG(lg))
    {
        Show(HeadLG(lg));
        printf(", ");
        ShowLG(TailLG(lg));
    }
}
