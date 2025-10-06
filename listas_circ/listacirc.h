#ifndef LISTACIRC_H_
#define LISTACIRC_H_

#include <stdio.h>
#include <stdbool.h>

struct nodo_listacirc
{
    int dato;
    listacirc sig;
};
typedef struct nodo_listacirc *listacirc;

// ==== Creación y estado ====
listacirc crear();
bool vacia(listacirc l);

// ==== Inserción ====
listacirc cons(listacirc l, int n);
listacirc snoc(listacirc l, int n);

// ==== Consulta ====
int contar(listacirc l);
bool pertenece(listacirc l, int n);

// ==== Eliminación y destrucción ====
listacirc eliminar(listacirc l, int n);
listacirc destruir(listacirc l);

#endif