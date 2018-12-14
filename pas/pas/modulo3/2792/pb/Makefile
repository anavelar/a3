#Geracao do executavel pela linkagem entre os codigos objeto gerados
main: main.o pb.o
	gcc -O2 -lm pb.o main.o -o main

#Geracao do codigo objeto para o codigo do main
main.o: mainaux.c pb.h pb.c
	gcc -c -O2 -lm mainaux.c

#Geracao do codigo objeto para as funcoes da pesquisa binaria
pb.o: pb.c pb.h
	gcc -c -O2 -lm pb.c

clean:
	rm *.o
	rm main
