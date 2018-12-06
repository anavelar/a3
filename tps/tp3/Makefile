all: tp3

tp3: tp3.o funcoes.o
	gcc -std=c99 -Wall -Wextra -Werror funcoes.o tp3.o -o tp3

tp3.o: tp3.c funcoes.h funcoes.c
	gcc -c -std=c99 -Wall -Wextra -Werror tp3.c

funcoes.o: funcoes.c funcoes.h
	gcc -c -std=c99 -Wall -Wextra -Werror funcoes.c

clean:
	rm *.o
	rm tp3
