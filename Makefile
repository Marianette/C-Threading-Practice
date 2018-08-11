#
# NWEN 241 Makefile for Programming Assignment #4
#
# Name:
# Student ID:
#

# Do not remove the line below:
.PHONY: clean egame

# Write the rules below, as specified in Task 2.


fgame:	fgame.o common.o
	gcc -o fgame fgame.o common.o 


egame:  egame.o guess.o ttt.o common.o
	gcc -o game egame.o common.o
	gcc -o guess guess.o common.o
	gcc -o ttt ttt.o common.o

common.o: common.h common.c
	  gcc -o common.o -c common.c

fgame.o: game.c common.h common.c
	 gcc -D FORK_IMPL -o fgame.o -c game.c

egame.o: game.c common.h common.c
	 gcc -D FORK_EXEC_IMPL -o egame.o -c game.c

guess.o: guess.c common.h common.c
	 gcc -D FORK_EXEC_IMPL -c guess.c
ttt.o:  ttt.c common.h common.c
	gcc -D FORK_EXEC_IMPL -c ttt.c

clean: 
	rm -f *.o ttt guess game fgame egame
