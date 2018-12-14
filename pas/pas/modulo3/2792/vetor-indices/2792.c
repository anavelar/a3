#include <stdlib.h>
#include <stdio.h>
#define INVALIDO -1

// Usar:
// cd /home/ana/execucao/c/a3/pas/pas/modulo3/2792
// gcc -O2 -lm 2792.c -o 2792
// ./2792 <toys/toy1.in >toys/meutoy1.out
// diff toys/meutoy1.out toys/outtoy1.out

//Assinaturas
void Imprime(long int* indices, long int retirada, long int numRetiradas, long int N);
void Retira(long int* indices, long int retirada);
void Arruma(long int* indices, long int retirada, long int N, long int numRetiradas);

int main(){

  long int i; //Contador
  long int N;
  long int retirada = INVALIDO; //Elemento que vai ser "retirado"
  long int* indices = NULL; //Vetor com os indices de cada elemento inicial
                            //Long int porque os indices podem ser ate 500 000
  long int numRetiradas = 0;

  //Leitura do arquivo de entrada
  scanf("%li\n", &N);

  //Geracao do vetor de indices
  //Vai ter sentinela pra facilitar o acesso
  indices = (long int*) malloc((N+1)*sizeof(long int));
  indices[0] = INVALIDO;
  for(i=1; i<(N+1); i++)
    indices[i] = i;

  //Leitura e efetivacao das retiradas
  //Os que tem espaco depois
  for(i=1; i<N; i++) // De 1 ate (N-1), um a menos
  {
    scanf("%li ", &retirada);
    numRetiradas++;
    Imprime(indices, retirada, numRetiradas, N);
    Retira(indices, retirada);
    Arruma(indices, retirada, N, numRetiradas);
  }
  //Ultimo do arquivo
  //Conferir aqui com em cima + pensar na arruma se ta certa aqui e nas outras
  scanf("%li", &retirada);
  numRetiradas++;
  Imprime(indices, retirada, numRetiradas, N);
  //Nao precisa, cagay
  //Retira(indices, retirada); //Nao precisa
  //Arruma(indices, retirada, N); //Nao precisa, foi o ultimo a sair, so invalido la agora

  //Finaliza o programa
  free(indices);

  return 0;
}

//Funcoes
void Imprime(long int* indices, long int retirada, long int numRetiradas, long int N)
{
  if(numRetiradas == N) //Se eh a ultima retirada
  {
    //Imprime o indice sem espaco depois
    printf("%li\n", indices[retirada]);
  }
  else //Se nao eh a ultima retirada
  {
    //Imprime o indice com espaco depois
    printf("%li ", indices[retirada]);
  }

}

void Retira(long int* indices, long int retirada)
{
  indices[retirada] = INVALIDO;
}

void Arruma(long int* indices, long int retirada, long int N, long int numRetiradas)
{
  long int i;
  //Otimizacao que pode nao ajudar em nada
  long int retiradasafazer = N - numRetiradas;
  long int ajustesFeitos = 0;


  // Arruma os que vem depois
  if((retirada+1) < (N+1)) //Se existe elementos depois desse no vetor
  {
    // Percorre depois dele no vetor ajustando cada um
    for(i=(retirada+1); i<(N+1); i++)
    {
      //Ajusta o elemento i
      if(indices[i] != INVALIDO)
      {
        indices[i]--;
        ajustesFeitos++;
      }

      // Otimizacao que pode nao ajudar em bosta nenhuma do TLE
      //Obs: Nao otimiza quando as retiradas a fazer estao antes do que foi retirado
      if(ajustesFeitos == retiradasafazer) //Se só vai ter invalidos dai p frente
        break;

    }
  }

}
