ejec: main.o simplelist.o
	g++ -Wall -o ejec main.o simplelist.o
main.o: main.cpp
	g++ -Wall -c main.cpp
simplelist.o: simplelist.cpp simplelist.h
	g++ -Wall -c simplelist.cpp
clean:
	rm -f ejec
	rm -f *.o
