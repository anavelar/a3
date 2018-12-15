#include <stdio.h>
#include <stdlib.h>

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

int main()
{
  int A[5];
  A[0]=3;
  A[1]=4;
  A[2]=2;
  A[3]=0;
  A[4]=1;

  Ordena(((long int) 0), ((long int) 5), A);

  int i;
  printf("A = ");
  for(i=0; i<5; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
