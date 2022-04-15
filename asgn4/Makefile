CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: tsp

tsp: tsp.o graph.o path.o stack.o util.o
	$(CC)  -o tsp-test tsp.o graph.o path.o stack.o util.o

unit-test: test.o graph.o path.o stack.o vertices.h
	$(CC)  -o tsp-test test.o graph.o path.o stack.o

tsp.o: tsp.c graph.h path.h vertices.h 
	$(CC) $(CFLAGS) -c tsp.c
	
graph.o: graph.c graph.h vertices.h
	$(CC) $(CFLAGS) -c graph.c	
	
path.o: path.c path.h stack.h
	$(CC) $(CFLAGS) -c path.c
	
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
	
	
util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

clean: 
	rm -rf  *.o tsp-test unit-test
	
scan-build: clean
	scan-build make
	
format:
	clang-format -style=file -i *.c *.h
