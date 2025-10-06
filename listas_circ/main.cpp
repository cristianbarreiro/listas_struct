#include "listacirc.h"
#include <stdio.h>



int main()
{
    listacirc l = crear();

    // Probar vacia
    printf("¿Lista vacía? %s\n", vacia(l) ? "Sí" : "No");

    // cons
    l = cons(l, 1);
    l = cons(l, 2);
    l = cons(l, 3);

    // snoc
    l = snoc(l, 4);
    l = snoc(l, 5);

    // contar
    printf("Cantidad de elementos: %d\n", contar(l));

    // pertenece
    printf("¿Pertenece el 3? %s\n", pertenece(l, 3) ? "Sí" : "No");
    printf("¿Pertenece el 10? %s\n", pertenece(l, 10) ? "Sí" : "No");

    // Mostrar todos los elementos (recorrido manual)
    printf("Elementos de la lista: ");
    if (!vacia(l))
    {
        listacirc iter = l;
        do
        {
            printf("%d ", iter->dato);
            iter = iter->sig;
        } while (iter != l);
    }
    printf("\n");

    // eliminar
    l = eliminar(l, 2);
    printf("Lista tras eliminar(2): ");
    if (!vacia(l))
    {
        listacirc iter = l;
        do
        {
            printf("%d ", iter->dato);
            iter = iter->sig;
        } while (iter != l);
    }
    printf("\nCantidad: %d\n", contar(l));

    // destruir
    l = destruir(l);
    printf("Lista tras destruir: cantidad = %d\n", contar(l));
    printf("¿Lista vacía? %s\n", vacia(l) ? "Sí" : "No");

    return 0;
}