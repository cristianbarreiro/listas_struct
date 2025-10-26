#include "estructura.h"

struct nodo_archivo
{
    char *nombre;
    Version versiones; // árbol de versiones
};

struct nodo_version
{
    char *numero = new char[20]; // "1", "2.1", "2.2.1", etc.
    Texto texto;                 // Puntero a las líneas del texto
    Version padre;               // Puntero al padre (NULL si raíz)
    Version hijo;                // Puntero al primer hijo (subversión)
    Version hermano;             // Puntero al siguiente hermano
    bool esraiz;                 // Indica si es una versión raíz (primer nivel)
};

struct nodo_texto
{
    char *linea = new char[120];
    unsigned int nlinea;
    Texto sig;
};