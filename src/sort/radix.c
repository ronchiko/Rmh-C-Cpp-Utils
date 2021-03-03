
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort/radix.h"

#define MASK 0xF
#define GET_HEXIT(i) ((in[i] >> (iter << 2)) & MASK)
#define GET_DIGIT(i) (in[i] / div % 10)

static inline int ipow(int b, int e){
	int o = 1;
	for(int i = 0; i < e; i++) o *= b;
	return o;
}

void rsort(int* in, int size) {
	int* out = malloc(size * sizeof(int)), *oout = out, *oin = in;
	int iter = 0;
	while(iter < 12) {
		int div = ipow(10, iter);
		int prefixSum[10] = {0};
		for(int i = 0; i < 10; i++) prefixSum[i] = 0;

		for(int i = 0; i < size; i++)
			++prefixSum[GET_DIGIT(i)];
		
		for(int i = 1; i < 10; i++) 
			prefixSum[i] += prefixSum[i - 1];
		
		for(int i = size - 1; i >= 0; i--) {
			out[--prefixSum[GET_DIGIT(i)]] = in[i];
		}

		iter++;
		void* temp = in;
		in = out;
		out = temp;
	}

	if(oin != in)
		memcpy(in, oout, sizeof(int) * size);
	free(oout);
}

void rsort16(int* in, int size) {
	int* out = malloc(size * sizeof(int));
	int* oout = out;
	int* oin = in;	// Copy of the original input address

	int iter = 0;
	while(iter < sizeof(int) * 2){
		// Prefix sum array
		int prefixSum[16];
		for(int i = 0; i < 16; i++) prefixSum[i] = 0;

		for(int i = 0; i < size; i++)
			++prefixSum[GET_HEXIT(i)];
		
		// Compute prefix sum
		for(int i = 1; i < 16; i++) 
			prefixSum[i] += prefixSum[i - 1];
		// Sub sort into the output array
		for(int i = size - 1; i >= 0; i--)
			out[--prefixSum[GET_HEXIT(i)]] = in[i];
		
		iter++;
		// Swap pointers
		void* temp = out;
		out = in;
		in = temp;
	}
	
	// If we are on an odd number of iterations, copy to original array
	if(oin != in)
		memcpy(in, oout, sizeof(int) * size);
	free(oout);	// Free helper array
}
