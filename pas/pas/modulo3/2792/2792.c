#include <stdlib.h>
#include <stdio.h>
#define INVALIDO -1

//Assinaturas
//*******************************************Colocar as assinaturas aqui


int main(){

  long int i; //Contador
  long int N;
  long int retirada = INVALIDO; //Elemento que vai ser "retirado"
  lont int* indices = NULL; //Vetor com os indices de cada elemento inicial
                            //Long int porque os indices podem ser ate 500 000

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
    Retira(indices, retirada);
  }
  //Ultimo do arquivo
  scanf("%li", &retirada);
  Retira(indices, retirada);

  return 0;
}

//Funcoes
void Retira(long int* indices, long int retirada)
{
  indices[retirada] = INVALIDO;
}

void Arruma(long int* indices, long int retirada)
