#include "recursivo.h"

int main()
{
    lista l = crear();

    // Agregar elementos con cons (al principio)
    l = cons(l, 3);
    l = cons(l, 1);

    // Agregar elementos con snocRecursivo (al final)
    l = snocRecursivo(l, 4);
    l = snocRecursivo(l, 5);

    printf("Lista actual: ");
    printList(l);

    // Insertar ordenadamente
    l = InsertRecursivo(l, 2);
    printf("Lista tras InsertRecursivo(2): ");
    printList(l);

    // Quitar un elemento (primera ocurrencia)
    l = Quitar(l, 3);
    printf("Lista luego de Quitar(3): ");
    printList(l);

    // Eliminar todas las ocurrencias de un elemento
    l = cons(l, 4); // agrego otro 4 para probar RemoveRecursivo
    printf("Lista tras agregar otro 4: ");
    printList(l);
    lista l2 = RemoveRecursivo(l, 4);
    printf("Lista tras RemoveRecursivo(4): ");
    printList(l2);

    // Verificar si pertenece
    printf("¿El 5 pertenece a l2? %s\n", IsElement(l2, 5) ? "Sí" : "No");

    // Contar elementos
    printf("Cantidad de elementos (LengthRecursivo): %d\n", LengthRecursivo(l2));

    // Último elemento
    printf("Último elemento (LastRecursivo): %d\n", LastRecursivo(l2));

    // Máximo elemento
    printf("Máximo elemento (MaxRecursivo): %d\n", MaxRecursivo(l2));

    // Promedio
    printf("Promedio (AverageRecursivo): %.2f\n", AverageRecursivo(l2));

    // Contar ocurrencias de un valor
    printf("Ocurrencias de 2 (HowMany): %d\n", HowMany(2, l2));

    // Comparar listas
    lista l3 = crear();
    l3 = cons(l3, 1);
    l3 = snocRecursivo(l3, 2);
    l3 = snocRecursivo(l3, 5);
    printf("Lista l3: ");
    printList(l3);
    printf("¿l2 y l3 son iguales? %s\n", EqualsRecursivo(l2, l3) ? "Sí" : "No");

    // MergeRecursivo
    lista l4 = MergeRecursivo(l2, l3);
    printf("MergeRecursivo(l2, l3): ");
    printList(l4);

    // AppendRecursivo
    lista l5 = AppendRecursivo(l2, l3);
    printf("AppendRecursivo(l2, l3): ");
    printList(l5);

    // TakeRecursivo
    lista l6 = TakeRecursivo(2, l2);
    printf("TakeRecursivo(2, l2): ");
    printList(l6);

    // DropRecursivo
    lista l7 = DropRecursivo(2, l2);
    printf("DropRecursivo(2, l2): ");
    printList(l7);

    // Liberar memoria
    DeleteRecursivo(l);
    DeleteRecursivo(l2);
    DeleteRecursivo(l3);
    DeleteRecursivo(l4);
    DeleteRecursivo(l5);
    DeleteRecursivo(l6);
    DeleteRecursivo(l7);

    return 0;
}