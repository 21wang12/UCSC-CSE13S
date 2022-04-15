#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdint.h>

void swap(uint32_t *a, uint32_t *b);

void print_array(uint32_t *A, uint32_t n);

void max_up_to_date(uint32_t *max, uint32_t current);

void array_copy(uint32_t *A, uint32_t *B, uint32_t size);



#endif
