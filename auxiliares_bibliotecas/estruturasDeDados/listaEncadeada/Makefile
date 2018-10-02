listaencadeada: listaencadeada.o main.o
	gcc listaencadeada.o main.o -o listaencadeada
main.o: main.c listaencadeada.h
	gcc -g -c main.c
listaencadeada.o: listaencadeada.h listaencadeada.c
			gcc -g -c listaencadeada.c
clean:
	rm *.o *.gch
	rm listaencadeada
