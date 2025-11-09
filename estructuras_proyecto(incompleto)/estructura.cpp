#include "estructura.h"

Version BuscarAux(Version v, char *version)
{
    if (v->numero == NULL)
    {
        printf("nohay");
        return NULL;
    }
    else
    {
        printf("llegueaux");
        if (strcmp(v->numero, version) == 0)
        {
            return v;
        }
        else if (mayor_string(v->numero, version))
        {
            printf("buscaraux1");
            if (v->hijo != NULL)
            {
                Version esta_abajo = BuscarAux(v->hijo, version);
                return esta_abajo;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            printf("buscaraux2");
            return BuscarAux(v->hermano, version);
        }
        printf("buscaraux");
    }
}

Version BuscarVersion(Archivo &a, char *version)

{

    // Busca recursivamente una versión específica en el árbol

    // Retorna el nodo de la versión si existe, NULL si no existe
    Version aux = new (nodo_version);
    aux = a->versiones;
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        return BuscarAux(aux, version);
        printf("buscarversion");
    }
}

bool mayor_string(char *version1, char *version2)
{

    std::cout << "Comparando: " << version1 << " vs " << version2 << std::endl;

    // Crear copias INDEPENDIENTES para cada tokenización
    char copia1[50];
    char copia2[50];
    strcpy(copia1, version1);
    strcpy(copia2, version2);

    // Tokenizar POR SEPARADO cada cadena
    char tokens1[10][10]; // Array para almacenar tokens de version1
    char tokens2[10][10]; // Array para almacenar tokens de version2

    int count1 = 0, count2 = 0;

    // Tokenizar primera versión
    char *token = strtok(copia1, ".");
    while (token != NULL && count1 < 10)
    {
        strcpy(tokens1[count1], token);
        count1++;
        token = strtok(NULL, ".");
    }

    // Tokenizar segunda versión
    token = strtok(copia2, ".");
    while (token != NULL && count2 < 10)
    {
        strcpy(tokens2[count2], token);
        count2++;
        token = strtok(NULL, ".");
    }

    // Comparar los tokens
    int max_count = (count1 > count2) ? count1 : count2;

    for (int i = 0; i < max_count; i++)
    {
        int num1 = (i < count1) ? atoi(tokens1[i]) : 0;
        int num2 = (i < count2) ? atoi(tokens2[i]) : 0;

        if ((num1 == 0) && (i > 1))
        {
            printf("\n%s es mayor", version1);
            return true;
        }
        else if (num1 > num2)
        {
            std::cout << " -> " << version1 << " es MAYOR" << std::endl;
            printf("lleguemenor");
            return true;
        }
        else if (num1 < num2)
        {
            printf("%d-%d", num1, num2);

            if (num1 == 0)
            {
                printf("%s es mayor", version1);
                return true;
            }
            else
            {
                std::cout << " -> " << version2 << " es MAYOR" << std::endl;
                printf("lleguemayor");
                return false;
            }
        }
        else
        {
            std::cout << " -> Iguales" << std::endl;
        }
    }

    std::cout << "-> Las versiones son IGUALES" << std::endl;
    return false;
}

////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////

Archivo CrearArchivo(char *nombre)
{
    // Crea el archivo con el nombre especificado y lo inicializa sin contenido (vacío).
    // El archivo creado es retornado.
    // Esta operación se ejecuta al inicio de una sesión de trabajo con un archivo.
    if (strcmp(nombre, "") == 0)
    {
        return NULL;
    }

    Archivo a = new nodo_archivo;
    /*/ Inicializamos la lista de versiones en NULL hasta que se creen.
    a->versiones = new (nodo_version);
    strcpy(a->versiones->numero, "0");
    a->versiones->esraiz = true;
    */

    // Reservamos memoria para el nombre y evitamos desbordes respetando MAX_NOMBRE.
    size_t largo = strlen(nombre);
    if (largo >= MAX_NOMBRE)
    {
        largo = MAX_NOMBRE - 1;
    }
    a->nombre = new char[MAX_NOMBRE];
    strncpy(nombre, a->nombre, largo);

    return a;
}

