all: tp2-forcabruta tp2-pd

tp2-forcabruta: tp2-forcabruta.c
	gcc -g tp2-forcabruta.c -o tp2-forcabruta -lm

tp2-pd: tp2-pd.o pd.o
	gcc pd.o tp2-pd.o -o tp2-pd -lm

tp2-pd.o: tp2-pd.c pd.h pd.c
	gcc -g -c tp2-pd.c

pd.o: pd.c pd.h
	gcc -g -c pd.c

clean:
	rm *.o
	rm tp2-pd
	rm tp2-forcabruta
