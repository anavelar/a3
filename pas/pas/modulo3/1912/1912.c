#include <stdlib.h>
#include <stdio.h>

//temp para teste
#include <math.h>
//fimteste

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
  {
    Ordena(Esq, j, A);
  }

  if(i<Dir)
  {
    Ordena(i, Dir, A);
  }

}

double corteMediano(double hBase, double hTeto, double* tira, long int A, long int N, double areaTotal, double deltaAnterior);

int main(int argc, char* argv[]){

  long int i; //Contador
  long int A, N;
  double areaTotal, maiorTira;
  double* tira = NULL;
  double resultado, maiorTiraF;

  //Execucao
  scanf("%li %li\n", &N, &A);
  while((A!=0) && (N!=0)) //*************************
  {
    //Inicializacoes
    areaTotal = (double) 0.0;
    maiorTira = (double) 0.0;
    tira = (double*) malloc(N*sizeof(double));

    //Le e insere as tiras
    for(i=0; i<(N-1); i++)
    {
      scanf("%lf ",&tira[i]);
      if(tira[i] > maiorTira)
      {
        maiorTira = tira[i];
      }
      areaTotal = areaTotal + tira[i];
    }
    scanf("%lf\n",&tira[i]);
    if(tira[i] > maiorTira)
    {
      maiorTira = tira[i];
    }
    areaTotal = areaTotal + tira[i];

    if( ((double) A) > areaTotal) //Caso a area pedida seja maior do que a area total
    {
      printf("-.-\n"); //voltar p esse depois
      //printf("-.-inicial\n"); //teste
    }
    else
    {
      if( ((double) A) == areaTotal) //Se a area pedida for igual a area total
      {
        printf(":D\n");
      }
      else // Se A for < areaTotal: vai ter corte
      {
        //opcional: ordena as tiras decrescente? *************************
        //testar se melhora ou piora o time
        Ordena(0, (N-1), tira); //*************************************************************************9999999999

        //maiorTiraF = (float) maiorTira;
        //resultado = corteMediano( ((float) 0.0000), maiorTiraF, tira, A, N, areaTotal, (areaTotal*5) );
        resultado = corteMediano( ((double) 0.0000), maiorTira, tira, A, N, areaTotal, (areaTotal*5) );
        if(resultado == ((float) -1.0))
        {
          printf("-.-\n"); //voltar p esse depois
          //printf("-.-de retorno\n");
        }
        else
        {
          printf("%.4f\n", resultado); //**************************
        }
      }
    }

    //Proximo caso de teste
    free(tira);
    scanf("%li %li\n", &N, &A);;
  }

  return 0;
}

//Funcao recursiva de corte
//Retorna na ultima entrada a altura que gera o valor certo
double corteMediano(double hBase, double hTeto, double* tira, long int A, long int N, double areaTotal, double deltaAnterior)
{
  long int i; //Contador
  double areaSuperiorCorte, areaInferiorCorte, Ad;
  double H;
  double delta1, delta2, deltaf;

  //Calcula H
  Ad = (double) A; //Ad
  H = ((hBase + hTeto) / ((double) 2.0000));

  //Calcula a area *superior* resultante desse H
  areaSuperiorCorte = (double) 0.0000;
  for(i=0; i<N; i++)
  {
    if(tira[i] >  H)
    {
      areaSuperiorCorte = areaSuperiorCorte + (tira[i] - H);
    }
  }
  //Calcula a area *inferior* resultante desse corte
  areaInferiorCorte = areaTotal - areaSuperiorCorte;

  //Calcula deltaf para checar se vai dar resultado
  if(Ad > areaSuperiorCorte)
    delta1 = Ad - areaSuperiorCorte;
  else
    delta1 = areaSuperiorCorte - Ad;

  if( Ad > areaInferiorCorte )
    delta2 = Ad - areaInferiorCorte;
  else
    delta2 = areaInferiorCorte - Ad;

  if(delta1>delta2)
    deltaf = delta2;
  else
    deltaf = delta1;

  //teste
  //printf("delta1=%lf, delta2=%lf, entao deltaf=%lf.\n", delta1, delta2, deltaf);
  //fimteste

  //teste
  //printf("deltaf=%lf\ndeltaAnterior=%lf\n\n", deltaf, deltaAnterior);
  //fimteste

  //Se ao cortar encontrei exatamente a area que queria
  if((areaSuperiorCorte == Ad) || (areaInferiorCorte == Ad))
  {
    return H;
  }
  else //Caso cortei mas não encontrei a area que queria, eh maior ou menor do que ela
  {
    //Depois adicionar uma condicao de parada**************************************************8
    //exemplo:
    //if( (hTeto - hBase) < 0.00001 ) //Se esta na hora de parar de iterar - Se h ja eh o mesmo ******
    //teste
    /*
    double ab;
    if(deltaf == delta2) //eh perto da area inferior
    {
      ab = areaInferiorCorte;
    }
    else //se deltaf == delta1. //eh perto da area superior
    {
      ab = areaSuperiorCorte;
    }
    */
    //fimteste
    if( (hTeto - hBase) < ((double) 0.00001) ) //Se esta na hora de parar de iterar - Se h ja eh o mesmo ******
    //if( deltaf < ((double) 0.00001) ) //temporario
    {
      return H;
    }

    //Condicao de impossibilidade
    //if( deltaf >= deltaAnterior )
    //if( ((hTeto - hBase) < 0.00001) && (deltaf >= deltaAnterior) )
    //{
      //teste
      //printf("H=%f. ", H);
      //fimteste
      //return ((float) -1.0); //Retornar qdo der loop, impossivel
    //}
    else
    {
      if(areaSuperiorCorte > Ad) //Caso a area acima eh maior do que eu preciso
      {
        //Aumenta o valor de H para diminuir a area acima do corte
        return (corteMediano(H, hTeto, tira, A, N, areaTotal, deltaf));
      }
      else //Caso a area acima eh menor do que eu preciso
      {
        //Desce o valor de H para a area Superior ao corte aumentar
        return( corteMediano(hBase, H, tira, A, N, areaTotal, deltaf) );
      }
    }

  }
}
