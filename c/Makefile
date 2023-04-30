CC=gcc
CFLAGS=-g -Wall
OBJS=graph.o

test.exe:testapp.o ${OBJS}
	${CC} ${CFLAGS} testapp.o ${OBJS} -o test.exe

testapp.o:testapp.c
	${CC} ${CFLAGS} -c testapp.c -o testapp.o

graph.o:graph.c
	${CC} ${CFLAGS} -c graph.c -o graph.o

clean:
	rm -f *.o
	rm -f *.exe

all:
	make