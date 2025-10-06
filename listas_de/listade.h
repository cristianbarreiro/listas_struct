#ifndef LISTADE_H_
#define LISTADE_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct nodo_listade *listade;

// ==== Creación y estado ====
listade Null();
bool isEmpty(listade l);

// ==== Inserción y ordenamiento ====
listade cons(listade l, int n);
listade snoc(listade l, int n);
listade insOrd(listade l, int n);

// ==== Consulta de cantidad ====
int cant(listade l);
int cant_ant(listade l);
int cant_sig(listade l);

// ==== Consulta de elementos ====
bool pertenece(listade l, int n);
int primero(listade l);
int ultimo(listade l);
int actual(listade l);

// ==== Navegación ====
listade ant(listade l);
listade sig(listade l);

// ==== Eliminación y destrucción ====
listade eliminar(listade l, int n);
listade destruir(listade l);

// ==== Visualización ====
void imprimir(listade l);
void imprimirInvertido(listade l);

#endif