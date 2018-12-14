#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 2147483647
#define SIM 1
#define NAO 0
#define INICIO 0

int main(){

  // Variaveis
  int numCasosTeste;
  int numPessoas; //Inteiro positivo e <500: Entre 1 e 500
  double *x, *y, *peso;
  int* visita;
  int i, j, k; //Contadores
  double teia;
  int indiceAux;
  double m;
  double d, dx, dy;

  // Programa
  scanf("%d\n", &numCasosTeste);
  //Para cada caso de teste
  for(i=0; i<numCasosTeste; i++)
  {
    //Inicializacoes
    scanf("%d\n", &numPessoas);
    x = (double*) malloc(numPessoas*sizeof(double));
    y = (double*) malloc(numPessoas*sizeof(double));
    peso = (double*) malloc(numPessoas*sizeof(double));
    visita = (int*) malloc(numPessoas*sizeof(int));
    for(j=0; j<numPessoas; j++)
    {
      scanf("%lf %lf\n", &(x[j]), &(y[j]));
      visita = NAO;
      peso[j] = MAX;
    }

    //Para comecar a execucao
    peso[0] = INICIO;
    teia = INICIO;
    for(j=0; j<numPessoas; j++)
    {
      indiceAux = INICIO;
      m = MAX;
      for(k=0; k<numPessoas; k++)
      {
        if((peso[k] < m) && (visita[k] == NAO))
        {
          m = peso[k];
          indiceAux = k;
        }
      }

      teia = teia + m;
      visita[indiceAux] = SIM;
      for(k=0; k<numPessoas; k++)
      {
        if(visita[k] == NAO)
        {
          dx = pow((x[indiceAux] - x[k]), 2.0);
          dy = pow((y[indiceAux] - y[k]), 2.0);
          d = sqrt(dx + dy);
          if(d < peso[k])
          {
            peso[k] = d;
          }
        }
      }
    }

    //Imprime resultado
    teia /= 100.0;
    printf("%.2lf\n", teia);

    //Arruma para o proximo caso
    free(x);
    free(y);
    free(peso);
    free(visita);
  }
  return 0;
}
