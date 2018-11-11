#include <stdlib.h>
#include <stdio.h>
#include "pd.h"

//OBS: para execucao
//forca bruta:
// caso_teste=8 && time ./tp2-forcabruta $caso_teste.tst.i $caso_teste-fb && diff $caso_teste-fb casos_de_teste_tp2/$caso_teste.tst.o
//pd:
// caso_teste=9 && time ./tp2-pd $caso_teste.tst.i $caso_teste-pd && diff $caso_teste-pd casos_de_teste_tp2/$caso_teste.tst.o
//----------------------------
//Com valgrind
// caso_teste=7 && valgrind ./tp2-forcabruta $caso_teste.tst.i $caso_teste-fb
//pd:
// caso_teste=2 && valgrind ./tp2-pd $caso_teste.tst.i $caso_teste-pd
//----------------------------
//Se nao der, ver arquivo de possiveis otimizacoes aqui.

int main(int argc, char *argv[ ]) {

    //Declaracoes
    //-----------

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
    int i;

    //PD
    apontador arvore = NULL; //vai apontar para o primeiro, no zero com V
    long int valorMax;

    //debugando
    int ac = 0;

    //Programa
    //--------

    ok = InicializaPrograma(argc, argv, &pArqEntrada, &pArqSaida);

    if(ok == 0)
    {
      return 0;
    }
    else
    {
      //Leituras
      fscanf(pArqEntrada, "%d\n", &numCasosTeste);

      //Para cada instancia no arquivo
      for(i=0; i<numCasosTeste; i++)
      {
        LeDadosInstancia(&pArqEntrada, &S, &V, &X, &M, &sequencia);

        InicializaArvore(&arvore, V, &valorMax);

        VisitaNo(arvore, sequencia, X, S, &valorMax, &ac);

        ImprimeResultado(valorMax, &pArqSaida, M);

        //teste
        //printf("Quantidade de nos visitados:%d.\n", ac);

        ReiniciaParaProxCaso(&sequencia, &arvore, &ac);
      }

      //FIM DO PROGRAMA
      EncerraPrograma(&pArqEntrada, &pArqSaida);

      return 0;
    }
}
