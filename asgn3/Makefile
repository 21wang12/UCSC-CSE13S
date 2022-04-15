CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: sorting

unit-test: test.o queue.o stack.o quick.o util.o
	$(CC)  -o unit-test test.o queue.o stack.o quick.o util.o

sorting: sorting.o bubble.o shell.o quick.o util.o stack.o queue.o
	$(CC)  -o sorting-test sorting.o bubble.o shell.o quick.o util.o stack.o queue.o
	
sorting.o: sorting.c bubble.h shell.h quick.h
	$(CC) $(CFLAGS) -c sorting.c
	
	
bubble.o: bubble.c bubble.h util.h
	$(CC) $(CFLAGS) -c bubble.c

shell.o: shell.c shell.h gaps.h
	$(CC) $(CFLAGS) -c shell.c

quick.o: quick.c stack.h queue.h
	$(CC) $(CFLAGS) -c quick.c
	
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
	
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c
	
util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

clean: 
	rm -rf  *.o sorting-test unit-test
	
scan-build: clean
	scan-build make
	
format:
	clang-format -style=file -i *.c *.h
