#include "generalesTad.h"


int main()
{
    // Crear listas simples manualmente usando las funciones y el tipo lista
    lista l1 = NULL;
    lista l2 = NULL;

    // Agregar elementos a l1: 3, 2, 1
    l1 = new nodo_lista;
    l1 = new nodo_lista{2, l1};
    l1 = new nodo_lista{3, l1};

    // Agregar elementos a l2: 20, 10
    l2 = new nodo_lista{10, NULL};
    l2 = new nodo_lista{20, l2};

    // Crear lista general vacía
    listagral lg = NullLG();

    // Insertar listas simples en la lista general
    lg = ConsLG(lg, l1);
    lg = ConsLG(lg, l2);

    // Mostrar la lista general
    printf("Lista general:\n");
    ShowLG(lg);

    // Verificar si está vacía
    printf("¿Lista general vacía? %s\n", IsEmptyLG(lg) ? "Sí" : "No");

    // Mostrar la cantidad de elementos en la lista general
    printf("Cantidad de listas en la lista general: %d\n", LengthLG(lg));

    // Mostrar la primera lista elemento
    printf("Primera lista elemento:\n");
    lista head = HeadLG(lg);
    while (head != NULL)
    {
        printf("%d ", head->dato);
        head = head->sig;
    }
    printf("\n");

    // Mostrar la lista general sin el primer elemento
    printf("Lista general sin el primer elemento:\n");
    ShowLG(TailLG(lg));

    // Liberar memoria si lo necesitas (no implementado aquí)

    return 0;
}