#include "arbol.h"

struct nodo_abb { 
    int dato;
    abb izq;
    abb der;
}

abb crear() {
    //crea un árbol vacío binario
    return NULL;
}

abb Insertar(int x, abb a) {
    //pos: crea un nuevo árbolb cuya raíz tiene valor x
    if(a  == NULL) {
        abb aux = new (nodo_abb);
        abb->dato = x;
        abb->izq = NULL;
        abb->der = NULL;
        return aux;
    } else if(x < a->dato) {
        a->izq = insertar(x, a->izq);
    } else {
        a->der = insertar(x, a->der);
    }
    return a;
}

int raiz(abb a) {
    //pos: retorna el valor de el dato nodo
    //pre: ab no vacio
    return a->dato;
}

abb subizq(abb a) {
    //pos: retorna el subárbol izquierdo
    //pre: ab no vacía
    return a->izq;
}F

abb subder(abb a) {
    //pos: retorna el subárbol derecho
    //pre: ab no vacío
    return a->der;
}

bool vacio(abb a) {
    //pos: retorna true si ab es vacío
    //en caso contrario
    return (a == NULL);
}
//pertenece 1 y 2
bool pertenece1(int x, abb a) {
    
}

bool pertenece2(int x, abb a) {
    
}

int max(int x, int y) {
    //pos:retorna el valor mayor
    if(x > y) {
        return x;
    } else {
        return y;
    }
}

int profundidad(abb a) {
   
}

int cantidad(abb a) {
   
}

abb destruir(abb ab) {
  
}

void destruir(abb &ab) {
    
}