#include "bubble.h"
#include "util.h"

uint32_t bubble_compare = 0;
uint32_t bubble_move = 0;

void bubble_sort(uint32_t *A, uint32_t n) {
  //begin with the lowest index
	for (uint32_t i = 0; i < n; i++) {
		//the sort the unsorted element which end at n-i
		for (uint32_t j = 1; j < n - i; j++) {
				//gathering statistics: compares
				bubble_compare++;
				//bubble the lager element up
			if (A[j - 1] > A[j]) {
				swap(&A[j - 1], &A[j]);
				//gathering statistics: moves
				bubble_move++;
			}
		}
	}
}
