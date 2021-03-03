
CC = gcc
SRC := $(shell find src/ -name '*.c')

CFLAGS = -g -Wall -I include
POUT = test

radix: src/sort/radix.c tests/radix-main.c
	${CC} tests/radix-main.c ${SRC} ${CFLAGS} -o ${POUT}
	
run: test
	./${POUT}
