#Geracao do executavel pela linkagem entre os codigos objeto gerados
2792: mainaux.o pb.o
	gcc -O2 -lm pb.o mainaux.o -o 2792

#Geracao do codigo objeto para o codigo do main
mainaux.o: mainaux.c pb.h pb.c
	gcc -c -O2 -lm mainaux.c

#Geracao do codigo objeto para as funcoes da pesquisa binaria
pb.o: pb.c pb.h
	gcc -c -O2 -lm pb.c

clean:
	rm *.o
	rm 2792
