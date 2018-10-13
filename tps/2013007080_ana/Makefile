tp1: main.o grafos.o listaencadeada.o
	gcc listaencadeada.o grafos.o main.o -o tp1

main.o: tp1.c grafos.h
	gcc -g -c tp1.c

grafos.o: grafos.h grafos.c
	gcc -g -c grafos.c

listaencadeada.o: listaEncadeada.h listaEncadeada.c
	gcc -g -c listaEncadeada.c

clean:
	rm *.o *.gch
