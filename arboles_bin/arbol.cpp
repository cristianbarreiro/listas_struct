#include "arbol.h"

struct nodo_arbolb { 
    int dato;
    arbolb izq;
    arbolb der;
}

arbolb crear() {
    //crea un árbol vacío binario
    return NULL;
}

arbolb Insertar(int x, arbolb aizq, arbolb ader) {
    //pos: crea un nuevo árbolb cuya raíz tiene valor x
    //y subárboles izq y der con aizq y ader
    arbolb aux = new (nodo_arbolb);
    aux->dato = x;
    aux->izq  = aizq;
    aux->der = ader;
    return aux;
}

int raiz(arbolb ab) {
    //pos: retorna el valor de el dato nodo
    //pre: ab no vacio
    return ab->dato;
}

arbolb subizq(arbolb ab) {
    //pos: retorna el subárbol izquierdo
    //pre: ab no vacía
    return ab->izq;
}

arbolb subder(arbolb ab) {
    //pos: retorna el subárbol derecho
    //pre: ab no vacío
    return ab->der;
}

bool vacio(arbolb ab) {
    //pos: retorna true si ab es vacío
    //en caso contrario
    return (ab == NULL);
}
//pertenece 1 y 2
bool pertenece1(int x, arbolb ab) {
    //pos: retorna true si x está en el árbol en el caso contrario retorna false
    if(ab == NULL) {
        return NULL;
    } else if(ab->dato == x) {
        return true;
    } else if(pertenece(x, ab->izq)) {
        return true;
    } else {
        return pertenece(x, ab->der);
    }
}

bool pertenece2(int x, arbolb ab) {
    //pos: retorna true si x está en el árbol, en caso contrario retorna false
    if(vacio(ab)) {
        return false;
    } else if(raiz(ab) == x) {
        return true;
    } else {
        return pertenece(x, subizq(ab)) || pertenece(x, subder(ab));
    }
}

int max(int x, int y) {
    //pos:retorna el valor mayor
    if(x > y) {
        return x;
    } else {
        return y;
    }
}

int profundidad(arbolb ab) {
    //pos: retorna la cantidad de nodos entre la raíz
    //y el camino más largo
    if(ab == NULL) {
        return 0;
    } else {
        return 1 + max(profundidad(ab->izq), profundidad(ab->der));
    }
}

int cantidad(arbolb ab) {
    //pos: retorna cantidad de nodos ab
    if(ab == NULL) {
        return 0;
    } else {
        return 1 + cantidad(ab->izq) + cantidad(ab->der);
    }
}

arbolb destruir(arbolb ab) {
    //pos: elimina todos los nodos y libera memoria
    if(ab == NULL) {
        return NULL;
    } else {
        ab->izq = destruir(ab->izq);
        ab->der  = destruir(ab->der);
        delete (ab);
        return NULL;
    }
}

void destruir(arbolb &ab) {
    //pos: elimina todos los nodos y libera memoria
    if(ab != NULL) {
        destruir(ab->izq);
        destruir(ab->der);
        delete (ab);
    }
}