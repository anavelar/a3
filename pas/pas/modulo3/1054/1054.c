#include <stdio.h>
#include <stdlib.h>

#define INICIO 0
#define ENORME 2147483647

//Assinaturas das funcoes
void Particao(long int Esq, long int Dir, long int* i, long int* j, int* A);
void Ordena(long int Esq, long int Dir, int* A);

//aqui
#define VAL 305
//fimaqui

int main(){

  int numCasosTeste; //Ate 100
  int numPedras; // 0 <= numPedras <= 100
  long int dist; // 1 <= dist <= 1000000000
  char tamanho;
  long int M; // 0 < M < dist <= 1000000000
  int i, j, k, l; //Contadores

  int* A;
  int m;
  int aux;

  scanf("%d\n", &numCasosTeste);
  for(i=0; i<numCasosTeste; i++)
  {
    scanf("%d %li\n", &numPedras, &dist);
    A = (int*) malloc(VAL*sizeof(int));
    m = 0;
    for(j=0; j<numPedras; j++)
    {
      scanf("%c-%li\n", &tamanho, &M);
      A[m++] = M;
      if(tamanho == 'B')
        A[m++] = M;
    }
    A[m++] = INICIO;
    A[m++] = dist, A[m++] = dist;
    Ordena(((long int) 0.0), ((long int) m), A);
    int matrizPD[305][305];

    //Inicializa
    for(j=0; j<m; j++)
      for(k=0; k<m; k++)
        matrizPD[j][k] = ENORME;


    matrizPD[0][0] = INICIO;
    for(j=0; j<m; j++)
    {
      for(k=0; k<m; k++)
      {
        l = (j < k)? k : j;
        l++;

        aux = (matrizPD[j][k] < (A[l]-A[k]))? (A[l]-A[k]) : matrizPD[j][k];
        matrizPD[j][l] = (matrizPD[j][l] < aux) ? matrizPD[j][l] : aux;

        aux = (matrizPD[j][k] < (A[l]-A[j])) ? (A[l]-A[j]) : matrizPD[j][k];
        matrizPD[l][k] = (matrizPD[l][k] < aux) ? matrizPD[l][k] : aux;
      }
    }
    printf("Case %d: %d\n", (i+1), matrizPD[m-1][m-2]);

    //Fim do caso de teste
    free(A);
  }
  return 0;
}

//Funcoes usadas
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
