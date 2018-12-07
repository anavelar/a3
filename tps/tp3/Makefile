all: tp3

tp3: tp3.o funcoes.o
	gcc -std=c99 funcoes.o tp3.o -o tp3

tp3.o: tp3.c funcoes.h funcoes.c
	gcc -c -std=c99 tp3.c

funcoes.o: funcoes.c funcoes.h
	gcc -c -std=c99 funcoes.c

clean:
	rm *.o
	rm tp3
