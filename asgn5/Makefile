CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic
MATHLIB = -lm

all: encode-test decode-test error entropy

unit-test: test.o bv.o util.o
	$(CC)  -o unit-test test.o bv.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

encode-test: encode.o bm.o bv.o hamming.o util.o
	$(CC)  -o encode-test encode.o bm.o bv.o hamming.o util.o
	
decode-test: decode.o bm.o bv.o hamming.o util.o
	$(CC)  -o decode-test decode.o bm.o bv.o hamming.o util.o
	
entropy: entropy.c
	$(CC) $(CFLAGS) $(MATHLIB) -o entropy entropy.c
	
error: error.c
	$(CC) $(CFLAGS) -o error error.c
	
encode.o: encode.c
	$(CC) $(CFLAGS) -c encode.c

decode.o: decode.c
	$(CC) $(CFLAGS) -c decode.c
	
bv.o: bv.c bv.h
	$(CC) $(CFLAGS) -c bv.c

bm.o: bm.c bm.h
	$(CC) $(CFLAGS) -c bm.c

hamming.o: hamming.c hamming.h
	$(CC) $(CFLAGS) -c hamming.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

clean: 
	rm -rf  *.o entropy error encode-test decode-test unit-test
	
scan-build: clean
	scan-build make
	
format:
	clang-format -style=file -i *.c *.h