TipoRet BorrarArchivo(Archivo &a)
{
    // Elimina toda la memoria utilizada por el archivo y asigna NULL al puntero a.
    // Se asume como precondición que a referencia a un archivo (en particular a es distinto a NULL).
    // Esta operación se ejecuta al final de una sesión de trabajo con un archivo.
    // Liberar el nodo
    Version aux1;
    aux1 = a->versiones;
    if (aux1 != NULL)
        BorrarArbol(aux1);
    if (a->nombre != NULL)
        delete[] a->nombre;
    delete a;
    a = NULL;
    return OK;
}

TipoRet BorrarArbol(Version &a)
{
    // Elimina recursivamente todo el árbol de versiones comenzando desde el nodo a.
    // Pre: a es un nodo de versión válido o NULL.
    // Post: Libera toda la memoria del árbol de versiones y asigna NULL a a.
    if (a == NULL)
        return OK;

    // Recursivamente borrar todos los hijos
    if (a->hijo != NULL)
        BorrarArbol(a->hijo);

    // Recursivamente borrar todos los hermanos
    if (a->hermano != NULL)
        BorrarArbol(a->hermano);

    // Borrar el texto asociado (lista enlazada)
    if (a->texto != NULL)
    {
        while (a->texto != NULL)
        {
            Texto aux = a->texto;
            a->texto = a->texto->sig;

            // Liberar la línea si existe
            if (aux->linea != NULL)
                delete aux->linea;

            // Liberar el nodo de texto
            delete aux;
        }
    }

    // Liberar memoria de strings

    if (a->numero != NULL)
        delete a->numero;
    delete a;
    a = NULL;

    return OK;
}

TipoRet InsertarLinea(Archivo &a, char *version, char *linea, unsigned int nroLinea, char *error)
{
    // Esta función inserta una linea de texto a la version parámetro en la posición nroLinea.
    // El número de línea debe estar entre 1 y n+1, siendo n la cantidad de líneas del archivo. Por ejemplo, si el texto tiene 7 líneas, se podráinsertar en las posiciones 1 (al comienzo) a 8 (al final).
    // Si se inserta en un número de línea existente, ésta y las siguientes líneas se correrán hacia adelante (abajo) dejando el espacio para la nueva línea.
    // No se puede insertar una línea en una versión que tenga subversiones.
    // Notar que el crear un archivo, éste no es editable hSasta que no se crea al menos una versión del mismo. Sólo las versiones de un archivo son editables (se pueden insertar o suprimir líneas), siempre que no tengan subversiones creadas.
    // En caso que TipoRet sea ERROR, en error se debe cargar cuál es el mismo.
    Version aux1;
    const char *origen;

    aux1 = BuscarVersion(a, version);
    printf("ins1");
    if (aux1 == NULL)
    {
        strcpy(error, "version no encontrada");
        printf("%s \n", error);
        return ERROR;
    }
    if (aux1->hijo != NULL)
    {

        strcpy(error, "version tiene subversiones");
        printf("%s \n", error);
        return ERROR;
    }
    Texto tex;
    tex = aux1->texto;
    if (nroLinea == 0)
    {
        strcpy(error, "nroLinea no es válido");
        printf("%s \n", error);
        return ERROR;
    }
    printf("ins2");
    if (tex == NULL)
    {
        tex = new (nodo_texto);
        tex->linea = linea;
        tex->nlinea = 1;
        printf("texto creado");
    }
    printf("ins3");

    while ((tex->sig != NULL) && (tex->nlinea != nroLinea))
        tex = tex->sig;
    if (tex->nlinea == nroLinea)
    {
        Texto auxtex1;
        auxtex1->nlinea = 1;
        auxtex1->linea = tex->linea;
        auxtex1->nlinea = tex->nlinea + 1;
        printf("ins4");

        tex->sig = auxtex1;
        tex->linea = linea;
        auxtex1 = auxtex1->sig;
        while (auxtex1 != NULL)
        { /*BUCLE NO CIERRA*/
            auxtex1->nlinea = auxtex1->nlinea + 1;
            auxtex1 = auxtex1->sig;
            printf("problema");
        }

        return OK;
    }
    else if ((tex->sig == NULL) && (nroLinea == tex->nlinea + 1))
    {
        tex->sig = new nodo_texto();
        tex = tex->sig;
        tex->linea = linea;
        tex->nlinea = nroLinea;
        return OK;
    }

    else if ((tex->sig == NULL) && (nroLinea == tex->nlinea))
    {
        Texto auxtex1;
        auxtex1->nlinea = 0;
        auxtex1->linea = tex->linea;
        auxtex1->nlinea = tex->nlinea + 1;
        tex->sig = auxtex1;
        tex->linea = linea;
        return OK;
    }

    strcpy(error, "nroLinea no es válido");
    printf("%s \n", error);
    return ERROR;
}

