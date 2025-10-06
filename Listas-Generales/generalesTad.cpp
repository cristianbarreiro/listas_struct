#include "generalesTad.h"
// Definición de la estructura nodo_lista y nodo_listagral (por compatibilidad)

struct nodo_listagral
{
    lista dato;
    listagral sig;
};

// Crea la lista general vacía
listagral NullLG()
{
    return NULL;
}

// Inserta la lista elemento l al principio de la lista general lg
listagral ConsLG(listagral lg, lista l)
{
    listagral nuevo = new nodo_listagral;
    nuevo->dato = l;
    nuevo->sig = lg;
    return nuevo;
}

// Verifica si la lista general está vacía
bool IsEmptyLG(listagral lg)
{
    return lg == NULL;
}

// Retorna la primer lista elemento. Pre: lg no vacía
lista HeadLG(listagral lg)
{
    return lg->dato;
}

// Retorna lg sin su primer elemento. Pre: lg no vacía
listagral TailLG(listagral lg)
{
    return lg->sig;
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
        return 1 + LengthLG(TailLG(lg));
    }
}

// Muestra la lista general separando los elementos
void ShowLG(listagral lg)
{
    printf("[");
    listagral actual = lg;
    while (actual != NULL)
    {
        // Imprime los elementos de la lista interna
        printf("{");
        lista l = actual->dato;
        while (l != NULL)
        {
            printf("%d", l->dato);
            if (l->sig != NULL)
                printf(", ");
            l = l->sig;
        }
        printf("}");
        if (actual->sig != NULL)
            printf(" | ");
        actual = actual->sig;
    }
    printf("]\n");
}