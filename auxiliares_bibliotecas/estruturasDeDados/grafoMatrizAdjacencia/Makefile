matrizAdj: matrizAdj.o main.o
	gcc matrizAdj.o main.o -o matrizAdj
main.o: main.c matrizAdj.h
	gcc -g -c main.c
matrizAdj.o: matrizAdj.h matrizAdj.c
	    gcc -g -c matrizAdj.c
clean:
	rm *.o *.gch
	rm matrizAdj
