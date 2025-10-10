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
    // pos: elimina el nodo con valor x del árbol (iterativa)
    abb actual = a;
    abb padre = NULL;

    while (actual != NULL && actual->dato != x)
    {
        padre = actual;
        if (x < actual->dato)
        {
            actual = actual->izq;
        }
        else
        {
            actual = actual->der;
        }
    }

    if (actual == NULL)
    {
        return a;
    }

    abb reemplazo;

    if (actual->izq == NULL && actual->der == NULL)
    {
        reemplazo = NULL;
    }
    else if (actual->izq == NULL)
    {
        reemplazo = actual->der;
    }
    else if (actual->der == NULL)
    {
        reemplazo = actual->izq;
    }
    else
    {
        abb padreSucesor = actual;
        abb sucesor = actual->der;
        while (sucesor->izq != NULL)
        {
            padreSucesor = sucesor;
            sucesor = sucesor->izq;
        }

        actual->dato = sucesor->dato;

        if (padreSucesor == actual)
        {
            padreSucesor->der = sucesor->der;
        }
        else
        {
            padreSucesor->izq = sucesor->der;
        }

        delete sucesor;
        return a;
    }

    if (padre == NULL)
    {
        delete actual;
        return reemplazo;
    }
    else if (padre->izq == actual)
    {
        padre->izq = reemplazo;
    }
    else
    {
        padre->der = reemplazo;
    }

    delete actual;
    return a;
}

abb destruir(abb a)
{
    // pos: elimina todos los nodos del árbol y libera la memoria (iterativa)
    if (vacio(a))
    {
        return NULL;
    }
    else
    {
        abb actual = a;
        
        while (actual != NULL)
        {
            if (actual->izq == NULL)
            {
                abb temp = actual;
                actual = actual->der;
                delete temp;
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
                    abb temp = actual;
                    actual = actual->der;
                    delete temp;
                }
            }
        }
        
        return NULL;
    }
}
