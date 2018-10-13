#Geracao do executavel pela linkagem entre os codigos objeto gerados
tp1: tp1.o grafos.o listaEncadeada.o
	gcc listaEncadeada.o grafos.o tp1.o -o tp1

#Geracao do codigo objeto para o codigo do tp1, o main dele
tp1.o: tp1.c grafos.h listaEncadeada.h grafos.c listaEncadeada.c
	gcc -g -c tp1.c

#Geracao do codigo objeto para a biblioteca Grafos
grafos.o: grafos.c grafos.h listaEncadeada.h listaEncadeada.c
	gcc -g -c grafos.c

#Geracao do codigo objeto para a biblioteca Lista Encadeada
listaEncadeada.o: listaEncadeada.c listaEncadeada.h
	gcc -g -c listaEncadeada.c

clean:
	rm *.o
	rm tp1
