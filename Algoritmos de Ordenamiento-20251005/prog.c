// Estructuras de Datos y Algoritmos 2020 - Turno Matutino y Vespertino Buceo
// Modulo de Prueba para Algortimos de Ordenacion

// prog.c

#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#define MAX_COMANDO 25

void imprimir_arreglo (int arr[], int tope)
// Recorre el arreglo imprime sus elementos.
{
	for (int i = 0; i < tope; i++)
	{
		if (tope != 0)
		{
			cout << arr[i];
			if (tope - i != 1)
			{
				cout << " - ";
			}
		}
	}
	cout << endl;
}

int main (int argc, char * argv[])
{
	bool salir = false;
	
	if (argc < 2)
	{
		cout << "\t ./sort [algoritmo] [elem1 elem2 elem3 .......]\n\n";
		cout << "   algoritmo:\n";
		cout << "\t1 - Bubble Sort\n";
		cout << "\t2 - Cocktail Sort\n";
		cout << "\t3 - Selection Sort\n";
		cout << "\t4 - Insertion Sort\n";
		cout << "\t5 - Merge Sort\n";
		cout << "\t6 - Quick Sort\n";
		cout << "\t7 - Shell Sort\n";
		cout << "   elem[i]:\n";
		cout << "\tlos elementos deben ser enteros\n\n";
		salir = true;
	}
	if (! salir)
	{
		int comparaciones = 0;
		int algoritmo = atoi(argv[1]);
		int tope = argc - 2;
		int arr[tope];
		if ((algoritmo > 0) && (algoritmo < 8))
		{
			for (int i = 0; i < tope; i++)
			{
				arr[i] = atoi(argv[i + 2]);
			}

			cout << "\n\tArreglo a ordenar: ";
			imprimir_arreglo (arr, tope);
			cout << endl;
		}
		
		if (algoritmo == 1)
		{
			cout << " - Ordenando con Bubble Sort.....\n";
			bubble_sort (arr, tope, comparaciones);
		}
		else if (algoritmo == 2)
		{
			cout << " - Ordenando con Cocktail Sort.....\n";
			cocktail_sort (arr, tope, comparaciones);
		}
		else if (algoritmo == 3)
		{
			cout << " - Ordenando con Selection Sort.....\n";
			selection_sort (arr, tope, comparaciones);
		}
		else if (algoritmo == 4)
		{
			cout << " - Ordenando con Insertion Sort.....\n";
			insertion_sort (arr, tope, comparaciones);
		}
		else if (algoritmo == 5)
		{
			cout << " - Ordenando con Merge Sort.....\n";
			merge_sort (arr, tope, comparaciones);
		}
		else if (algoritmo == 6)
		{
			cout << " - Ordenando con Quick Sort.....\n";
			quick_sort (arr, tope, comparaciones);
		}
		else if (algoritmo == 7)
		{
			cout << " - Ordenando con Shell Sort.....\n";
			shell_sort (arr, tope, comparaciones);
		}
		else
			cout << " - ERROR: Algoritmo debe ser un valor entre 1 y 7.\n";
		
		if ((algoritmo > 0) && (algoritmo < 8))
		{
			cout << "\tArreglo Ordenado: ";
			imprimir_arreglo (arr, argc - 2);
			cout << "\tCantidad de Elementos: " << tope << endl;
			cout << "\tComparaciones Realizadas: " << comparaciones << endl;
		}
		cout << endl;
	}
	
	
}
