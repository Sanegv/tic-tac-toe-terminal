# Tic tac toe

## 1. Files
 This repo contains the readme that you're reading, a Makefile, and two folders: 
 /src  contains fonctions.c and fonctions.h, which are the files containing all the actual code, and main.c simply starts it.
 /bin contains the compiled main program, and the different .o files.

## 2. How to use
 If you are using ubuntu, simply run bin/main, or just use the "make" command, and it will recompile and run automatically.
 If you're using another OS, you'll have to recompile the source code for yourself.
 Once you rune the program, a menu will open and ask you if you want to play player v. player, or against an AI. If you choose AI, you'll get to choose which turn you play, or let the computer pick one randomly.
 For now, there is only one AI difficulty : it only plays random moves.

## 3. Future improvements
- I'll code an AI that plays the optimal move every time 
- I might add an intermediate level that tries to win and block you, but without necessarily playing the perfect move
- In the long term, I'll make a simple GUI