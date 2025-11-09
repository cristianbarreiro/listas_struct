#include "estructura.h"

int main()
{

    char l2[10] = "1.2.2";
    char numv1[5] = "1";
    char version1buscar[5] = "1";
    char numv2[5] = "1.1";
    char nombrearchivo[15] = "Pakito";
    char techo[30];
    char miamor2[30] = "sos muy linda";
    char miamor[30] = "te amo miamor,";
    char coco[15] = "coco";
    char doscocos[30] = "2cocos";
    unsigned int linea1 = 1;
    unsigned int linea2 = 2;

    /// inicializar texto

    Texto g = new nodo_texto;
    g->linea = miamor2;
    g->nlinea = 2;
    g->sig = NULL;

    Texto t = new nodo_texto;
    t->linea = miamor;
    t->nlinea = 1;
    t->sig = NULL;

    printf("1,");

    Archivo pakito = new nodo_archivo;
    pakito->nombre = nombrearchivo;

    printf("2,");
    Version v2 = new nodo_version;
    v2->numero = numv2;
    v2->padre = NULL;
    v2->hijo = NULL;
    v2->texto = NULL;
    v2->hermano = NULL;
    v2->esraiz = false;

    Version v1 = new nodo_version;
    v1->numero = numv1;
    v1->padre = NULL;
    v1->texto = NULL;
    v1->hijo = NULL;
    v1->hermano = NULL;
    v1->esraiz = true;

    printf("3,");
    pakito->versiones = v1;
    printf("4,");

    // InsertarLinea(pakito, version1buscar, coco, linea1, techo);

    MostrarTexto(pakito, version1buscar);
    printf("5,");

    InsertarLinea(pakito, numv1, coco, linea1, techo);
    printf("6,");
    printf("%s", v1->texto->linea);
    MostrarTexto(pakito, version1buscar);

    // BorrarLinea(pakito, version1buscar, linea1, techo);

    // MostrarTexto(pakito, version1);
    printf("7,");

    // BuscarVersion(pakito, l2);
    // BorrarArchivo(pakito);
    // printf("7,");

    return 0;
}