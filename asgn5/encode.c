#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/stat.h>

#include "bm.h"
#include "hamming.h"
#include "util.h"

#define OPTIONS "hi:o:"

#define G_ROWS  4
#define G_COLS  8
uint8_t m_G[G_ROWS][G_COLS] = {
	{1,0,0,0,0,1,1,1},
	{0,1,0,0,1,0,1,1},
	{0,0,1,0,1,1,0,1},
	{0,0,0,1,1,1,1,0},
};

int main (int argc, char *argv[]){
	int opt=0;
	FILE *infp = stdin;
	FILE *outfp = stdout;
	
	//Parse the command-line options
	while((opt=getopt(argc, argv, OPTIONS)) != -1){
		switch (opt) {
			case 'h': 
				help_encode();
				exit(0);
				break;
			case 'i':
				if((infp = fopen(optarg,"rb")) == NULL){
					printf("Error: failed to open infile.\n");
					exit(1);
				}
				break;
			case 'o':
				if((outfp = fopen(optarg,"wb")) == NULL){
					printf("Error: failed to open outfile.\n");
					exit(1);
				}
			  	break;
		}
	}
	
	//ref@asgn5.pdf : handdle file permmision
	struct stat statbuf;
	fstat(fileno(infp), &statbuf);
	fchmod(fileno(outfp), statbuf.st_mode);
	
	//Initialize the generator matrix G using bm_create().
	BitMatrix *G = bm_create(G_ROWS,G_COLS);
	for(uint32_t i = 0; i < G_ROWS; i++){
		for(uint32_t j = 0; j < G_COLS; j++){
			if(m_G[i][j]){
				bm_set_bit(G,i,j);
			}
		}
	}
	
	//Read a byte from the specified file stream or stdin with fgetc().
	uint8_t msg = 0;
	uint8_t code = 0;
	msg = fgetc(infp);
	while(!feof(infp)){
		//printf("%d\n",msg);
		//Generate the Hamming(8,4) codes for both the upper and lower nibble with ham_encode()
		code = encode(G,lower_nibble(msg));
		fputc(code,outfp);
		//printf("%d\n",code);
		code = encode(G,upper_nibble(msg));
		fputc(code,outfp);
		//printf("%d\n",code);
		//printf("====\n");
		msg = fgetc(infp);
	}
	//fputc('\n',stdout);
	//close file pointer and free allocated memory
	bm_delete(&G);
	fclose(infp);
	fclose(outfp);
	
	return 0;
}
