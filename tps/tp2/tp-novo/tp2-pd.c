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

    //Contadores
    int i;

    /* "estatico" / com grande alocacao *********************************************** REMOVER SE DINAMICO FUNCIONAR
    long int** pd;      //long int pq M eh long int.
    long int tempPD;
    int j; //contador, subir pra junto dos contadores
    //PD
    pd = (long int**) malloc(S*(sizeof(long int*)));
    for(j=0; j<S; j++)
    {
      tempPD = (int) pow(((double) 2), ((double) (j+1)));
      pd[j] = (long int*) malloc(tempPD*(sizeof(long int)));
    }
    */

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




    }

    //FIM DO PROGRAMA
    fclose(pArqEntrada);
    fclose(pArqSaida);

  return 0;
}
