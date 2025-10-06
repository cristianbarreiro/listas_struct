ejec: main.o recursivo.o
	g++ -Wall -o ejec main.o recursivo.o
main.o: main.cpp
	g++ -Wall -c main.cpp
recursivo.o: recursivo.cpp recursivo.h
	g++ -Wall -c recursivo.cpp
clean:
	rm -f ejec
	rm -f *.o
