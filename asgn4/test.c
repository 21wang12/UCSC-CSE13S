#include <stdio.h>
#include <assert.h>

#include <string.h> //For strdup
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "path.h"
#include "vertices.h"

#define MAX_LINE 100

int m_getline(char *line,int max,FILE *fp){
	if(fgets(line,max,fp) == NULL){
		return 0;
	}
	return strlen(line);
}

int main(){

	char line[200];
	fgets(line,200,fp);
	
	printf("%s",line);
	/** @brief : test Graph

	
	Graph *g = graph_create(10,true);
	
	printf("here");
	graph_print(g);
	
	graph_delete(&g);
	assert(g==NULL);
	 */
	 
	/** @breif : test Stack
	 
	char *cities[] = {"London","New York","Beijing","Indian"};
	Stack *s = stack_create(4);
	Stack *s_dst = stack_create(4);
	printf("stack empty:%s\n",stack_empty(s)?"true":"false");
	printf("stack full:%s\n",stack_full(s)?"true":"false");
	stack_push(s, 0);
	stack_push(s, 1);
	stack_push(s, 2);
	stack_push(s, 3);
	printf("stack empty:%s\n",stack_empty(s)?"true":"false");
	printf("stack full:%s\n",stack_full(s)?"true":"false");
	printf("stack size:%u\n",stack_size(s));
	uint32_t elem;
	stack_pop(s,&elem);
	printf("pop:%u\n",elem);
	stack_peek(s,&elem);
	printf("peek:%u\n",elem);
	stack_pop(s,&elem);
	printf("pop:%u\n",elem);
	stack_print(s,stdout,cities);
	stack_push(s, 2);
	stack_push(s, 3);
	stack_print(s,stdout,cities);
	stack_copy(s_dst,s);
	stack_print(s_dst,stdout,cities);
	printf("stack empty:%s\n",stack_empty(s_dst)?"true":"false");
	printf("stack size:%u\n",stack_size(s_dst));
	stack_delete(&s);
	stack_delete(&s_dst);
	assert(s==NULL);
	assert(s_dst == NULL);
	 */
	 
	 
	/** @brief : test Path
	 
	 
	 	
	 */
	 
	 
	/** @brief : test read file

	
	char *input_file = "./graphs/ucsc.graph";
	FILE *fp = fopen(input_file,"r");
	uint32_t n;
	fscanf(fp,"%u\n",&n);	//read the first number
	printf("%u\n",n);
	
	
	char *cities[n];
	char line[MAX_LINE];
	int line_length=0;
	for(uint32_t i = 0; i < n; i++){
		line_length = m_getline(line,MAX_LINE,fp);
		cities[i] = (char *)strdup(line);
		
		//Note: using fgets() will leave in the newline character('\n') at the end, so you will manually have to change it to the null character('\0') to remove it.
		cities[i][line_length-1] = '\0';
	}
	
	for(uint32_t i = 0; i < n; i++){
		printf("%s\t%lu\n",cities[i],strlen(cities[i]));
	}
	
	for(uint32_t i = 0; i < n; i++){
		free(cities[i]); //free strdup	
	}
	
	uint32_t a,b,c;
	//Scan the input line by line using fscanf() until the end-of-file is reached
	while(fscanf(fp,"%u %u %u",&a,&b,&c)!=EOF){
		printf("%u %u %u\n",a,b,c);
	}
	
	fclose(fp);
	 */
	 
	Path *p = path_create();
	path_delete(&p);
	 
	return 0;
}

