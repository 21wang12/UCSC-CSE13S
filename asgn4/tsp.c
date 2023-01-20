/**
 *	@brief command line option:
 *	@param h : Prints out a help message describing the purpose of the graph and the command-line optionsit accepts, exiting the program afterwards. Refer to the reference program in the resources repo foran idea of what to print.

 *	@param v : Enables verbose printing. If enabled, the program prints out all Hamiltonian paths found as well as the total number of recursive calls to dfs().

 *	@param u : Specifies the graph to be undirected.

 *	@param i infile : Specify the input file path containing the cities and edges of a graph. If not specified, the default input should be set as stdin.

 *	@param o outfile : Specify the output file path to print to. If not specified, the default output should be set as stdout.
*/


#include <stdbool.h> // For bool
#include <stdio.h>   // For printf(), fgets(), fscanf()
#include <stdlib.h>  // For atoi() and strtoul()  inspired by asgn3
#include <unistd.h>  // For getopt()
#include <string.h>	 // For strdup()

#include "graph.h"
#include "path.h"
#include "stack.h"
#include "util.h"
#include "vertices.h"

#define OPTIONS "hvui:o:"
#define MAX_LINE 100
#define TRIPLE 3

int main(int argc, char **argv){

	int opt=0;
	//ref@asgn4.pdf : Specifics 4. make defalut graph directed
	bool undirected = false;
	bool verbose_print = false;	
	
	FILE *infp = stdin;
	FILE *outfp = stdout;
	//get the argument comes from CLI
	while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
		switch (opt) {
			case 'h': 
				tsp_help();
				exit(0);
				break;
			case 'v':
				verbose_print = true;
			 	break;
			case 'u':
			    undirected = true;
			 	break;
			case 'i':
				if((infp = fopen(optarg,"r")) == NULL){
					printf("Error: failed to open infile.\n");
					exit(1);
				}
				break;
			case 'o':
				if((outfp = fopen(optarg,"w")) == NULL){
					printf("Error: failed to open outfile.\n");
					exit(1);
				}
			  	break;
		}
	}


	/** read graph from infile*/
	uint32_t n;
	//read the first number, which is the number of vetices
	fscanf(infp,"%u\n",&n);	
	//if there only have one vertex 
	if(n <= 1){
		printf("There's nowhere to go.\n");
		fclose(infp);
		fclose(outfp);
		exit(1);
	}
	
	//ref@asgn4.pdf : Specifics 2.
	if(n > VERTICES){
		printf("Error: the number specified is greater than VERTICES\n");
		fclose(infp);
		fclose(outfp);
		exit(1);
	}
	
	//read n city names
	char *cities[n];
	char line[MAX_LINE];
	int line_length=0;
	for(uint32_t i = 0; i < n; i++){
		line_length = m_getline(line,MAX_LINE,infp);
		//ref@asgn4.pdf : Specifics 3.
		if(line_length == 0){
			printf("Error: the line is malformed.\n");
			for(uint32_t j = 0; j < i; j++){
				free(cities[j]);
			}
			fclose(infp);
			fclose(outfp);
			exit(1);
		}
		//ref@asgn4.pdf : Specifics 3
		cities[i] = (char *)strdup(line);
		cities[i][line_length-1] = '\0';
	}

	//create graph
	Graph *g = graph_create(n,undirected);
	//read edges<u,v,w> from infile
	uint32_t u,v,w;
	int match_items = 0;
	while((match_items = fscanf(infp,"%u %u %u",&u,&v,&w))!=EOF){
		//printf("%u %u %u\n",u,v,w);
		if(match_items != TRIPLE){
			printf("Error: the line is malformed.\n");
			for(uint32_t j = 0; j < n; j++){
				free(cities[j]);
			}
			graph_delete(&g);
			fclose(infp);
			fclose(outfp);
			exit(1);
		}
		graph_add_edge(g,u,v,w);
	}
	//record current path and shortest path
	Path *curr = path_create();
	Path *shortest = path_create();
	//use dfs() function to find Hamiltonian path
	dfs(g, START_VERTEX, curr, shortest, cities, outfp,verbose_print);
	
	//print shortest path
	path_print(shortest,outfp,cities);
	printf("Total recursive calls: %d\n",recursive);


	//delete path
	path_delete(&curr);
	path_delete(&shortest);
	
	//delete graph
	graph_delete(&g);
	
	//free cities created by strdup()
	for(uint32_t i = 0; i < n; i++){
		free(cities[i]); 	
	}
	
	//close file pointer opened by fopen()
	fclose(infp);
	fclose(outfp);
	
	return 0;
}
