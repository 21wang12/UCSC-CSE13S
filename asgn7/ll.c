#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll.h"
uint64_t seeks = 0;
uint64_t links = 0;
struct LinkedList {
    uint32_t length;
    Node *head; // Head sentinel node .
    Node *tail; // Tail sentinel node .
    bool mtf;
};

LinkedList *ll_create(bool mtf) {
    LinkedList *ll = malloc(sizeof(LinkedList));
    if(ll){
    	ll->length = 0;
		ll->head = node_create("", "");
		ll->tail = node_create("", ""); //head and tail should be empty
		ll->head->next = ll->tail;
		ll->tail->prev = ll->head;
		ll->mtf = mtf;
    }
    return ll;
}

void ll_delete(LinkedList **ll) {
	Node *x;
    if (*ll){
		while ((*ll)->head != NULL) { // when tail  is not equal to null, meaning still have nodes exits	    
		    x = (*ll)->head->next; // set pointer x to the next node
		    node_delete(&((*ll)->head)); //free current node
		    (*ll)->head = x; //save the new node "head" to x
		}
	}
    free(*ll);
    *ll = NULL; //free the pointer
    return;
}

uint32_t ll_length(LinkedList *ll) {
    return ll->length; //return length
}

Node *ll_lookup(LinkedList *ll, char *oldspeak) {
	seeks++;
	Node *v;
    for (v = ll->head; v != ll->tail; v = v->next) { //forloop to look for whole linked list
        /*if(v->next == ll->tail)*/	
        if(v != ll->head){
        	links++;
        }
        if (!strcmp(oldspeak, v->oldspeak)) { //if oldspeak is found
            //check whether move-to-front option was specified
            if (ll->mtf) {
                v->prev->next = v->next;
                v->next->prev = v->prev;
                v->next = (ll)->head->next;
                v->prev = (ll)->head;
                (ll)->head->next->prev = v;
                (ll)->head->next = v; //move to the node to front
            }
            return v;
        }
    }
   
    return NULL; //return NULL if not founded
}

void ll_insert(LinkedList *ll, char *oldspeak, char *newspeak) {
    if (ll_lookup(ll, oldspeak) == NULL) { //if not found the word
        Node *n = node_create(oldspeak, newspeak);
        n->prev = ll->head;
        n->next = ll->head->next;
        ll->head->next->prev = n;
        ll->head->next = n; //inserted new node to save the word
        ll->length += 1;
    }
}

void ll_print(LinkedList *ll) { //print the whole thing to test out
	if(ll){
		Node *k;
		k = (ll)->head->next;
		while (k->next != NULL) {
		    node_print(k);
		    k = k->next;
		}
	}
    return;
}

