#include <stdlib.h>
#include <stdio.h>

//Assinaturas das Funcoes
void Particao(long int Esq, long int Dir, long int* i, long int* j, double* A);
void Ordena(long int Esq, long int Dir, double* A);
double corteMediano(double hBase, double hTeto, double* tira, long int A, long int N);

//Programas
int main(int argc, char *argv[])
{
  long int i; //Contador
  long int A, N;
  double* tira = NULL;
  double areaTotal, resultado;

  //Cada caso de teste
  scanf("%li %li\n", &N, &A);
  while((A!=0) && (N!=0))
  {
    //Inicializacoes
    tira = (double*) malloc(N*sizeof(double));

    areaTotal = 0.0;
    for(i=0; i<(N-1); i++)
    {
      scanf("%lf ",&tira[i]);
      areaTotal = areaTotal + tira[i];
    }
    scanf("%lf\n",&tira[i]);
    areaTotal = areaTotal + tira[i];

    //Confere o corte em questao
    if(((double) A) > areaTotal)
      printf("-.-\n");
    else
    {
      if(((double) A) == areaTotal)
        printf(":D\n");
      else
      {
        Ordena(0, (N-1), tira);
        resultado = corteMediano(((double) 0.0000), tira[N-1], tira, A, N);
        printf("%.4lf\n", resultado);
      }
    }

    //Novo caso de Teste
    free(tira);
    scanf("%li %li\n", &N, &A);
  }

  return 0;
}

//Funcoes usadas no programa
void Particao(long int Esq, long int Dir, long int* i, long int* j, double* A)
{
  double x, w;

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

void Ordena(long int Esq, long int Dir, double* A)
{
  long int i, j;

  Particao(Esq, Dir, &i, &j, A);

  if(Esq<j)
    Ordena(Esq, j, A);

  if(i<Dir)
    Ordena(i, Dir, A);
}

double corteMediano(double hBase, double hTeto, double* tira, long int A, long int N)
{
  double metade, area, delta;
  long int i;

  metade = ((hBase+hTeto) / ((double) 2.0000));

  //Area do corte
  area = (double) 0.0000;
  //O Vetor esta ordenado em ordem crescente
  for(i=(N-1); i>=0; i--)
  {
    if(metade >= tira[i])
     break;
    else
     area = area + (tira[i] - metade);
  }

  //Condicao de parada
  if(A > area)
    delta = A - area;
  else //(A < area ou sao iguais)
    delta = area - A;

  if( delta < ((double) 0.0001) )
    return metade;

  //Nao encontrou
  if(hBase <= hTeto)
  {
    if(area < A)
      return (corteMediano(hBase, metade, tira, A, N));
    else //(area > A)
      return (corteMediano(metade, hTeto, tira, A, N));
  }
}
