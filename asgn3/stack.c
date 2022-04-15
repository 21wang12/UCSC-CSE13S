#include "stack.h"
#include <stdio.h>
#include <stdlib.h> //For malloc() and For calloc()

struct Stack {
  uint32_t top;      // Index of the next empty slot.
  uint32_t capacity; // Number of items that can be pushed.
  int64_t *items;    // Array of items , each with type int64_t.
};

Stack *stack_create(uint32_t capacity) {
  Stack *s = (Stack *) malloc(sizeof(Stack));
  // if success alloc
  if (s) {
    s->top = 0;
    s->capacity = capacity;
    s->items = (int64_t *)calloc(capacity, sizeof(int64_t));
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

bool stack_push(Stack *s, int64_t x) {
  bool flag = true;
  if (stack_full(s)) {
    flag = false;
  } else {
    s->items[s->top++] = x;
  }
  return flag;
}

bool stack_pop(Stack *s, int64_t *x) {
  bool flag = true;
  if (stack_empty(s)) {
    flag = false;
  } else {
    s->top--;
    *x = s->items[s->top];
  }
  return flag;
}

void stack_print(Stack *s) {
  printf("====Stack====\n");
  printf("top:%u\n", s->top);
  printf("capacity:%u\n", s->capacity);
  printf("items:|");
  for (uint32_t i = 0; i < s->top; i++) {
    printf("%ld|", s->items[i]);
  }
  printf("\n=============\n");
}
