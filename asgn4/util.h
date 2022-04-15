#ifndef __UTIL_H__
#define __UTIL_H__

#include "graph.h"
#include "path.h"
#include "stack.h"
#include "vertices.h"
#include <stdint.h>

void tsp_help();

//total number of recursive calls to dfs().
extern uint32_t recursive;
//TODO: implement in util.c
void dfs ( Graph *G, uint32_t v, Path *curr , Path * shortest , char * cities [], FILE * outfile,bool verbose );

//ref@<<K&R C programming>>
int m_getline(char *line,int max,FILE *fp);

#endif
