run: compile
	./main

compile: main.o fonctions.o
	gcc -Wall -o main main.o fonctions.o -g

main.o: main.c fonctions.o
	gcc -Wall -c main.c fonctions.h fonctions.c -g

fonctions.o: fonctions.h fonctions.c
	gcc -Wall -c fonctions.h fonctions.c -g

sarcasme: sarcasme.c
	gcc -Wall -o sarcasme sarcasme.c -g
	./sarcasme

clean: 
	rm *.o
	rm main
	rm sarcasme

valgrind: compile
	valgrind ./main

code:
	code Makefile
	code main.c
	code fonctions.c
	code fonctions.h