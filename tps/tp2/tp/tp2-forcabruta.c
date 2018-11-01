#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BITS_CAMPO 8
#define SIM 1
#define NAO 0

int main(int argc, char *argv[ ]) {

  //INICIALIZACAO
  FILE* pArqEntrada;
  FILE* pArqSaida;

  int i, j, k, l; //Contadores
  int numCasosTeste; // I, onde 1 <= I <=10
  int S; //S - tamanho da sequencia. 1<= S <= 10^3
  int V; // V, 0 <= V <= X (e X<= 10^3)
  int X; //X, 1<= X <= 10^3
  long int M; //M, ??
  int* sequencia = NULL; //Vetor com a sequencia --- No max 10^3 cada item?
  unsigned char* vetorBits = NULL; //unsigned char: 8bits, de 0 a 255.
                                   //cada bit vai representar o sinal de um
                                   //elemento da sequencia.
  double qtdadeChars; //double do int tamVetorBits arredondado para baixo
  int tamVetorBits; //de 1 a 125? (125 p 8 bits por campo)
  int bitsAmais; //de 0 a 7?
  unsigned char maximo; //ate onde percorrer no ultimo bit dentro do campo (ver aqui abaixo)
  int maximoPercorrer; //quando sabe que varreu o espaco de solucoes
  int indiceVetorBits; //Entre 0 e 124 (max 125 posicoes)
  //Usados para percorrer campo do vetor de bits
  unsigned char valorBit;
  int n;
  //resultado para cada conf do vetor e p conf global colocar aqui tb?
  long int valorConf; //valor de uma configuracao do vetor de bits
  long int valorConfMax; //maior valorConf ja encontrado ate agora
  long int temp; //para checar se passou o limite ao add
  //Para aborts
  int abortouConf; //uma booleana na verdade aqui

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
    fscanf(pArqEntrada, "%d %d ", &S, &V);
    fscanf(pArqEntrada, "%d %d\n", &X, &M);
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

    //Inicializacoes
    //Do vetor de bits todo zero 00000... a todo 1 11111...
    //Inicializa para a 1a configuracao do vetor
    for(j=0; j<tamVetorBits; j++)
    {
      vetorBits[j] = 0;
    }
    l = 0;

    indiceVetorBits = 0;
    valorConfMax = 0;

    //Para cada configuracao do vetor de bits possivel:
    //Cada passada no vetor de bitsx**m?
    //Cada: Percorrendo o vetor todo uma vezx**m?
    while(l != maximoPercorrer) //l desfazer se nao usar
    {
      //Inicializacoes necessarias
      valorConf = V;
      abortouConf = NAO;

      //Percorrendo cada campo do vetor de bits
      for(j=0; j<tamVetorBits; j++)
      {
        if(j == tamVetorBits-1) //Se esta no ultimo campo do vetor de bits,
                                //o que pode nao estar cheio
        {
          if(bitsAmais == 0) //Se o ultimo campo deve ser percorrido inteiro
          {

          }
          else //Se o ultimo campo deve ser percorrido parcialmente
          {

          }
        }
        else //Se nao esta no ultimo campo do vetor de bits, um dado campo
        {
          //Dentro de um campo unsigned char do vetor de bits
          //7 eh o bit mais a esquerda, 2^7. 0 mais a direita, 2^0.
          //Percorre os bits de um dos campos do vetor
          for(n=7; n>=0; n--) //Aqui, n de 7 a 0.
          {
            //Para cada bit do vetor
            //----------------------

            valorBit = (vetorBits[j] & (1 << n));

            if(valorBit != 0) //Se o bit n for 1 (-)
            {
              temp = valorConf - sequencia[(8*indiceVetorBits)+(7-n)];

              if(temp >= 0) //Se a operacao nao estorou limites
              {
                valorConf = valorConf - sequencia[(8*indiceVetorBits)+(7-n)];
              }
              else //Se a operacao estourou limites: aborta essa conf
                  // cuidado com o valor la em baixo.
              {
                abortouConf = SIM;
                break;
              }
            }
            else //Se o bit n for 0 (+)
            {
              temp = valorConf + sequencia[(8*indiceVetorBits)+(7-n)];

              if(temp <= X) //Se a operacao nao estorou limites
              {
                valorConf = valorConf + sequencia[(8*indiceVetorBits)+(7-n)];
              }
              else //Se a operacao estourou limites: aborta essa conf
                  // cuidado com o valor la em baixo.
              {
                abortouConf = SIM;
                break;
              }
            }
          }
        }

        if(abortouConf == SIM)
        {
          break;
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

      //Calcula novo l --- conferir se depois q mudei mudou aqui***********
      //ver se nao vai sair antes também!!! ao total
      l = 0;
      for(j=0; j<tamVetorBits; j++)
      {
        l = l + vetorBits[j];
      }

      //Atualiza indices para os do novo loop
      //Ve ser ja fez todos os cenarios daquele campo.
      //Se sim atualiza os indices e vai para o proximo campo
      //se nao deixa os indices certos, confirmar isso aqui
      //indiceVetorBits++;

      //OBRIGATORIO, mas precisa conferir também se não abortou
      //se tiver abortado descarta o valor conf do ramo:
      //checa o valorConf encontrado nessa conf do vetor
      //conferir depois o valorConf p caso nao abortou se eh isso mesmo
      if ( (abortouConf == NAO) && (valorConf > valorConfMax) )
      {
        valorConfMax = valorConf;
      }

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
