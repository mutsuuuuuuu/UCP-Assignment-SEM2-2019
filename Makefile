CFLAGS = -Wall -g -ansi -pedantic -Werror 
EXEC = program

Program : TicTacToe.o readFile.o board.o
	gcc TicTacToe.o readFile.o board.o -o program

TicTacToe.o : TicTacToe.h TicTacToe.c readFile.h board.h
	gcc ${CFLAGS} -c TicTacToe.c 
	
readFile.o: readFile.c readFile.h
	gcc ${CFLAGS} -c readFile.c

board.o: board.c board.h
	gcc ${CFLAGS} -c board.c
clean : 
	rm -f TicTacToe.o readFile.o board.o program 
