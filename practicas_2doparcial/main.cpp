#include "practica.h"
#include "arbol_finitario.h"

int main()
{
    // ================================================================
    // --- Pruebas para practica.cpp (Cola) ---
    // ================================================================
    printf("--- Probando la Cola (Queue) ---\n");

    // Creamos una cola vacía
    queue mi_cola = crearQueue();
    printf("Cola creada. Suma inicial: %d\n", mi_cola->suma);

    // Insertamos elementos
    mi_cola = insertar(mi_cola, 10);
    mi_cola = insertar(mi_cola, 20);
    mi_cola = insertar(mi_cola, 5);
    printf("Insertados 10, 20, 5. Nueva suma: %d\n", mi_cola->suma); // Esperado: 35

    // Eliminamos un elemento
    mi_cola = eliminar(mi_cola);
    printf("Eliminado el primer elemento (10). Nueva suma: %d\n", mi_cola->suma); // Esperado: 25

    // Eliminamos otro elemento
    mi_cola = eliminar(mi_cola);
    printf("Eliminado el primer elemento (20). Nueva suma: %d\n", mi_cola->suma); // Esperado: 5

    // Liberamos la memoria de la cola
    destruirQueue(mi_cola);
    printf("Cola destruida.\n");

    // ================================================================
    // --- Pruebas para arbol_binario.cpp (Árbol Binario) ---
    // ================================================================
    printf("\n--- Probando el Arbol Binario ---\n");

    // Construimos un árbol manualmente para probar
    //       20a
    //      /  \
    //     10  30
    //      \
    //      15
    abb arbol = crearArbol(20,
                           crearArbol(10, NULL, crearArbol(15, NULL, NULL)),
                           crearArbol(30, NULL, NULL));

    printf("Arbol creado.\n");

    // Probamos las funciones del árbol
    printf("Suma de todos los nodos: %d\n", suma(arbol));                      // Esperado: 75
    printf("Suma de nodos mayores que 18: %d\n", sumaMayoresQueK(arbol, 18));  // Esperado: 50
    printf("Maximo elemento del arbol: %d\n", maximo(arbol));                  // Esperado: 30
    printf("Profundidad del arbol: %d\n", profundidad(arbol));                 // Esperado: 3
    printf("El arbol esta balanceado? %s\n", balanceado(arbol) ? "Si" : "No"); // Esperado: Si

    // Liberamos la memoria del árbol
    destruirArbol(arbol);
    printf("Arbol destruido.\n");

    return 0;
}