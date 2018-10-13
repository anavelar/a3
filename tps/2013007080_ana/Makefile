tp1: tp1.o grafos.o listaEncadeada.o
	gcc listaEncadeada.o grafos.o tp1.o -o tp1

tp1.o: tp1.c grafos.h listaEncadeada.h
	gcc -g -c tp1.c

grafos.o: grafos.h grafos.c listaEncadeada.h
	gcc -g -c grafos.c

listaEncadeada.o: listaEncadeada.h listaEncadeada.c
	gcc -g -c listaEncadeada.c

clean:
	rm *.o
	rm tp1
