#ifndef DEFINICIONES_H
#define DEFINICIONES_H

// Estructuras de Datos y Algoritmos - Obligatorio 2025
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// definiciones.h
// Modulo para definiciones generales del proyecto como constantes, etc.

#include <stdio.h>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>




enum _retorno
{
	OK,
	ERROR,
	NO_IMPLEMENTADA
};

typedef enum _retorno TipoRet;

#define MAX_NOMBRE 20
#define MAX_COMANDO 75

#endif