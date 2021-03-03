#pragma once

#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint;

// Preferoms a base 10 radix sort
void rsort(int* arr, int n);
// Base 16 radix sort
void rsort16(int* arr, int n);

