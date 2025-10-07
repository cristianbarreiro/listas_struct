#include "arbol.h"

struct nodo_arbolb { 
    int dato;
    arbolb izq;
    arbolb der;
};

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
    } else if(pertenece1(x, ab->izq)) {
        return true;
    } else {
        return pertenece1(x, ab->der);
    }
}

bool pertenece2(int x, arbolb ab) {
    //pos: retorna true si x está en el árbol, en caso contrario retorna false
    if(vacio(ab)) {
        return false;
    } else if(raiz(ab) == x) {
        return true;
    } else {
        return pertenece2(x, subizq(ab)) || pertenece2(x, subder(ab));
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

arbolb destruir1(arbolb ab) {
    //pos: elimina todos los nodos y libera memoria
    if(ab == NULL) {
        return NULL;
    } else {
        ab->izq = destruir1(ab->izq);
        ab->der  = destruir1(ab->der);
        delete (ab);
        return NULL;
    }
}

void destruir2(arbolb &ab) {
    //pos: elimina todos los nodos y libera memoria
    if(ab != NULL) {
        destruir2(ab->izq);
        destruir2(ab->der);
        delete (ab);
    }
}

int mayor(arbolb ab) {
   if(vacio(ab->izq) && vacio(ab->der)) {
    return raiz(ab);
   } else if(vacio(ab->izq)) {
    int mayorDerecho = mayor(ab->der);
    if(ab->dato > mayorDerecho) {
        return ab->dato;
    } else {
        return mayorDerecho;
    }
   } else if(vacio(ab->der)) {
        int mayorIzquierdo = mayor(ab->izq);
        if(ab->dato > mayorIzquierdo) {
            return ab->dato;
        } else {
            return mayorIzquierdo;
        }
    } else {
        int mayorIzquierdo = mayor(ab->izq);
        int mayorDerecho = mayor(ab->der);
        int result = max(ab->dato, mayorIzquierdo);
        result = max(result, mayorDerecho);
        return result;
   }
}