#include "arbol.h"

struct nodo_arbol {
    int dato;
    arbol ph;
    arbol sh;
};

arbol crear() {
    // Crea un árbol vacío.
    return NULL;
}

arbol primer_hijo(arbol a) {
    // Retorna el primer hijo del árbol a.
    // Pre: a no es vacío.
    return a->ph;
}

arbol siguiente_hermano(arbol a) {
    // Retorna el segundo hijo del árbol a.
    // Pre: a no es vacío.
    return a->sh;
}

int cantidad(arbol a){
    //Pos: cantidad de nodos en el árbol
    if (a == NULL){
        return 0;
    } else {
        return 1 + cantidad(primer_hijo(a)) + cantidad(siguiente_hermano(a));
    }
}

bool pertenece(int x, arbol a) {
    // Retorna true si x pertenece al árbol a.
    if (a == NULL) {
        return false;
    } else if (a->dato == x) {
        return true;
    } else {
        return pertenece(x, primer_hijo(a)) || pertenece(x, siguiente_hermano(a));
    }
}

int profundidad(arbol a) {
    // Retorna la profundidad del árbol a.
    if (a == NULL) {
        return 0;
    } else {
        int maxProfHijo = 0;
        arbol hijo = primer_hijo(a);
        while (hijo != NULL) {
            int profHijo = profundidad(hijo);
            if (profHijo > maxProfHijo) {
                maxProfHijo = profHijo;
            }
            hijo = siguiente_hermano(hijo);
        }
        return 1 + maxProfHijo;
    }
}

bool vacio(arbol a) {
    // Retorna true si el árbol a es vacío.
    return (a == NULL);
}

arbol destruir(arbol a) {
    // Destruye el árbol a y libera la memoria asociada.
    if (a != NULL) {
        arbol hijo = primer_hijo(a);
        while (hijo != NULL) {
            arbol siguiente = siguiente_hermano(hijo);
            destruir(hijo);
            hijo = siguiente;
        }
        delete a;
    }
    return NULL;
}

arbol insertar(int x, int padre, arbol a){
    // Inserta el valor x como hijo del nodo con valor padre en el árbol a.
    // Si padre no existe en a, no hace nada.
    if (a == NULL) {
        return NULL;
    } else if (a->dato == padre) {
        arbol nuevo = new nodo_arbol;
        nuevo->dato = x;
        nuevo->ph = NULL;
        nuevo->sh = a->ph;
        a->ph = nuevo;
        return a;
    } else {
        arbol hijo = primer_hijo(a);
        while (hijo != NULL) {
            arbol resultado = insertar(x, padre, hijo);
            if (resultado != NULL) {
                return a; // Inserción exitosa
            }
            hijo = siguiente_hermano(hijo);
        }
        return NULL; // Padre no encontrado
    }
}