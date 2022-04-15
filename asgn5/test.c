#include <stdio.h>


#include "bv.h"
#include "util.h"


int main(){
	uint8_t u8 = 0;
	uint8_t set_bit = 1;
	/*
	
	*/
	BitVector *bv0 = bv_create(24);
	bv_set_bit(bv0,0);
	bv_set_bit(bv0,2);
	bv_set_bit(bv0,4);
	bv_set_bit(bv0,6);
	for(uint32_t i = 0; i < 8; i++){
		if(bv_get_bit(bv0,i)){
			u8 |= set_bit;
		}
		set_bit <<= 1;
	}
	
	for(int i = 0; i < 8; i++){
		printf("%d\t",(u8&(1<<i))==0?0:1);
	}

	printf("\n%d\n",23/8);
	BitVector *bv = bv_create(24);
	bv_set_bit(bv,0);
	bv_print(bv);
	bv_clr_bit(bv,0);
	bv_print(bv);
	bv_xor_bit(bv,0,1);
	bv_print(bv);
	bv_xor_bit(bv,0,1);
	bv_print(bv);
	
	bv_delete(&bv);
	
	return 0;


}
