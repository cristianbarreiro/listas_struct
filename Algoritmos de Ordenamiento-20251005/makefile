ejec: prog.o sorting.o
	g++ -Wall -o sort sorting.o prog.o
prog.o: sorting.o prog.c
	g++ -Wall -c prog.c
sorting.o: sorting.c sorting.h
	g++ -Wall -c sorting.c
clean:
	rm -f sort
	rm -f *.o
