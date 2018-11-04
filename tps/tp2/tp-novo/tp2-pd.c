#include <stdlib.h>
#include <stdio.h>
#include "pd.h"

int main(int argc, char *argv[ ]) {

    //Declaracoes
    //-------------

    FILE* pArqEntrada;
    FILE* pArqSaida;
    int ok;
    int numCasosTeste;  // I, onde 1 <= I <=10
    int S, V, X;        //S - tamanho da sequencia. 1<= S <= 10^3
                        //V, 0 <= V <= X (e X<= 10^3)
                        //X, 1<= X <= 10^3
    long int M;         //M, ate 10^6 pela espec logo long int
    int* sequencia = NULL; //Vetor com a sequencia --- No max 10^3 cada item msm?

    //Contadores
    int i;

    //PD
    long int* pd;
    long int* pdAnterior;
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

      //Programa
      //InicializaPD(pd, &s, sequencia, V, X);


    }

    //FIM DO PROGRAMA
    EncerraPrograma(&pArqEntrada, &pArqSaida);

  return 0;
}
