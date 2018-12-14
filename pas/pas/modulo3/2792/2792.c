#include <stdlib.h>
#include <stdio.h>
#define INVALIDO -1

//Assinaturas
void Imprime(long int* indices, long int retirada, long int numRetiradas, long int N);
void Retira(long int* indices, long int retirada);
void Arruma(long int* indices, long int retirada, long int N);

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
    Arruma(indices, retirada, N);
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
    printf("%li", indices[retirada]);
  }
  else //Se nao eh a ultima retirada
  {
    //Imprime o indice com espaco depois
    printf("%li\n", indices[retirada]);
  }

}

void Retira(long int* indices, long int retirada)
{
  indices[retirada] = INVALIDO;
}

void Arruma(long int* indices, long int retirada, long int N)
{
  long int i;

  // Arruma os que vem depois
  if((retirada+1) < (N+1)) //Se existe elementos depois desse no vetor
  {
    for(i=(retirada+1); i<(N+1); i++)
    {
      if(indices[i] != INVALIDO)
        indices[i]--;
    }
  }

}
