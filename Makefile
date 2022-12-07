run: compile
	./bin/main

compile: bin/main.o bin/fonctions.o
	gcc -Wall -o ./bin/main ./bin/main.o ./bin/fonctions.o -g

./bin/main.o: src/main.c bin/fonctions.o
	gcc -Wall -c src/main.c src/fonctions.h src/fonctions.c -g
	mv main.o ./bin/main.o

./bin/fonctions.o: src/fonctions.h src/fonctions.c
	gcc -Wall -c src/fonctions.h src/fonctions.c -g
	mv fonctions.o ./bin/fonctions.o

clean: 
	rm bin/*.o
	rm *.gch

valgrind: compile
	valgrind ./bin/main
