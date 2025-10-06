#include "iterativo.h"

int main() {
    lista l = crear();

    // Agregar elementos con cons (al principio)
    l = cons(l, 3);
    l = cons(l, 1);

    // Agregar elementos con snoc (al final)
    l = snoc(l, 4);
    l = snoc(l, 5);

    printf("Lista actual: ");
    imprimir(l);

    // Quitar un elemento
    l = quitar(l, 3);
    printf("Lista luego de quitar el 3: ");
    imprimir(l);

    // Verificar si pertenece
    if (IsElement(l, 4))
        printf("El 4 pertenece a la lista\n");
    else
        printf("El 4 NO pertenece a la lista\n");

    // Contar elementos
    printf("Cantidad de elementos: %d\n", contar(l));

    return 0;
}