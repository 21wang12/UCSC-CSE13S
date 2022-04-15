#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "defines.h"
#include "io.h"
#include "huffman.h"
#include "pq.h"
#include "node.h"
#include "header.h"
#include "util.h"
#include "stack.h"

#define OPTIONS "hi:o:v"
typedef struct TEST TEST;
struct TEST{
	int a;
	int arr[10];
};


//read:https://unix.stackexchange.com/questions/194544/are-commands-in-a-pipeline-run-simultaneously
//solution:https://stackoverflow.com/questions/43283418/make-multiple-pipe-with-waiting-for-return-code-of-each-process
int main (/*int argc, char *argv[]*/){
	int infile = 0;
	int outfile = 1;
	//close(infile);
	//sleep(2);
	infile = open("/dev/stdin",O_RDONLY,0);
	Header h;
	
	read_bytes(infile,(uint8_t *)&h,sizeof(Header));
	uint8_t tree[h.tree_size];
	memset(tree,0,sizeof(tree));
	fprintf(stderr,"tree_size:%u\n",h.tree_size);
	/*
	int n = 0;
	while(n<h.tree_size){
		n+=read(infile,&tree[n],1);
	}
	*/
	int n = read_bytes(infile,tree,h.tree_size);
	fprintf(stderr,"\nn=%d\n",n);
	fprintf(stderr,"\n===unit-test====\n");
	for(int i = 0; i<h.tree_size; i++){
		fprintf(stderr,"%c",tree[i]);
	}
	fprintf(stderr,"\n===write_tree====\n");
	Node *root = rebuild_tree(h.tree_size,tree);//TODO  :maybe cause error
	write_tree(outfile,root);  //printtree is SAME with the example binary
	close(infile);
	close(outfile);
	return 0;
}
