#include "dyn_array.h"
#include <string.h>

struct nodo_dynar{
	char * cadena;
	int tam;
};

dynar dynar_crear(int tam){
// Crea un Arreglo dinamico de tamaño tam.
	dynar d = new(nodo_dynar);
	d->tam = tam;
	d->cadena = new char[tam];
	return d;
}

dynar dynar_ins(dynar d, char * cadena){
// Setea la cadena en d.
// Pre: largo cadena <= tamaño d
	strcpy(d->cadena, cadena);
	return d;
}

int dynar_tam(dynar d){
// Retorna el tamaño de d.
	return d->tam;
}

char * dynar_cad(dynar d){
// Retorna la cadena en d.
	return d->cadena;
}

dynar dynar_redimension(dynar d, int tam){
// Redimensiona d tam lugares.
// Pre: tam != 0
// Post: al redimensionar con numeros negativos se trunca la cadena tam lugares.
	char * aux = new char [d->tam + tam];
	
	if (d->tam < d->tam + tam){
		for (int i=0;i<d->tam;i++)
			aux[i] = d->cadena[i];
	}else{
		for (int i=0;i<d->tam + tam;i++)
			aux[i] = d->cadena[i];
	}
	d->tam += tam;   // d->tam = d->tam + tam;
	delete [] d->cadena;
	d->cadena = aux;
	return d;
}


dynar dynar_destruir(dynar d){
// Destruye d y libera la memoria asociada.
	delete [] d->cadena;
	delete d;
	return NULL;	
}










