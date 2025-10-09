#include "arbol.h"

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
    // pos: crea un nuevo árbolb cuya raíz tiene valor x
    if (a == NULL)
    {
        abb aux = new (nodo_abb);
        aux->dato = x;
        aux->izq = NULL;
        aux->der = NULL;
        return aux;
    }
    else if (x < a->dato)
    {
        a->izq = Insertar(x, a->izq);
    }
    else
    {
        a->der = Insertar(x, a->der);
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
    // retorna true si pertenece, false si es vacío
    if (vacio(a))
    {
        return false;
    }
    else if (raiz(a) == x)
    {
        return true;
    }
    else if (x < raiz(a))
    {
        return pertenece(x, subizq(a));
    }
    else
    {
        return pertenece(x, subder(a));
    }
}

int min_der(abb a)
{
    // pos: retorna el valor entero menor
    // pre: a no vacío
    if (vacio(subizq(a)))
    {
        return raiz(a);
    }
    else
    {
        return min_der(subizq(a));
    }
}

int max_izq(abb a)
{
    // pos:retorna el maximo del subarbol izq
    // pre: a no vacio
    if (vacio(subder(a)))
    {
        return a->dato;
    }
    else
    {
        return max_izq(a->der);
    }
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
    if (vacio(a))
    {
        return 0;
    }
    else
    {
        return 1 + cantidad(subizq(a)) + cantidad(subder(a));
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
        else if (profundidad(a->izq) > profundidad(a->der))
        {
            int datoMaxizq = max_izq(a->izq);
            a->dato = datoMaxizq;
            a->izq = eliminar(datoMaxizq, a->izq);
        }
        else
        {
            int datoMinder = min_der(a->der);
            a->dato = datoMinder;
            a->der = eliminar(datoMinder, a->der);
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
        a->izq = destruir(subizq(a));
        a->der = destruir(subder(a));
        delete a;
        return NULL;
    }
}

void alisarAbb(abb a, lista &s, lista &l)
{
    if (a != NULL)
    {
        alisarAbb(a->izq, s, l);

        lista aux = new nodo_lista;
        aux->dato = a->dato;
        aux->sig = NULL;

        if (l == NULL)  // 
        {
            l = aux;
            s = aux;
        }
        else
        {
            l->sig = aux;
            l = aux;
        }

        alisarAbb(a->der, s, l);
    }
}


// Ejercicios posibles: contar la cantidad de hojas,