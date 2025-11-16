#include "arbol_binario.h"


struct nodo_arbol
{
    int dato;
    abb ph;//primer hijo
    abb sh;//siguiente hermano
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

int MayorCantidadNivelQueue(abb a)
{
    if (vacio(a))
    {
        return 0;
    }

    // Usamos una cola para el recorrido por niveles.
    // La cola almacenará punteros a los nodos del árbol.
    std::queue<abb> q;
    q.push(a);

    int maxNodos = 0;

    while (!q.empty())
    {
        // El tamaño actual de la cola es el número de nodos en el nivel actual.
        int nodosEnNivel = q.size();

        // Actualizamos el máximo si el nivel actual tiene más nodos.
        if (nodosEnNivel > maxNodos)
        {
            maxNodos = nodosEnNivel;
        }

        // Procesamos todos los nodos del nivel actual:
        // los sacamos de la cola y añadimos a sus hijos.
        for (int i = 0; i < nodosEnNivel; ++i)
        {
            abb nodoActual = q.front();
            q.pop();

            // Si tiene hijo izquierdo (ph), lo añadimos a la cola.
            if (nodoActual->ph != NULL)
            {
                q.push(nodoActual->ph);
            }

            // Si tiene hijo derecho (sh), lo añadimos a la cola.
            if (nodoActual->sh != NULL)
            {
                q.push(nodoActual->sh);
            }
        }
    }

    return maxNodos;
}

void ContarNodosRecursivo(abb a, int nivel, int conteoNiveles[])
{
    if (vacio(a))
    {
        return;
    }

    // Incrementar el contador para el nivel actual.
    conteoNiveles[nivel]++;

    // Llamar recursivamente para los hijos en el siguiente nivel.
    ContarNodosRecursivo(a->ph, nivel + 1, conteoNiveles);
    ContarNodosRecursivo(a->sh, nivel + 1, conteoNiveles);
}

int MayorCantidadNivel(abb a)
{
    if (vacio(a))
    {
        return 0;
    }

    // 1. Calcular la profundidad máxima para saber el tamaño del arreglo necesario.
    int prof = profundidad(a);

    // 2. Crear un arreglo para almacenar el conteo de nodos de cada nivel.
    // Usamos 'new' para crear un arreglo dinámico en el heap.
    int* conteoNiveles = new int[prof](); // Los '()' inicializan todo a 0.

    // 3. Llamar a la función recursiva para llenar el arreglo.
    // Empezamos en el nivel 0.
    ContarNodosRecursivo(a, 0, conteoNiveles);

    // 4. Encontrar el valor máximo en el arreglo de conteos.
    int maxNodos = 0;
    for (int i = 0; i < prof; i++)
    {
        if (conteoNiveles[i] > maxNodos)
        {
            maxNodos = conteoNiveles[i];
        }
    }

    // 5. Liberar la memoria del arreglo.
    delete[] conteoNiveles;

    // 6. Retornar el máximo encontrado.
    return maxNodos;
}