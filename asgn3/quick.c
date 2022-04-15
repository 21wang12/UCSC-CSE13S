#include "quick.h"
#include "queue.h"
#include "stack.h"
#include "util.h"
#include <assert.h> //For assert()
#include <stdio.h>  //For declared identifier 'NULL'

#define STACK_INIT_CAPACITY 1000
#define QUEUE_INIT_CAPACITY 1000

uint32_t max_stack_size = 0;
uint32_t max_queue_size = 0;

uint32_t quick_move = 0;
uint32_t quick_compare = 0;


//ref to: asgn3.pdf@partition()
int64_t partition(uint32_t *A, int64_t lo, int64_t hi) {
  uint32_t pivot =
      A[lo + (hi - lo) / 2]; // choose the middle emelent in A[lo,hi] as pivot
  int64_t i = lo - 1;
  int64_t j = hi + 1;

  while (i < j) {
    do {
      i++;
      quick_compare++;
    } while (A[i] < pivot);

    do {
      j--;
      quick_compare++;
    } while (A[j] > pivot);
    
    if (i < j) {
      quick_move++;
      swap(&A[i], &A[j]);
    }
  }
  return j;
}

//ref to: asgn3.pdf@quick_sort_stack()
void quick_sort_stack(uint32_t *A, uint32_t n) {
  int64_t p = 0;
  int64_t lo = 0, hi = n - 1;
  Stack *s = stack_create(STACK_INIT_CAPACITY);
  stack_push(s, lo);
  stack_push(s, hi);
  max_stack_size = 0;
  max_up_to_date(&max_stack_size, stack_size(s));
  while (stack_size(s) != 0) {
    stack_pop(s, &hi);
    stack_pop(s, &lo);
    p = partition(A, lo, hi);
    if (lo < p) {
      stack_push(s, lo);
      stack_push(s, p);
      max_up_to_date(&max_stack_size, stack_size(s));
    }
    if (hi > p + 1) {
      stack_push(s, p + 1);
      stack_push(s, hi);
      max_up_to_date(&max_stack_size, stack_size(s));
    }
  }
  //free the stack
  stack_delete(&s);
  assert(s == NULL);
}

//ref to: asgn3.pdf@quick_sort_queue
void quick_sort_queue(uint32_t *A, uint32_t n) {
  int64_t p = 0;
  int64_t lo = 0, hi = n - 1;

  Queue *q = queue_create(QUEUE_INIT_CAPACITY);
  enqueue(q, lo);
  enqueue(q, hi);
  max_queue_size = 0;
  max_up_to_date(&max_queue_size, queue_size(q));
  while (queue_size(q) != 0) {
    dequeue(q, &lo);
    dequeue(q, &hi);
    p = partition(A, lo, hi);
    if (lo < p) {
      enqueue(q, lo);
      enqueue(q, p);
      max_up_to_date(&max_queue_size, queue_size(q));
    }
    if (hi > p + 1) {
      enqueue(q, p + 1);
      enqueue(q, hi);
      max_up_to_date(&max_queue_size, queue_size(q));
    }
  }
  //free the queue
  queue_delete(&q);
  assert(q == NULL);
}
