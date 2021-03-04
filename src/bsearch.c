
#include "bsearch.h"

#include <stdint.h>

typedef uint8_t byte;

static int r_ibinsrch(int* array, int s, int e, int v) {
	if(s + 1 >= e || s >= e) return -1;
	int m = (s + e) / 2;
	if(array[m] == v) return m;
	return array[m] < v ? r_ibinsrch(array, m, e, v) : r_ibinsrch(array, s, m, v);
}


static int r_fbinsrch(float* array, int s, int e, float v) {
	if(s + 1 >= e || s >= e) return -1;
	int m = (s + e) / 2;
	if(array[m] == v) return m;
	return array[m] < v ? r_fbinsrch(array, m, e, v) : r_fbinsrch(array, s, m, v);
}

int ibinsrch(int* array, int len, int value) {
	return r_ibinsrch(array, 0, len, value);
}

int fbinsrch(float* a, int len, float v){
	return r_fbinsrch(a, 0, len, v);
}

