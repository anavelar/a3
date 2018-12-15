#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INICIO 0

//Assinaturas das funcoes
void Caminha(int* vetor, int* eind, long int valor, int x);
void Particao(long int Esq, long int Dir, long int* i, long int* j, int* A);
void Ordena(long int Esq, long int Dir, int* A);

int main(){

  int numCasosTeste; //Ate 100
  int numPedras; // 0 <= numPedras <= 100
  long int dist; // 1 <= dist <= 1000000000
  char tamanho;
  long int M; // 0 < M < dist <= 1000000000
  int i, j, k, l; //Contadores
  int* vetor;
  int ind;
  int aux;
  int** matrizPD;
  int v = 500;

  scanf("%d\n", &numCasosTeste);
  for(i=0; i<numCasosTeste; i++)
  {
    scanf("%d %li\n", &numPedras, &dist);

    vetor = (int*) malloc(v*sizeof(int));
    matrizPD = (int**) malloc(v*sizeof(int*));
    for(j=0; j<v; j++)
      matrizPD[j] =  (int*) malloc(v*sizeof(int));
    ind = 0;

    for(j=0; j<numPedras; j++)
    {
      scanf("%c-%li\n", &tamanho, &M);

      if(tamanho == 'S')
        Caminha(vetor, &ind, M, 1);
      else
        Caminha(vetor, &ind, M, 2);
    }

    Caminha(vetor, &ind, INICIO, 1);
    Caminha(vetor, &ind, dist, 2);
    Ordena(((long int) 0), ((long int) ind), vetor);

    //Inicializa
    for(j=0; j<ind; j++)
      for(k=0; k<ind; k++)
        matrizPD[j][k] = INT_MAX;

    // Calcula
    matrizPD[0][0] = INICIO;
    for(j=0; j<ind; j++)
    {
      for(k=0; k<ind; k++)
      {
        l = (j < k)? k : j;
        l++;

        aux = (matrizPD[j][k] < (vetor[l]-vetor[k]))? (vetor[l]-vetor[k]) : matrizPD[j][k];
        matrizPD[j][l] = (matrizPD[j][l] < aux) ? matrizPD[j][l] : aux;

        aux = (matrizPD[j][k] < (vetor[l]-vetor[j])) ? (vetor[l]-vetor[j]) : matrizPD[j][k];
        matrizPD[l][k] = (matrizPD[l][k] < aux) ? matrizPD[l][k] : aux;
      }
    }

    //Imprime o Resultado encontrado
    printf("Case %d: %d\n", (i+1), matrizPD[ind-1][ind-2]);

    //Fim do caso de teste
    free(vetor);
    for(j=0; j<v; j++)
      free(matrizPD[j]);
    free(matrizPD);

  }
  return 0;
}

//Funcoes usadas
void Caminha(int* vetor, int* eind, long int valor, int x)
{
  int i;

  for(i=0; i<x; i++)
  {
    (*eind)++;
    vetor[(*eind)] = valor;
  }
}

void Particao(long int Esq, long int Dir, long int* i, long int* j, int* A)
{
  long int x, w;

  *i=Esq;
  *j=Dir;

  x = A[ (*i + *j) / 2 ];

  do
  {
    while(x > A[*i])
     (*i)++;

    while(x < A[*j])
     (*j)--;

    if( *i <= *j )
    {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
    }

  } while( *i <= *j );
}

void Ordena(long int Esq, long int Dir, int* A)
{
  long int i, j;

  Particao(Esq, Dir, &i, &j, A);

  if(Esq<j)
    Ordena(Esq, j, A);

  if(i<Dir)
    Ordena(i, Dir, A);
}
