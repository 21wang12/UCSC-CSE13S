CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: encode-test decode-test

encode-test: encode.o pq.o node.o code.o util.o io.o huffman.o stack.o
	$(CC)  -o encode-test encode.o pq.o node.o code.o util.o io.o huffman.o stack.o

decode-test: decode.o pq.o node.o code.o util.o io.o huffman.o stack.o
	$(CC)  -o decode-test decode.o pq.o node.o code.o util.o io.o huffman.o stack.o

unit-test: test.o pq.o node.o code.o util.o io.o huffman.o stack.o
	$(CC)  -o unit-test test.o pq.o node.o code.o util.o io.o huffman.o stack.o

entropy: entropy.c
	$(CC) $(CFLAGS) -o entropy entropy.c

encode.o :encode.c
	$(CC) $(CFLAGS) -c encode.c
	
decode.o :decode.c
	$(CC) $(CFLAGS) -c decode.c

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

pq.o: pq.c pq.h
	$(CC) $(CFLAGS) -c pq.c
	
	
node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c
	
code.o: code.c code.h defines.h
	$(CC) $(CFLAGS) -c code.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c
	
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
	
huffman.o: huffman.c huffman.h
	$(CC) $(CFLAGS) -c huffman.c
	
util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c
	
	
clean: 
	rm -rf  *.o unit-test encode-test decode-test
	
scan-build: clean
	scan-build make
	
format:
	clang-format -style=file -i *.c *.h
