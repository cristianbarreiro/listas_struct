#include "practica.h"

typedef nodo_arbol *abb;

struct nodo_arbol
{
    int dato;
    abb ph;
    abb sh;
};

abb subizq(abb a)
{
    // pos: retorna el subárbol izquierdo
    // pre: ab no vacía
    return a->ph;
}

abb subder(abb a)
{
    // pos: retorna el subárbol derecho
    // pre: ab no vacío
    return a->sh;
}

bool vacio(abb a)
{
    return (a == NULL);
}

int maximo(abb a)
{
    // Retorne el máximo de a
    // PRE: a no es vacío
    while (a->sh != NULL)
    {
        a = a->sh;
    }
    return a->dato;
}

int suma(abb a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return a->dato + suma(a->ph) + suma(a->sh);
    }
}

int sumaMayoresQueK(abb a, int k)
{
    if (a == NULL)
    {
        return 0;
    }
    else if (a->dato > k)
    {
        return a->dato + sumaMayoresQueK(a->ph, k) + sumaMayoresQueK(a->sh, k);
    }
    else
    {
        return sumaMayoresQueK(a->ph, k) + sumaMayoresQueK(a->sh, k);
    }
}

int profundidad(abb a)
{
    // pos: retorna la profundidad máxima del árbol
    if (vacio(a))
    {
        return 0;
    }
    else
    {
        int profIzq = profundidad(subizq(a));
        int profDer = profundidad(subder(a));
        return 1 + (profIzq > profDer ? profIzq : profDer);
    }
}

bool balanceado(abb a)
{
    if (a == NULL)
    {
        return true;
    }
    else
    {
        int profIzq = profundidad(a->ph);
        int profDer = profundidad(a->sh);
        if (profIzq - profDer > -2 && profIzq - profDer < 2)
        {
            return balanceado(a->ph) && balanceado(a->sh);
        }
        else
        {
            return false;
        }
    }
}