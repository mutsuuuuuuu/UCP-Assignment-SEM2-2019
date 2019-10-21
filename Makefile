CFLAGS = -Wall -ansi -pedantic -Werror -std=c89
EXEC = TicTacToe
OBJ = TicTacToe.o userInterface.o readFile.o board.o log.o LinkedList.o ListNode.o writeFile.o

CFLAGS += -D ${MODE}

Program: ${OBJ}
	gcc ${OBJ} -o TicTacToe
	
TicTacToe.o: TicTacToe.c TicTacToe.h userInterface.h LinkedList.h
	gcc ${CFLAGS} -c TicTacToe.c

readFile.o: readFile.c readFile.h
	gcc ${CFLAGS} -c readFile.c

board.o: board.c board.h log.h LinkedList.h
	gcc ${CFLAGS} -c board.c

log.o: log.c log.h
	gcc ${CFLAGS} -c log.c

LinkedList.o: LinkedList.c ListNode.h LinkedList.h log.h
	gcc ${CFLAGS} -c LinkedList.c

ListNode.o: ListNode.h ListNode.c log.h
	gcc ${CFLAGS} -c ListNode.c

writeFile.o: writeFile.h writeFile.c LinkedList.h
	gcc ${CFLAGS} -c writeFile.c

userInterface.o: LinkedList.h board.h readFile.h writeFile.h userInterface.c userInterface.h
	gcc ${CFLAGS} -c userInterface.c

clean :
	rm -f ${OBJ} ${EXEC}
