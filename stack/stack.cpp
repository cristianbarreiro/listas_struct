#include "stack.h"

struct nodo_stack
{
    int dato;
    stack sig;
};

stack crear_stack()
{
    return NULL;
}

stack push(stack s, int x)
{
    stack aux = new (nodo_stack);
    aux->dato = x;
    if (vacio(s))
    {
        aux->sig = NULL;
    }
    else
    {
        aux->sig = s;
    }
    return aux;
}

stack pop(stack s)
{
    if (!vacio(s))
    {
        stack aux = s;
        s = s->sig;
        delete (aux);
    }
    return s;
}

int top(stack s)
{
    // pre: stack no vacio
    return s->dato;
}

bool vacio(stack s)
{
    return (s == NULL);
}

stack destruir(stack s)
{
    if (s != NULL)
    {
        s->sig = destruir(s->sig);
        delete s;
    }
    return NULL;
}