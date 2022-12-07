run: compile
	./bin/main

compile: bin/main.o bin/fonctions.o bin/AI.o
	gcc -Wall -o ./bin/main ./bin/main.o ./bin/fonctions.o ./bin/AI.o -g

bin/main.o: src/main.c bin/fonctions.o bin/AI.o
	gcc -Wall -c src/main.c src/fonctions.h src/fonctions.c src/AI.c src/AI.h -g
	mv main.o ./bin/main.o

bin/AI.o: src/AI.h src/AI.c bin/AI.o
	gcc -Wall -c src/AI.c src/AI.h src/fonctions.c src/fonctions.h -g
	mv AI.o ./bin/AI.o

bin/fonctions.o: src/fonctions.h src/fonctions.c
	gcc -Wall -c src/fonctions.h src/fonctions.c -g
	mv fonctions.o ./bin/fonctions.o

clean: 
	rm bin/*.o
	rm src/*.gch

valgrind: compile
	valgrind ./bin/main
