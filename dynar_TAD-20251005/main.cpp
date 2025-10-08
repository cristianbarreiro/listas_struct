// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Modulo de Prueba Arreglo Dinámico.


#include "dyn_array.h"

#define MAX_COMANDO 25
#define MAX_CADENA 255

using namespace std;


int main(){
	bool salir= false;	
	char comando[MAX_COMANDO];
	dynar d;
	int valor;

	do{
		cout << "Comandos:\n\t- crear\n\t- ins\n\t- tam\n\t- cad\n\t- redim\n\t- dest\n\t- imprimir\n\t- salir\n\n";
		cout << "> ";
		cin >> comando; // Equivalente a scanf
		if(strcmp(comando, "crear") == 0){
			cout << "Insertar tamaño: ";
			cin >> valor;
			d= dynar_crear(valor);
			cout << " -- arreglo dinámico creado\n\n";
		}
		else if(strcmp(comando, "ins") == 0){
			char cadena[MAX_CADENA];
			cout << "Insertar caracteres: ";
			cin >> cadena;
			d = dynar_ins(d, cadena);
			cout << " -- cadena de caracteres seteada\n\n";
		}
		else if(strcmp(comando, "tam") == 0){
			cout << " -- el tamaño del arreglo es " << dynar_tam(d) << endl;
		}
		else if(strcmp(comando, "cad") == 0){
			cout << " -- contenido: " << dynar_cad(d) << "\n";
		}
		else if(strcmp(comando, "redim") == 0){
			cout << "Insertar valor: ";
			cin >> valor;
			d= dynar_redimension(d, valor);
			cout << " -- arreglo redimensionado " << valor << " lugares.\n\n";
		}
		else if(strcmp(comando, "dest") == 0){
			d = dynar_destruir(d);
			cout << " -- arreglo destruido.\n\n";
		}
		else if(strcmp(comando, "imprimir") == 0){
			cout << dynar_cad(d) << "\n";
		}
		else if(strcmp(comando, "salir") == 0){
			salir = true;
		}else
			cout << " -- comando incorrecto\n\n";
	}while(!salir);
	cout << "CHAUUUU!!!!\n\n";
}	
