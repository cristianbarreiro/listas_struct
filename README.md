# Listas y Estructuras de Datos

Colección de implementaciones de estructuras de datos y algoritmos en C y C++ para fines educativos.

## 📁 Estructura del Proyecto

Este repositorio contiene múltiples implementaciones de estructuras de datos clásicas:

### Listas
- **Listas-Generales**: Implementación de listas generales en C++
- **listas_circ**: Listas circulares
- **listas_de**: Listas doblemente enlazadas
- **listas_gen**: Listas genéricas
- **listas_simp_iter**: Listas simplemente enlazadas (iterativo)
- **listas_simp_rec**: Listas simplemente enlazadas (recursivo)

### Árboles
- **arboles_bin**: Árboles binarios básicos
- **arboles_bin_busqueda**: Árboles binarios de búsqueda (recursivo)
- **arboles_bin_busqueda_iter**: Árboles binarios de búsqueda (iterativo)
- **arboles_fin_phsh**: Árboles con finalización por hash

### Pilas y Colas
- **stack**: Implementación de pila (stack)
- **stack_arreglo**: Pila implementada con arreglos
- **stack_lista**: Pila implementada con listas
- **queue**: Implementación de cola (queue)
- **sistema_queue_cola**: Sistema de colas
- **priority_queue**: Cola de prioridad
- **minheap**: Heap mínimo

### Hash Tables
- **hash abierto**: Hash table con encadenamiento abierto
- **hash cerrado**: Hash table con direccionamiento cerrado

### Algoritmos
- **Algoritmos de Ordenamiento-20251005**: Implementaciones de algoritmos de ordenamiento (sorting)

### Otros
- **TAD-Recursivo_old**: Tipos abstractos de datos recursivos (versión antigua)
- **dynar_TAD-20251005**: Arreglos dinámicos
- **estructuras_proyecto(incompleto)**: Proyecto de estructuras (incompleto)
- **practicas_2doparcial**: Prácticas del segundo parcial

## 🛠️ Tecnologías

- **Lenguajes**: C, C++
- **Compiladores**: GCC, G++
- **Build System**: Makefiles

## 📋 Requisitos

- Compilador GCC/G++ instalado
- Make (para proyectos con Makefile)

## 🚀 Uso

### Compilar un proyecto individual

Para proyectos con Makefile:
```bash
cd [directorio_del_proyecto]
make
```

Para proyectos sin Makefile:
```bash
g++ -o main main.cpp [otros_archivos.cpp]
```

### Ejecutar
```bash
./main
```

## 📚 Estructuras Implementadas

### Listas Enlazadas
- **Simples**: Un enlace por nodo
- **Dobles**: Dos enlaces (anterior y siguiente)
- **Circulares**: El último nodo apunta al primero
- **Genéricas**: Implementación reutilizable con templates

### Árboles
- **Binarios**: Cada nodo tiene máximo 2 hijos
- **Binarios de Búsqueda**: Propiedad de ordenamiento (izquierda < raíz < derecha)
- **Iterativos vs Recursivos**: Diferentes enfoques de implementación

### Hash Tables
- **Abierto**: Resolución de colisiones con listas enlazadas
- **Cerrado**: Resolución de colisiones con sondeo lineal/cuadrático

### Estructuras Lineales
- **Pilas (Stack)**: LIFO (Last In, First Out)
- **Colas (Queue)**: FIFO (First In, First Out)
- **Colas de Prioridad**: Elementos con prioridad variable

## 📖 Conceptos Cubiertos

- Tipos Abstractos de Datos (TAD)
- Gestión dinámica de memoria
- Recursividad
- Complejidad algorítmica
- Patrones de diseño en estructuras de datos

## 🎓 Propósito Educativo

Este repositorio fue creado con fines educativos para aprender y practicar:
- Implementación de estructuras de datos desde cero
- Análisis de algoritmos
- Programación en C/C++
- Diseño de software modular

## 👤 Autor

Cristian Barreiro

## 📄 Licencia

Este proyecto es de uso educativo.
