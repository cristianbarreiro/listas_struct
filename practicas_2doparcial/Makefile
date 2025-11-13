# --- Variables ---

# Compilador de C++
CXX = g++

# Banderas de compilación:
# -Wall: Muestra todas las advertencias (warnings)
# -g: Incluye información de depuración (para usar con gdb)
# -std=c++11: Usa el estándar C++11 (necesario para 'new', 'nullptr', etc.)
CXXFLAGS = -Wall -g -std=c++11

# Nombre del archivo ejecutable final
EXEC = programa

# Lista de todos los archivos fuente (.cpp)
SRCS = main.cpp practica.cpp arbol_binario.cpp

# Lista de archivos objeto (.o) que se generarán a partir de los fuentes
OBJS = $(SRCS:.cpp=.o)

# --- Reglas ---

# La regla por defecto, que se ejecuta al escribir 'make'
# Depende del ejecutable final
all: $(EXEC)

# Regla para crear el archivo ejecutable
# Depende de todos los archivos objeto (.o)
# Enlaza los objetos para crear el ejecutable
$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Regla genérica para compilar cualquier archivo .cpp en su .o correspondiente
# -c: Compila pero no enlaza
# $<: Es el nombre de la primera dependencia (el archivo .cpp)
# $@: Es el nombre del objetivo (el archivo .o)
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar el directorio de archivos generados
# Se ejecuta con 'make clean'
clean:
    rm -f $(EXEC) $(OBJS)

# Declara que 'all' y 'clean' no son nombres de archivos
.PHONY: all clean