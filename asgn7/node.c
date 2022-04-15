#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

#define strdup(s) strcpy(malloc(strlen(s) + 1), s) //mimic strdup

Node *node_create(char *oldspeak, char *newspeak) {
    Node *n = (Node *) malloc(sizeof(Node));
    if(n){
		if (oldspeak == NULL) {
		    n->oldspeak = NULL; //if head and node, return NULL
		} else {
		    n->oldspeak = strdup(oldspeak); //else use strdup oldspeak
		}

		if (newspeak == NULL) {
		    n->newspeak = NULL; //if head and node, return NULL
		} else {
		    n->newspeak = strdup(newspeak); //else use strdup newspeak
		}
		n->next = NULL;
		n->prev = NULL;
    }
    return n;
}

void node_delete(Node **n) {
	if(*n){
		free((*n)->oldspeak);
    	free((*n)->newspeak); //delete the content inside each node
	}
    free(*n); //delete the pointer
    *n = NULL; //set itself to null
    return;
}

void node_print(Node *n) {
    if (n->newspeak == NULL) {
        printf("%s\n", n->oldspeak); //when no newspeak, print oldspeak only
    } else {
        printf("%s -> %s\n", n->oldspeak, n->newspeak); //print both if newspeak exit
    }
}


