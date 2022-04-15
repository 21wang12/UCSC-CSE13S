#include <stdbool.h> // For bool
#include <stdio.h>   //For printf()
#include <stdlib.h>  //For atoi() and strtoul()  inspired by instructor:Eric Hernandez in question@381:https://piazza.com/class/kmfs2bmdr9syz?cid=381
#include <unistd.h>  // For getopt()

#include "bubble.h"
#include "quick.h"
#include "shell.h"
#include "util.h"

#define OPTIONS "absqQr:n:p:"
#define INPUT_BASE 10
#define INIT_SEED 13371453
#define INIT_ARRAY_SIZE 100

/**
 * @brief command line option:
 * @param a : Enables all sorting algorithms.
 * @param b : Enables Bubble Sort.
 * @param s : Enables Shell Sort.
 * @param q : Enables the Quicksort that utilizes a stack.
 * @param Q : Enables the Quicksort that utilizes a queue.
 * @param r seed : Set the random seed to seed. The default seed should be
 * 				   13371453.
 * @param n size : Set the array size to size. The default size should be 100.
 * @param p elements : Print out elements number of elements from the array. 
 *					   The default number of elements to print out should be 100. 
 *					   If the size of the array is less than the 
 *					   specified number of elements to print, print out the
 * 					   entire array and nothing more.
 */

int main(int argc, char **argv) {
	int opt;
	bool run_bubble = false, run_shell = false, run_quick_stack = false, run_quick_queue = false;
	uint32_t seed = INIT_SEED, size = INIT_ARRAY_SIZE, print_elem_cnt = 100;

	//get the argument comes from CLI
	while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
	switch (opt) {
		case 'a': // enable all sort algo
			run_bubble = true;
			run_shell = true;
			run_quick_stack = true;
			run_quick_queue = true;
			break;
		case 'b':
		  	run_bubble = true;

		  break;
		case 's':
		  	run_shell = true;
		 	break;
		case 'q':
			run_quick_stack = true;
			break;
		case 'Q':
		  	run_quick_queue = true;
		  	break;
		case 'r':
		  	seed = strtoul(optarg, NULL, INPUT_BASE);
		  	break;
		case 'n':
		  	size = strtoul(optarg, NULL, INPUT_BASE);
		  	break;
		case 'p':
		  	print_elem_cnt = strtoul(optarg, NULL, INPUT_BASE);
		  	break;
		}
	}
	
	
	// create Array
	uint32_t A[size];
	// backup to shuffle A
	uint32_t B[size];
	// set the random seed
	srand(seed);

	for (uint32_t i = 0; i < size; i++) {
		A[i] = rand();
		B[i] = A[i]; // backup
	}

	if (run_bubble) {
		bubble_sort(A, size);
		printf("Bubble Sort\n");
		printf("%u elements, %u moves, %u compares\n", size, bubble_move, bubble_compare);
		if (size <= print_elem_cnt) {
		  print_array(A, size);
		} else {
		  print_array(A, print_elem_cnt);
		}
	}

	if (run_shell) {
		// reshuffle A
		array_copy(A, B, size);

		shell_sort(A, size);
		printf("Shell Sort\n");
		printf("%u elements, %u moves, %u compares\n", size, shell_move, shell_compare);
		if (size <= print_elem_cnt) {
		  	print_array(A, size);
		} else {
		 	 print_array(A, print_elem_cnt);
		}
	}

	if (run_quick_stack) {
		// reshuffle A
		array_copy(A, B, size);
		quick_sort_stack(A, size);
		printf("Quick Sort (Stack)\n");
		printf("%u elements, %u moves, %u compares\n", size, quick_move, quick_compare);
		printf("Max stack size: %u\n", max_stack_size);
		if (size <= print_elem_cnt) {
		  print_array(A, size);
		} else {
		  print_array(A, print_elem_cnt);
		}
	}

	if (run_quick_queue) {
		// reshuffle A
		array_copy(A, B, size);
		quick_move = 0;
		quick_compare = 0;
		quick_sort_queue(A, size);
		printf("Quick Sort (Queue)\n");
		printf("%u elements, %u moves, %u compares\n", size, quick_move, quick_compare);
		printf("Max queue size: %u\n", max_stack_size);

		if (size < print_elem_cnt) {
		  	print_array(A, size);
		} else {
		  	print_array(A, print_elem_cnt);
		}
	}

	return 0;
}
