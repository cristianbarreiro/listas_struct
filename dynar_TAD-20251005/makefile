todo: main.o dyn_array.o
	g++ -Wall -o main main.o dyn_array.o
main.o: main.c
	g++ -Wall -c main.c
dyn_array.o: dyn_array.h dyn_array.c
	g++ -Wall -c dyn_array.c
limpiar:
	rm -f *.o
	rm -f main
