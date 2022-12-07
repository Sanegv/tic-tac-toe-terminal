# Tic tac toe

## 1. Files
 This repo contains the readme that you're reading, a Makefile, and two folders: 
 /src  contains fonctions.c and fonctions.h, which are the files containing all the actual code, and main.c simply starts it.
 /bin contains the compiled main program, and the different .o files.

## 2. How to use
 Given that you are using ubuntu, simply run bin/main, or just use the "make" command, and it will recompile and run automatically.
 If you're using another OS, you'll have to recompile the source code for yourself.
 Then, it's a basic tic tac toe. The game automatically starts, and you can only play against another human being (or yourself) on the same terminal, for now.

## 3. Future improvements
- I'll soon add a simple "AI" that plays a random move when it's its turn
- After that, I'll code an AI that plays the optimal move every time 
- I might add an intermediate level that tries to win and block you, but without necessarily playing the perfect move
- In the long term, I'll make a simple GUI