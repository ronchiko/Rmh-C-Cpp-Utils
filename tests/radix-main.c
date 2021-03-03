
#include <stdio.h>

#include "sort/radix.h"

void print(int* array, int size){
	for(int i = 0; i < size; i++){
		printf("%d", array[i]);
		if(i != size - 1) printf(", ");
	}
	printf("\n");
}

int main(void) {
	int array[7] = {7, 8, 1, 4, 45, 79, 999};
	print(array, 7);
	rsort16(array, 7);
	print(array, 7);
	int array2[7] = {1, 70, 12, 35, 90, 12, 325};
	rsort(array2, 7);
	print(array2, 7);
	return 0;
}
