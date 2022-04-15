#include "stack.h"
#include <stdio.h>
#include <stdlib.h> //For malloc() and For calloc()

/**
 *	@pass : unit-test
 *  @pass : valgrind
 *	@date : 04/26/2021 05:04:34 AM  
 */

//ref@asgn3 : almost same as /asgn3/stack.c

struct Stack {
	uint32_t top;      // Index of the next empty slot.
	uint32_t capacity; // Number of items that can be pushed.
	uint32_t *items;    // Array of items , each with type int32_t.	
};

Stack *stack_create(uint32_t capacity) {
	Stack *s = (Stack *) malloc(sizeof(Stack));
	// if success alloc
	if (s) {
		s->top = 0;
		s->capacity = capacity;
		s->items = (uint32_t *)calloc(capacity, sizeof(uint32_t));
		// if fail alloc
		if (!s->items) {
			free(s);
			s = NULL;
		}
	}
 	return s;
}

void stack_delete(Stack **s) {
	if (*s && (*s)->items) {
		free((*s)->items);
		free(*s);
		*s = NULL;
	}
 	return;
}

bool stack_empty(Stack *s) { return s->top == 0 ? true : false; }

bool stack_full(Stack *s) { return s->top == s->capacity ? true : false; }

uint32_t stack_size(Stack *s) { return s->top; }

bool stack_push(Stack *s, uint32_t x) {
	bool flag = true;
	if (stack_full(s)) {
		flag = false;
	} else {
		s->items[s->top++] = x;
	}
	return flag;
}

//querying a stack about the element at the top of the stack
bool stack_peek(Stack *s, uint32_t *x){
	bool flag = false;
	if (! stack_empty(s)) {
		*x = s->items[s->top-1];
		flag = true;
	}
	return flag;

}

bool stack_pop(Stack *s, uint32_t *x) {
	bool flag = false;
	if (! stack_empty(s)) {
		s->top--;
		*x = s->items[s->top];
		flag = true;
	}
	return flag;
}

void stack_copy(Stack *dst, Stack *src){
	//Assuming that the destination stack dst is properly initialized
	dst->top = src->top;
	
	dst->capacity = src->capacity;
	//copy items from src to dst
	for(uint32_t i =0; i < src->capacity; i++){
		dst->items[i] = src->items[i];
	}
	return;

}

void stack_print(Stack *s, FILE * outfile, char *cities []) {
	for (uint32_t i = 0; i < s->top; i++) {
		fprintf ( outfile , "%s", cities [s-> items [i]]);
		if (i + 1 != s-> top ) {
			fprintf ( outfile , " -> ");
		}
  	}
  	fprintf ( outfile , "\n");
}
