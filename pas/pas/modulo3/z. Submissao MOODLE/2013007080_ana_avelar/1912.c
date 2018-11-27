#include <stdlib.h>
#include <stdio.h>

//Assinaturas
void Particao(long int Esq, long int Dir, long int* i, long int* j, double* A);
void Ordena(long int Esq, long int Dir, double* A);
double corteMediano(double hBase, double hTeto, double* tira, long int A, long int N);

int main(int argc, char* argv[]){

  long int i; //Contador
  long int A, N;
  double* tira = NULL;
  double areaTotal, resultado;

  //Execucao
  scanf("%li %li\n", &N, &A);
  while((A!=0) && (N!=0))
  {
    //Inicializacoes
    areaTotal = (double) 0.0;
    tira = (double*) malloc(N*sizeof(double));

    //Le e insere as tiras
    for(i=0; i<(N-1); i++)
    {
      scanf("%lf ",&tira[i]);
      areaTotal = areaTotal + tira[i];
    }
    scanf("%lf\n",&tira[i]);
    areaTotal = areaTotal + tira[i];

    if( ((double) A) > areaTotal) //Caso a area pedida seja maior do que a area total
      printf("-.-\n");
    else
    {
      if( ((double) A) == areaTotal) //Se a area pedida for igual a area total
        printf(":D\n");
      else // Se A for < areaTotal: vai ter corte
      {
        Ordena(0, (N-1), tira);

        resultado = corteMediano( ((double) 0.0000), tira[N-1], tira, A, N);
        printf("%.4f\n", resultado);

      }
    }

    //Proximo caso de teste
    free(tira);
    scanf("%li %li\n", &N, &A);;
  }

  return 0;
}

//Funcoes

//Ordenacao
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

//Funcao recursiva de corte
//Retorna na ultima entrada a altura que gera o valor certo
double corteMediano(double hBase, double hTeto, double* tira, long int A, long int N)
{
  long int i; //Contador
  double areaSuperiorCorte, Ad, H, delta;

  //Calcula H
  Ad = (double) A; //Ad
  H = ((hBase + hTeto) / ((double) 2.0000));

  //Calcula a area *superior* resultante desse H
  areaSuperiorCorte = (double) 0.0000;
  for(i=0; i<N; i++)
  {
    if(tira[i] >  H)
      areaSuperiorCorte = areaSuperiorCorte + (tira[i] - H);
  }

  //Checa se esta na hora de parar
  if(Ad > areaSuperiorCorte)
    delta = Ad - areaSuperiorCorte;
  else
    delta = areaSuperiorCorte - Ad;

  if(delta < ((double) 0.0001) )
    return H;

  //Caso nao vai parar ainda
  if(areaSuperiorCorte > Ad) //Caso a area acima eh maior do que eu preciso
    //Aumenta o valor de H para diminuir a area acima do corte
    return (corteMediano(H, hTeto, tira, A, N));
  else //Caso a area acima eh menor do que eu preciso
    //Desce o valor de H para a area Superior ao corte aumentar
    return( corteMediano(hBase, H, tira, A, N) );
}
