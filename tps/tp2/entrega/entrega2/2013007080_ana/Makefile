all: tp2-forcabruta tp2-pd extra-tp2-pd-vetorbits extra-tp2-pd-matriz

tp2-forcabruta: tp2-forcabruta.c
	gcc -g tp2-forcabruta.c -o tp2-forcabruta -lm

tp2-pd: tp2-pd.o pd.o
	gcc pd.o tp2-pd.o -o tp2-pd

tp2-pd.o: tp2-pd.c pd.h pd.c
	gcc -g -c tp2-pd.c

pd.o: pd.c pd.h
	gcc -g -c pd.c

# Implementacao anterior do tp2-pd por matrizes
# So funciona para os casos 1, 3 e 7
extra-tp2-pd-matriz: extra-tp2-pd-matriz.o pd-matriz.o
	gcc pd-matriz.o extra-tp2-pd-matriz.o -o extra-tp2-pd-matriz -lm

extra-tp2-pd-matriz.o: extra-tp2-pd-matriz.c pd-matriz.h pd-matriz.c
	gcc -g -c extra-tp2-pd-matriz.c

pd-matriz.o: pd-matriz.c pd-matriz.h
	gcc -g -c pd-matriz.c

# Implementacao anterior do tp2-pd por vetor de bits
# So funciona para os casos 1, 3 e 7
extra-tp2-pd-vetorbits: extra-tp2-pd-vetorbits.c
	gcc -g extra-tp2-pd-vetorbits.c -o extra-tp2-pd-vetorbits -lm

clean:
	rm *.o
	rm tp2-pd
	rm tp2-forcabruta
	rm extra-tp2-pd-matriz
	rm extra-tp2-pd-vetorbits
