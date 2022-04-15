#include <inttypes.h>
#include <stdio.h>

#include "util.h"

void swap(uint32_t *a, uint32_t *b) {
  uint32_t temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(uint32_t *A, uint32_t n) {

  for (uint32_t i = 0; i < n; i++) {
    printf("%13" PRIu32, A[i]);
  }
  if (n != 0) {
    printf("\n");
  }
}

void max_up_to_date(uint32_t *max, uint32_t current) {
  if (current > *max) {
    *max = current;
  }
}

void array_copy(uint32_t *A, uint32_t *B, uint32_t size) {
  for (uint32_t i = 0; i < size; i++) {
    A[i] = B[i];
  }
}
