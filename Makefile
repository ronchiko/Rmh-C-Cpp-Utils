
CC = gcc
SRC := $(shell find src/ -name '*.c')

VF := $(shell find ./ -name '*.swp')

CFLAGS = -g -Wall -I include
POUT = test.out

radix: src/sort/radix.c tests/radix-main.c
	${CC} tests/radix-main.c ${SRC} ${CFLAGS} -o ${POUT}

run: test
	./${POUT}

${VF}:
	rm $@

clean: ${VF}

