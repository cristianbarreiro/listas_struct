#include "arbol.h"
// INCOMPLETO: Cambiar funciones a Iterativas
struct nodo_abb
{
    int dato;
    abb izq;
    abb der;
};

abb crear()
{
    // crea un árbol vacío binario
    return NULL;
}

abb Insertar(int x, abb a)
{
    // pos: inserta x en forma ordenada en el abb.
    abb iter = a;
    abb ant;
    while (iter != NULL && x != iter->dato)
    {
        ant = iter;
        if (x < iter->dato)
        {
            iter = iter->izq;
        }
        else
        {
            iter = iter->der;
        }
    }
    if (iter == NULL)
    {
        // Si no se encontró el valor, se inserta
        abb aux = new (nodo_abb);
        aux->dato = x;
        aux->izq = NULL;
        aux->der = NULL;
        if (ant == NULL)
        {
            // Árbol vacío, el nuevo nodo es la raíz
            a = aux;
        }
        else if (x < ant->dato)
        {
            ant->izq = aux;
        }
        else
        {
            ant->der = aux;
        }
    }
    return a;
}

int raiz(abb a)
{
    // pos: retorna el valor de el dato nodo
    // pre: ab no vacio
    return a->dato;
}

abb subizq(abb a)
{
    // pos: retorna el subárbol izquierdo
    // pre: ab no vacía
    return a->izq;
}

abb subder(abb a)
{
    // pos: retorna el subárbol derecho
    // pre: ab no vacío
    return a->der;
}

bool vacio(abb a)
{
    // pos: retorna true si ab es vacío
    // en caso contrario
    return (a == NULL);
}

bool pertenece(int x, abb a)
{
    // pos: retorna true si x pertenece al árbol, false en caso contrario
    while (a != NULL)
    {
        if (x == a->dato)
        {
            return true;
        }
        else if (x < a->dato)
        {
            a = a->izq;
        }
        else
        {
            a = a->der;
        }
    }
    return false;
}

int minimo(abb a)
{
    // pos: retorna el valor entero menor
    // pre: a no vacío
    while (a->izq != NULL)
    {
        a = a->izq;
    }
    return a->dato;
}

int max(int x, int y)
{
    // pos:retorna el valor mayor
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int cantidad(abb a)
{
    int cant = 0;
    abb actual = a;
    
    while (actual != NULL)
    {
        if (actual->izq == NULL)
        {
            cant++;
            actual = actual->der;
        }
        else
        {
            abb pred = actual->izq;
            while (pred->der != NULL && pred->der != actual)
            {
                pred = pred->der;
            }
            
            if (pred->der == NULL)
            {
                pred->der = actual;
                actual = actual->izq;
            }
            else
            {
                pred->der = NULL;
                cant++;
                actual = actual->der;
            }
        }
    }
    
    return cant;
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
        return 1 + max(profIzq, profDer);
    }
}

abb eliminar(int x, abb a)
{
    if (vacio(a))
    {
        return NULL;
    }
    else if (x < a->dato)
    {
        a->izq = eliminar(x, a->izq);
    }
    else if (x > a->dato)
    {
        a->der = eliminar(x, a->der);
    }
    else
    { // x == a->dato - encontramos el nodo a eliminar
        if (vacio(subizq(a)) && vacio(subder(a)))
        {
            // Caso 1: Nodo hoja (sin hijos)
            delete a;
            return NULL;
        }
        else if (vacio(subizq(a)))
        {
            // Caso 2: Solo tiene hijo derecho
            abb temp = subder(a);
            delete a;
            return temp;
        }
        else if (vacio(subder(a)))
        {
            // Caso 3: Solo tiene hijo izquierdo
            abb temp = subizq(a);
            delete a;
            return temp;
        }
        else
        {
            // Caso 4: Tiene ambos hijos
            int minDer = minimo(subder(a));
            a->dato = minDer;
            a->der = eliminar(minDer, subder(a));
        }
    }
    return a;
}

abb destruir(abb a)
{
    // pos: elimina todos los nodos del árbol y libera la memoria
    if (vacio(a))
    {
        return NULL;
    }
    else
    {
        destruir(subizq(a));
        destruir(subder(a));
        delete a;
        return NULL;
    }
}
