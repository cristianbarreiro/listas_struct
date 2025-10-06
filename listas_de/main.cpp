#include "listade.h"

int main()
{
    listade l = crear();

    // Insertar elementos al inicio y al final
    l = cons(l, 3);
    l = cons(l, 1);
    l = snoc(l, 5);
    l = snoc(l, 7);

    printf("Lista después de cons y snoc:\n");
    imprimir(l);

    // Insertar ordenadamente
    l = insOrd(l, 4);
    printf("Lista tras insOrd(4):\n");
    imprimir(l);

    // Consultas
    printf("Cantidad total de elementos: %d\n", cant(l));
    printf("Cantidad de anteriores al actual: %d\n", cant_ant(l));
    printf("Cantidad de siguientes al actual: %d\n", cant_sig(l));
    printf("¿Pertenece el 5? %s\n", pertenece(l, 5) ? "Sí" : "No");
    printf("¿Pertenece el 10? %s\n", pertenece(l, 10) ? "Sí" : "No");
    printf("Primero: %d\n", primero(l));
    printf("Último: %d\n", ultimo(l));
    printf("Actual (primer nodo): %d\n", actual(l));

    // Navegación
    listade nodo = l;
    while (ant(nodo) != NULL)
        nodo = ant(nodo);
    printf("Recorrido hacia adelante: ");
    while (nodo != NULL)
    {
        printf("%d ", actual(nodo));
        nodo = sig(nodo);
    }
    printf("\n");

    // Impresión invertida
    printf("Lista invertida:\n");
    imprimirInvertido(l);

    // Eliminar un elemento
    l = eliminar(l, 4);
    printf("Lista tras eliminar(4):\n");
    imprimir(l);

    // Destruir la lista
    l = destruir(l);
    printf("Lista tras destruir:\n");
    imprimir(l);

    return 0;
}