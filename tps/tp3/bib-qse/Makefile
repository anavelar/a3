#Geracao do executavel pela linkagem entre os codigos objeto gerados
qse: main-qse.o qse.o area.o
	gcc -std=c99 -Wall -Wextra -Werror area.o qse.o main-qse.o -o qse

#Geracao do codigo objeto para o codigo do tp3, o main dele
main-qse.o: main-qse.c qse.h area.h qse.c area.c
	gcc -c -std=c99 -Wall -Wextra -Werror main-qse.c

#Geracao do codigo objeto para o QuickSort Externo
qse.o: qse.c qse.h area.h area.c
	gcc -c -std=c99 -Wall -Wextra -Werror qse.c

#Geracao do codigo objeto para a TAD Area
area.o: area.c area.h
	gcc -c -std=c99 -Wall -Wextra -Werror area.c

clean:
	rm *.o
	rm qse