TipoRet BorrarLinea(Archivo &a, char *version, unsigned int nroLinea, char *error)
{
    // Esta función elimina una línea de texto de la version del archivo a en la posición nroLinea.
    // El número de línea debe estar entre 1 y n, siendo n la cantidad de líneas del archivo. Por ejemplo, si el texto tiene 7 líneas, se podrán eliminar líneas de las posiciones 1 a 7.
    // Cuando se elimina una línea, las siguientes líneas se corren, decrementando en una unidad sus posiciones para ocupar el lugar de la línea borrada.
    // No se puede borrar una línea de una versión que tenga subversiones creadas.
    // En caso que TipoRet sea ERROR, en error se debe cargar cuál es el mismo.
    Texto tex = new (nodo_texto);
    const char *origen;
    Version aux1 = new (nodo_version);
    aux1 = BuscarVersion(a, version);
    if (aux1 == NULL)
    {

        strcpy(error, "version no encontrada");
        printf("%s \n", error);
        return ERROR;
    }
    if (aux1->hijo != NULL)
    {

        strcpy(error, "version tiene subdivisones");
        printf("%s \n", error);
        return ERROR;
    }
    if (nroLinea == 0)
    {

        strcpy(error, "nroLinea no es válido");
        printf("%s \n", error);
        return ERROR;
    }

    tex = aux1->texto;
    if (aux1->texto == NULL)
    {
        printf("no hay texto que borrar");
        return ERROR;
    }
    else
        while ((tex->sig != NULL) && (tex->sig->nlinea != nroLinea))
            tex = tex->sig;
    if (tex->sig->nlinea == nroLinea)
    {
        Texto auxtex1;
        auxtex1->nlinea = 0;
        Texto auxtex2;
        auxtex1->linea = tex->linea;
        auxtex1->nlinea = tex->nlinea;
        tex = tex->sig;
        auxtex2 = tex->sig;
        delete tex;
        tex = NULL;
        auxtex1->sig = auxtex2;
        auxtex1 = auxtex1->sig;
        while (auxtex1 != NULL)
        {
            auxtex1->nlinea = auxtex1->nlinea - 1;
            auxtex1 = auxtex1->sig;
        }
        return OK;
    }

    else if ((tex->sig->sig == NULL) && (tex->sig->nlinea == nroLinea))
    {
        tex = tex->sig;
        delete tex;
        tex = NULL;
        return OK;
    }
    else if ((tex->sig == NULL) && (tex->nlinea == nroLinea))
    {
        delete tex;
        tex = NULL;
        return OK;
    }

    strcpy(error, "nroLinea no es válido");
    printf("%s \n", error);
    return ERROR;
}

void imp_version(Archivo &a, char *version)
{
    while (a != NULL)
    {
    }
}

TipoRet MostrarTexto(Archivo a, char *version)
{
    Version aux1 = new (nodo_version);
    aux1 = BuscarVersion(a, version);
    // aux1=a->versiones
    printf("encontre");
    if (aux1 == NULL)
    {
        printf("nohayversion");
        return ERROR;
    }
    else
    {
        Texto tex;
        tex = aux1->texto;
        /*de aca*/ if (tex == NULL)
        {
            printf("No contiene lineas");
        }
        else
        { /*hasta aca*/
            while (tex->linea != NULL)
            {
                printf("while");
                printf("%d  ", tex->nlinea);
                printf("%s  \n", tex->linea);
                tex = tex->sig;
            }
        }
        return OK;
        // Esta función muestra el texto completo de la version, teniendo en cuenta los cambios realizados en dicha versión y en las versiones ancestras, de la cual ella depende.
    }
}
