#include "min_heap.h"

struct nodo_minheap
{
    int *arr;
    int tope;
};

//Crea un minheap vacío
minheap minheap_crear()
{
    minheap h = new nodo_minheap;
    h->tope = 0;
}

// Inserta x en el min-heap h
minheap minheap_insertar(minheap h, int x)
{
}

// Retorna el valor del mínimo elemento
int minheap_lleno(minheap h)
{
}

// Retorna true si el min-heap está lleno
bool minheap_lleno(minheap h)
{
}

// Retorna la cantidad de elementos de h
int minheap_tope(minheap h)
{
}

minheap minheap_quitar_minimo(minheap h)
{
}

void minheap_imprimir_arreglo(minheap h)
{
}

void minheap_imprimir_monticulo(minheap h)
{
}

minheap minheap_destruir(minheap h)
{
    delete[] h->arr;
    delete h;
    return nullptr;
}