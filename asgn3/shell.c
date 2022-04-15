#include "shell.h"
#include "gaps.h"
#include "util.h"

uint32_t shell_move = 0;
uint32_t shell_compare = 0;

void shell_sort(uint32_t *A, uint32_t n) {

  // find fist gap idx
  uint32_t idx = GAPS - 1;
  while (gaps[idx] < n / 2) { // ref shell: N/2
    idx--;
  }
  

  for (uint32_t gap; idx < GAPS; ++idx) {
    gap = gaps[idx];
    // do insertion sort
    for (uint32_t i = gap; i < n; i++) {
      // insert a[j] element in assending sequence
      for (uint32_t j = i; j > gap - 1; j -= gap) {
        shell_compare++; // compare count
        // if the previous element is less than curent element, then swap them
        if (A[j] < A[j - gap]) {
          shell_move++; // move count
          swap(&A[j], &A[j - gap]);
        }
      }
    }
  }
}
