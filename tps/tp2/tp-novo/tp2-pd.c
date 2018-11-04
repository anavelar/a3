#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[ ]) {

    //Declaracoes
    //-------------

    FILE* pArqEntrada;
    FILE* pArqSaida;
    int numCasosTeste;  // I, onde 1 <= I <=10
    int S, V, X;        //S - tamanho da sequencia. 1<= S <= 10^3
                        //V, 0 <= V <= X (e X<= 10^3)
                        //X, 1<= X <= 10^3
    long int M;         //M, ate 10^6 pela espec logo long int
    int* sequencia = NULL; //Vetor com a sequencia --- No max 10^3 cada item msm?

    //Contadores
    int i, j;

    //PD
    long int* pd;
    long int* pdAnterior;
    int s;   // minusculo - 1 <= s <= 10^3 - aux Szao
    long int temp;


    //Entrada dos dados
    //-----------------

    //Abertura dos arquivos
    if(argc != 3)
    {
      printf("\nERRO. Faltam parametros para a execucao do programa,");
      printf("falta especificar o arquivo de entrada, de saida ou o executavel.\n");
      printf("\nNao foi possivel executar o programa.\n\n");
      return 0;
    }

    pArqEntrada = fopen(argv[1],"r");
    pArqSaida = fopen(argv[2],"w");

    if(pArqEntrada == NULL)
    {
      printf("\nNao foi possivel encontrar o arquivo de entrada.\n");
      printf("\nNao foi possivel executar o programa.\n\n");
      fclose(pArqSaida);
      return 0;
    }

    //Leituras
    fscanf(pArqEntrada, "%d\n", &numCasosTeste);

    //Para cada instancia no arquivo
    for(i=0; i<numCasosTeste; i++)
    {
      //Leitura dos dados da instancia
      fscanf(pArqEntrada, "%d %d ", &S, &V);
      fscanf(pArqEntrada, "%d %li\n", &X, &M);
      sequencia = (int*) malloc(S*(sizeof(int)));
      for(j=0; j<(S-1); j++)
      {
        fscanf(pArqEntrada, "%d ", &sequencia[j]);
      }
      fscanf(pArqEntrada, "%d\n", &sequencia[j]);

      //Programa

      //long int* pd;
      //long int* pdAnterior;
      /*
      tempPD = (int) pow(((double) 2), ((double) (k+1)));
      pd[k] = (long int*) malloc(tempPD*(sizeof(long int)));
      */
      //Inicializacao
      s = 1;
      temp = (int) pow(((double) 2), ((double) s));
      pd = (long int*) malloc(temp*(sizeof(long int)));

      if( (V+sequencia[s-1]) <= X )
      {
        pd[0] = (V+sequencia[s-1]);
      }
      else //estourou
      {
        pd[0] = -1;
      }

      //if mais de 2 o S
      // mudar indices for(j=0; j<S; j++)
      {

      }



    }

    //FIM DO PROGRAMA
    fclose(pArqEntrada);
    fclose(pArqSaida);

  return 0;
}
