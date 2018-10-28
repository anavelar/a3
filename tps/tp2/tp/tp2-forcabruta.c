#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BITS_CAMPO 8

int main(int argc, char *argv[ ]) {

  //INICIALIZACAO
  FILE* pArqEntrada;
  FILE* pArqSaida;

  int i, j; //Contadores
  int numCasosTeste; // I, onde 1 <= I <=10
  int tamanhoSequencia; //S - tamanho da sequencia. 1<= S <= 10^3
  int valorInicio; // V, 0 <= V <= X (e X<= 10^3)
  int limiteRodada; //X, 1<= X <= 10^3
  int minimoRodada; //M, ??
  int* sequencia = NULL; //Vetor com a sequencia --- No max 10^3 cada item?
  unsigned char* vetorBits = NULL; //unsigned char: 8bits, de 0 a 255.
                                   //cada bit vai representar o sinal de um
                                   //elemento da sequencia.
  double qtdadeChars;
  int tamVetorBits;

  //Entrada dos dados
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

  //PROGRAMA
  fscanf(pArqEntrada, "%d\n", &numCasosTeste);

  //Para cada instancia do arquivo lido
  for(i=0; i<numCasosTeste; i++)
  {
    //Leitura do dados daquela instancia
    fscanf(pArqEntrada, "%d %d ", &tamanhoSequencia, &valorInicio);
    fscanf(pArqEntrada, "%d %d\n", &limiteRodada, &minimoRodada);
    sequencia = (int*) malloc(tamanhoSequencia*(sizeof(int)));
    for(j=0; j<(tamanhoSequencia-1); j++)
    {
      fscanf(pArqEntrada, "%d ", &sequencia[j]);
    }
    fscanf(pArqEntrada, "%d\n", &sequencia[j]);

    qtdadeChars = (double) tamanhoSequencia / BITS_CAMPO;
    tamVetorBits = (int) ceil(qtdadeChars);
    vetorBits = (unsigned char*) malloc(tamVetorBits*(sizeof(unsigned char)));







    //Ao fim da instancia: impressao no arquivo de saida do resultado.
    //Depois:: desalocar coisas para a proxima instancia!
    free(sequencia);
    free(vetorBits);
  }





  /*
  int leitura;
  fscanf(pArqEntrada, "%d\n", &leitura);
  fprintf(pArqSaida,"Impressao do forcao bruta: lido %d.\n", leitura);
  */

  //FIM DO PROGRAMA
  fclose(pArqEntrada);
  fclose(pArqSaida);

  //t

  return 0;
}
