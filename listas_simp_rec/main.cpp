#include "recursivo.h"
#include <stdio.h>

int main()
{
    lista l = Null();

    // Insertar elementos al principio y al final
    l = cons(l, 3);
    l = cons(l, 1);
    l = snoc(l, 4);
    l = snoc(l, 5);

    printf("Lista actual: ");
    printList(l);

    // Insertar ordenadamente
    l = Insert(l, 2);
    printf("Lista tras Insert(2): ");
    printList(l);

    // Mostrar con Show
    int cont = 0;
    printf("Lista con Show: ");
    Show(l, cont);

    // Buscar elemento
    printf("¿El 4 pertenece a l? %s\n", IsElement(l, 4) ? "Sí" : "No");
    printf("¿El 7 pertenece a l? %s\n", IsElement(l, 7) ? "Sí" : "No");

    // Contar elementos
    printf("Cantidad de elementos: %d\n", Length(l));

    // Último elemento
    printf("Último elemento: %d\n", Last(l));

    // Máximo elemento
    printf("Máximo elemento: %d\n", Max(l));

    // Promedio
    printf("Promedio: %.2f\n", Average(l));

    // Contar ocurrencias de un valor
    printf("Ocurrencias de 4: %d\n", HowMany(l, 4));

    // Quitar un elemento (primera ocurrencia)
    l = Quitar(l, 3);
    printf("Lista tras Quitar(3): ");
    printList(l);

    // Eliminar todas las ocurrencias de un elemento
    l = cons(l, 4); // agrego otro 4
    printf("Lista tras agregar otro 4: ");
    printList(l);
    lista l2 = Remove(l, 4);
    printf("Lista tras Remove(4): ");
    printList(l2);

    // Comparar listas
    lista l3 = Null();
    l3 = cons(l3, 1);
    l3 = snoc(l3, 2);
    l3 = snoc(l3, 5);
    printf("Lista l3: ");
    printList(l3);
    printf("¿l2 y l3 son iguales? %s\n", Equals(l2, l3) ? "Sí" : "No");

    // Merge
    lista l4 = Merge(l2, l3);
    printf("Merge(l2, l3): ");
    printList(l4);

    // Append
    lista l5 = Append(l2, l3);
    printf("Append(l2, l3): ");
    printList(l5);

    // Take
    lista l6 = Take(2, l2);
    printf("Take(2, l2): ");
    printList(l6);

    // Drop
    lista l7 = Drop(2, l2);
    printf("Drop(2, l2): ");
    printList(l7);

    // Liberar memoria
    Delete(l);
    Delete(l2);
    Delete(l3);
    Delete(l4);
    Delete(l5);
    Delete(l6);
    Delete(l7);

    return 0;
}