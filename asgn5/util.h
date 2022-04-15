#ifndef __UTIL_H__
#define __UTIL_H__
#include <stdint.h>
unsigned getbits(unsigned x, int p, int n);

uint8_t lower_nibble(uint8_t val);

uint8_t upper_nibble(uint8_t val);

uint8_t pack_byte(uint8_t upper, uint8_t lower);

void help_encode(void);

void help_decode(void);

#endif
