listaencadeada: listaencadeada.o main.o
	gcc listaencadeada.o main.o -o listaencadeada
main.o: mainTeste.c listaEncadeada.h
	gcc -g -c mainTeste.c
listaencadeada.o: listaEncadeada.h listaEncadeada.c
	gcc -g -c listaEncadeada.c
clean:
	rm *.o *.gch
	rm listaencadeada
