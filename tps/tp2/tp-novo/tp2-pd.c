#include <stdlib.h>
#include <stdio.h>
#include "pd.h"

int main(int argc, char *argv[ ]) {

    //Declaracoes
    //-------------

    FILE* pArqEntrada = NULL;
    FILE* pArqSaida = NULL;
    int ok;
    int numCasosTeste;  // I, onde 1 <= I <=10
    int S, V, X;        //S - tamanho da sequencia. 1<= S <= 10^3
                        //V, 0 <= V <= X (e X<= 10^3)
                        //X, 1<= X <= 10^3
    long int M;         //M, ate 10^6 pela espec logo long int
    int* sequencia = NULL; //Vetor com a sequencia --- No max 10^3 cada item msm?

    //Contadores
    int i, j;

    //PD
    long int* pd = NULL;
    long int* pdAnterior = NULL;
    int s;   // minusculo - 1 <= s <= 10^3 - aux Szao - elemento em que estou
    long int temp;


    //Programa
    //--------

    ok = InicializaPrograma(argc, argv, &pArqEntrada, &pArqSaida);
    if(ok == 0)
    {
      return 0;
    }

    //Leituras
    fscanf(pArqEntrada, "%d\n", &numCasosTeste);

    //Para cada instancia no arquivo
    for(i=0; i<numCasosTeste; i++)
    {
      LeDadosInstancia(&pArqEntrada, &S, &V, &X, &M, &sequencia);

      //teste
      printf("Instancia %d\n", i);
      //fimteste

      //Programa
      InicializaPD(&pd, &s, sequencia, V, X);

      //if S >= 2
      for(j=1; j<S; j++)
      {
        //para cada s, de s=2 ate s=S: (S-1) elementos
        //void PDdes(long int** epd, long int** epdAnterior, int* es, int X, int* sequencia);
        PDdes(&pd, &pdAnterior, &s, X, sequencia);
      }


    }

    //FIM DO PROGRAMA
    EncerraPrograma(&pArqEntrada, &pArqSaida);

  return 0;
}
