#include "sistema.h"
#include <stdio.h>

int main()
{
    // Crear una nueva queue
    queue q = crear_queue();

    // Verificar si la queue está vacía
    printf("¿Queue vacía?: %s\n", vacia_queue(q) ? "Sí" : "No");

    // Enqueue algunos elementos
    q = enqueue(q, 10);
    q = enqueue(q, 20);
    q = enqueue(q, 30);

    // Mostrar el primer y último elemento
    printf("Primero en la queue: %d\n", primero(q));
    printf("Último en la queue: %d\n", ultimo(q));

    // Dequeue un elemento
    q = dequeue(q);
    printf("Después de un dequeue, primero: %d\n", primero(q));

    // Destruir la queue
    q = destruir_queue(q);
    printf("¿Queue vacía después de destruir?: %s\n", vacia_queue(q) ? "Sí" : "No");

    return 0;
}