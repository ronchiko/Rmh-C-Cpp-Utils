
#include <stdio.h>
#include <stdlib.h>

#include "sort/radix.h"
#include "bsearch.h"

#define SIZE 11

int main(void) {
	int array[SIZE] = {1, 5, 7, 8 , 9 , 1, 5, 1, 40, 134, 8};
	float farr[6] = {-3.0f, 1.0f, 7.8f, 12.03f, 124.f, 1003.45f};
	rsort16(array, SIZE);
	
	int index = ibinsrch(array, SIZE, 40);
	printf("Index of 40: %d\n", index);
	
	index = fbinsrch(farr, 6, 1003.45f);
	printf("Index of 1003.45: %d\n", index);

	return 0;
}
