#include "queue.h"
#include <stdio.h>
#include <stdlib.h> //For malloc() and For calloc()

struct Queue {
	uint32_t head;     // Index of the head of the queue.
	uint32_t tail;     // Index of the tail of the queue.
	uint32_t size;     // The number of elements in the queue.
	uint32_t capacity; // Capacity of the queue.
	int64_t *items;    // Holds the items.
};

Queue *queue_create(uint32_t capacity) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	// if sucess alloc memory
	if (q) {
		//init the created queue
		q->head = 0;
		q->tail = 0;
		q->size = 0;
		q->capacity = capacity;
		q->items = (int64_t *)calloc(capacity, sizeof(int64_t));
		//prevent memory leak
		if (!q->items) {
			free(q);
			q = NULL;
		}
	}
	return q;
}

void queue_delete(Queue **q) {
	//use free() function to the memory created by malloc() and calloc() function 
	if (*q && (*q)->items) {
		free((*q)->items);
		free(*q);
		*q = NULL;
	}
	return;
}

bool queue_empty(Queue *q) { return q->size == 0 ? true : false; }

bool queue_full(Queue *q) { return q->size == q->capacity ? true : false; }

uint32_t queue_size(Queue *q) { return q->size; }

bool enqueue(Queue *q, int64_t x) {
	//save the return value
	bool flag = true;
	if (queue_full(q)) {
		flag = false;
	} else {
		//add head item in queue
		q->items[q->head] = x;
		q->size++;
		q->head++;
		q->head %= q->capacity;
	}
	return flag;
}

bool dequeue(Queue *q, int64_t *x) {
	//save the return value
	bool flag = true;
	if (queue_empty(q)) {
		flag = false;
	} else {
		//delete tail item and pass it to *x
		*x = q->items[q->tail];
		q->size--;
		q->tail++;
		q->tail %= q->capacity;
	}
	return flag;
}

void queue_print(Queue *q) {
	printf("====Queue====\n");
	printf("head:%u\n", q->head);
	printf("tail:%u\n", q->tail);
	printf("size:%u\n", q->size);
	printf("capacity:%u\n", q->capacity);
	printf("items:|");
	for (uint32_t i = 0; i < q->size; i++) {
		printf("%ld|", q->items[(i + q->tail) % q->capacity]);
	}
	printf("\n=============\n");
}
