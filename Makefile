.PHONY: run clean

CFLAGS = -Wall -Wextra
ARGS = 51 + 51 -k 2

cmdcalc: main.o calc.o
	gcc main.o calc.o -o cmdcalc

main.o: main.c
	gcc $(CFLAGS) -c main.c  -o main.o

calc.o: calc.c
	gcc $(CFLAGS) -c calc.c  -o calc.o

run: cmdcalc
	./cmdcalc $(ARGS)

clean: 
	rm -f *.o cmdcalc