#include "stack.h"
#include <stdio.h>

int main()
{
    // Crear un nuevo stack
    stack s = crear_stack();

    // Verificar si el stack está vacío
    printf("¿Stack vacío?: %s\n", vacio(s) ? "Sí" : "No");

    // Push de algunos elementos
    s = push(s, 10);
    s = push(s, 20);
    s = push(s, 30);

    // Mostrar el elemento en el tope
    printf("Elemento en el tope: %d\n", top(s));

    // Pop un elemento
    s = pop(s);
    printf("Después de un pop, elemento en el tope: %d\n", top(s));

    // Destruir el stack
    s = destruir(s);
    printf("¿Stack vacío después de destruir?: %s\n", vacio(s) ? "Sí" : "No");

    return 0;
}