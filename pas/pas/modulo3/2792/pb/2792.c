#include <stdlib.h>
#include <stdio.h>

// Usar:
// cd /home/ana/execucao/c/a3/pas/pas/modulo3/2792
// gcc -O2 -lm 2792.c -o 2792
// ./2792 <toys/toy1.in >toys/meutoy1.out
// diff toys/meutoy1.out toys/outtoy1.out

//Assinaturas************************************

int main(){

  long int i; //Contador
  long int N;
  long int retirada;

  //Leitura do arquivo de entrada
  scanf("%li\n", &N);

  //Leitura e efetivacao das retiradas
  //Os que tem espaco depois
  for(i=1; i<N; i++) // De 1 ate (N-1), um a menos
  {
    scanf("%li ", &retirada);
  }
  //Ultimo do arquivo
  scanf("%li", &retirada);

  //Finaliza o programa
  //Desalocacoes etc

  return 0;
}
