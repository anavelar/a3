#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BITS_CAMPO 8

int main(int argc, char *argv[ ]) {

  //INICIALIZACAO
  FILE* pArqEntrada;
  FILE* pArqSaida;

  int i, j, k, l; //Contadores
  int numCasosTeste; // I, onde 1 <= I <=10
  int S; //S - tamanho da sequencia. 1<= S <= 10^3
  int valorInicio; // V, 0 <= V <= X (e X<= 10^3)
  int limiteRodada; //X, 1<= X <= 10^3
  int minimoRodada; //M, ??
  int* sequencia = NULL; //Vetor com a sequencia --- No max 10^3 cada item?
  unsigned char* vetorBits = NULL; //unsigned char: 8bits, de 0 a 255.
                                   //cada bit vai representar o sinal de um
                                   //elemento da sequencia.
  double qtdadeChars; //double do int tamVetorBits arredondado para baixo
  int tamVetorBits; //de 1 a 125? (125 p 8 bits por campo)
  int bitsAmais; //de 0 a 7?
  unsigned char maximo; //ate onde percorrer no ultimo bit dentro do campo (ver aqui abaixo)
  int maximoPercorrer; //quando sabe que varreu o espaco de solucoes
  int indiceVetorReal; //Entre 0 e 124 (max 125 posicoes)
  int indiceVetorNumero; //Entre 0 e 124 (max 125 posicoes)


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
    fscanf(pArqEntrada, "%d %d ", &S, &valorInicio);
    fscanf(pArqEntrada, "%d %d\n", &limiteRodada, &minimoRodada);
    sequencia = (int*) malloc(S*(sizeof(int)));
    for(j=0; j<(S-1); j++)
    {
      fscanf(pArqEntrada, "%d ", &sequencia[j]);
    }
    fscanf(pArqEntrada, "%d\n", &sequencia[j]);

    //Geracao do vetor de sinais
    qtdadeChars = (double) S / BITS_CAMPO;
    tamVetorBits = (int) ceil(qtdadeChars);
    bitsAmais = S % BITS_CAMPO;
    vetorBits = (unsigned char*) malloc(tamVetorBits*(sizeof(unsigned char)));

    //Procura do maior valor para a sequencia por forca bruta,
    //varendo todo o espaço de solucoes.
    //---------------------------------------------------------

    //Calcula quando todo o espaco de solucoes vai ter sido varrido
    //maximoPercorrer: quando vai ter varrido o espaco de solucoes
    //Tamanho maximo de maximoPercorrer = 255*125 = 31875 (cabe num int, que eh 32mil e alguma coisa).
    maximoPercorrer = 0;
    //Para os campos cheios
    for(j=0; j<(tamVetorBits-1); j++)
    {
      maximoPercorrer = maximoPercorrer + 255;
    }
    //para o ultimo campo, que pode ou nao ser completo (j = tamVetorBits-1) aqui
    if(bitsAmais == 0) //Caso o ultimo campo seja cheio
    {
      maximoPercorrer = maximoPercorrer + 255;
    }
    else //Caso o ultimo campo nao seja cheio
    {
      //Calcula o maximo dele
      maximo = 0;
      for(k=0; k<=bitsAmais-1; k++)
      {
        maximo = (maximo | (1 << k));
      }

      maximoPercorrer = maximoPercorrer + maximo;
    }


    //Varre a espaco de solucoes

    //Do vetor de bits todo zero 00000... a todo 1 11111...
    for(j=0; j<tamVetorBits; j++)
    {
      vetorBits[j] = 0;
    }
    l = 0;
    indiceVetorReal = tamVetorBits - 1;
    indiceVetorNumero = 0;

    //Para cada configuracao do vetor de bits possivel:
    //Cada passada no vetor de bitsx**m?
    //Cada: Percorrendo o vetor todo uma vezx**m?
    while(l != maximoPercorrer) //l desfazer se nao usar
    {
      //Percorrendo cada campo do vetor de bits
      for(j=(tamVetorBits-1); j>=0; j--)
      {
        if(j == 0) //Se esta no ultimo campo do vetor de bits
        {
          if(bitsAmais == 0) //Se o ultimo campo deve ser percorrido inteiro
          {

          }
          else //Se o ultimo campo deve ser percorrido parcialmente
          {

            //OBS.: 1o e 2o casos do 1o toy de testes
            //1 bit a mais = so o campo zero. 2: so o 0 e o 1. Etc.
            for(k=0; k<bitsAmais; k++)
            {
                //
            }

          }
        }
        else //Se nao esta no ultimo campo do vetor de bits? VER
        {

        }
      }

      //---------------------------------------------------------------------
      //Agora muda o vetor todo para novos 010101100.. aqui abaixo:

      //Reinicia o loop
      //Soma 1 no vetor e atualiza com isso TODOS OS CAMPOS
      if( tamVetorBits == 1) //Se so tem uma celula
      {

      }
      else //Se a ultima celula nao eh a unica, logo esta cheia.
      {

      }

      //Calcula novo l
      l = 0;
      for(j=0; j<tamVetorBits; j++)
      {
        l = l + vetorBits[j];
      }

      //Atualiza indices para os do novo loop
      //Ve ser ja fez todos os cenarios daquele campo.
      //Se sim atualiza os indices e vai para o proximo campo
      //se nao deixa os indices certos, confirmar isso aqui
      //indiceVetorReal--;
      //indiceVetorNumero++;
    }

    //Ao fim da instancia: impressao no arquivo de saida do resultado.
    //Depois:: desalocar coisas para a proxima instancia!
    free(sequencia);
    free(vetorBits);
  }

  //FIM DO PROGRAMA
  fclose(pArqEntrada);
  fclose(pArqSaida);

  return 0;
}
