// Estructuras de Datos y Algoritmos - Curso 2022
// Modulo Definición/Especificación Arreglo Dinámico.


#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stdlib.h>  // Para malloc, free
#include <iostream>
#include <string.h>  // Para strcpy

typedef struct nodo_dynar * dynar; // tipo opaco

dynar dynar_crear(int tam);
// Crea un Arreglo dinamico de tamaño tam.

dynar dynar_ins(dynar d, char * cadena);
// Setea la cadena en d.
// Pre: largo cadena <= tamaño d

int dynar_tam(dynar d);
// Retorna el tamaño de d.

char * dynar_cad(dynar d);
// Retorna la cadena en d.

dynar dynar_redimension(dynar d, int tam);
// Redimensiona d tam lugares.
// Pre: tam != 0
// Post: al redimensionar con numeros negativos se trunca la cadena tam lugares.

dynar dynar_destruir(dynar d);
// Destruye d y libera la memoria asociada.

#endif

