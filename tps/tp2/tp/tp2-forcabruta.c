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
  int bitsAmais;

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

    //Geracao do vetor de sinais
    qtdadeChars = (double) tamanhoSequencia / BITS_CAMPO;
    tamVetorBits = (int) ceil(qtdadeChars);
    bitsAmais = tamanhoSequencia % BITS_CAMPO;
    vetorBits = (unsigned char*) malloc(tamVetorBits*(sizeof(unsigned char)));
    for(j=0; j<tamVetorBits; j++)
    {
      vetorBits[j] = 0;
    }

    //Procura do maior valor para a sequencia por forca bruta,
    //varendo todo o espaço de solucoes.
    //Primeiro: percorrendo cada campo do vetor de bits
    for(j=(tamVetorBits-1); j>=0; j--)
    {
      if(j == 0) //Se esta no ultimo campo do vetor de bits
      {
        if(bitsAmais == 0) //Se o ultimo campo deve ser percorrido inteiro
        {

        }
        else //Se o ultimo campo deve ser percorrido parcialmente
        {

        }
      }
      else //Se nao esta no ultimo campo do vetor de bits? VER
      {

      }

    }


    /* ---- TESTE
    printf("Instancia %d:\n", i);
    printf("Qtdade de itens:%d\n", tamanhoSequencia);
    printf("bits em um campo:%d\n", BITS_CAMPO);
    printf("Campos necessarios:%d\n", tamVetorBits);
    printf("Elementos no ultimo campo:%d.\n\n", bitsAmais);
    */

    //Ao fim da instancia: impressao no arquivo de saida do resultado.
    //Depois:: desalocar coisas para a proxima instancia!
    free(sequencia);
    free(vetorBits);
  }

  //FIM DO PROGRAMA
  fclose(pArqEntrada);
  fclose(pArqSaida);

  //t

  return 0;
}
