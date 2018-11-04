#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BITS_CAMPO 8
#define SIM 1
#define NAO 0

//FUNCOES - PASSAR P TAD
//(ate agora eu soh somei um ao vetorbits[0])
void confereVizinho(unsigned char* vetorBits, int indice, int tamVetorBits){

  //Caso eu tenha feito a virada agora
  if((vetorBits[indice] == 0) && ((indice+1) < tamVetorBits))
  {
    //cuidado com o ultimo, pensar no caso dele
    vetorBits[indice+1]++;
    confereVizinho(vetorBits, (indice+1), tamVetorBits);
  }
}

//PROGRAMA
int main(int argc, char *argv[ ]) {

  //INICIALIZACAO
  FILE* pArqEntrada;
  FILE* pArqSaida;

  int i, j, k;
  int l; //nao usar como contador basico!!
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
  //Usados para percorrer campo do vetor de bits
  unsigned char valorBit;
  int n;
  //resultado para cada conf do vetor e p conf global colocar aqui tb?
  long int valorConf; //valor de uma configuracao do vetor de bits
  long int valorConfMax; //maior valorConf ja encontrado ate agora
  long int temp; //para checar se passou o limite ao add
  //Para aborts
  int abortouConf; //uma booleana na verdade aqui
  //PD
  long int** pd; //long int pq M eh long int, e valorConfMax e valorConf tb.
  long int tempPD;

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
    fscanf(pArqEntrada, "%d %li\n", &X, &M);
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

    //Procura do maior valor pra sequencia varrendo todo o espaço de solucoes.
    //------------------------------------------------------------------------

    //1.Calcula quando todo o espaco de solucoes vai ter sido varrido
    //maximoPercorrer: quando vai ter varrido o espaco de solucoes
    //Tamanho maximo de maximoPercorrer = 255*125 = 31875 (cabe num int, que eh 32mil e alguma coisa).
    maximoPercorrer = 255 * (tamVetorBits-1);
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

    //2.Inicializacoes
    //Do vetor de bits todo zero 00000... a todo 1 11111...
    //Inicializa para a 1a configuracao do vetor
    for(j=0; j<tamVetorBits; j++)
    {
      vetorBits[j] = 0;
    }
    l = 0;
    valorConfMax = -1;

    //3. PD
    pd = (long int**) malloc((S-1)*(sizeof(long int*)));
    for(j=0; j<(S-1); j++)
    {
      tempPD = (int) pow(((double) 2), ((double) (j+1)));
      pd[j] = (long int*) malloc(tempPD*(sizeof(long int)));
      for(k=0; k<tempPD; k++)
      {
        pd[j][k] = -1;
      }
    }

    //Para cada configuracao do vetor de bits possivel:
    //Cada passada no vetor de bitsx**m?
    //Cada: Percorrendo o vetor todo uma vezx**m?
    while(1) //sempre, condicao de interrupcao esta la em baixo
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
            //Confere se esse campo já foi calculado
            //--------------------------------------

              //calcula
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
                  temp = valorConf - sequencia[(8*j)+(7-n)];

                  if(temp >= 0) //Se a operacao nao estorou limites
                  {
                    valorConf = temp;
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
                  temp = valorConf + sequencia[(8*j)+(7-n)];

                  if(temp <= X) //Se a operacao nao estorou limites
                  {
                    valorConf = temp;
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
          else //Se o ultimo campo deve ser percorrido parcialmente
          {
            //Confere se esse campo já foi calculado
            //--------------------------------------

              //- Calcula
              //Dentro de um campo unsigned char do vetor de bits
              //7 eh o bit mais a esquerda, 2^7. 0 mais a direita, 2^0.
              //Percorre os bits de um dos campos do vetor
              for(n=0; n<bitsAmais; n++)
              {
                //Para cada bit do vetor
                //----------------------

                //Acessa o bit
                valorBit = (vetorBits[j] & (1 << n));

                if(valorBit != 0) //Se o bit n for 1 (-)
                {
                  temp = valorConf - sequencia[S-bitsAmais+n];

                  if(temp >= 0) //Se a operacao nao estorou limites
                  {
                    valorConf = temp;
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
                  temp = valorConf + sequencia[S-bitsAmais+n];

                  if(temp <= X) //Se a operacao nao estorou limites
                  {
                    valorConf = temp;
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
        }
        else //Se nao esta no ultimo campo do vetor de bits, um dado campo
        {
          //Confere se esse campo já foi calculado
          //--------------------------------------
          //- Calcula e coloca na variavel de valor do montante
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
              //PD ******************************************************************AQUI
              if(  )
              {

              }
              //nao esquecer de usar os anetriores para construir o atual

              //FB
              temp = valorConf - sequencia[(8*j)+(7-n)];

              if(temp >= 0) //Se a operacao nao estorou limites
              {
                valorConf = temp;
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
              temp = valorConf + sequencia[(8*j)+(7-n)];

              if(temp <= X) //Se a operacao nao estorou limites
              {
                valorConf = temp;
              }
              else //Se a operacao estourou limites: aborta essa conf
                  // cuidado com o valor la em baixo.
              {
                abortouConf = SIM;
                break;
              }
            }

            //proximo bit
          }

        }

        if(abortouConf == SIM)
        {
          break;
        }

      }

      //---------------------------------------------------------------------
      //Agora muda o vetor todo para novos 010101100.. aqui abaixo:
      //--------------------------------------------------------------------

      //Confere se este eh o loop final
      //1-Calcula
      l = 0;
      for(j=0; j<tamVetorBits; j++)
      {
        l = l + vetorBits[j];
      }
      //2- Usa o calculo e confere
      //Se for, checa valor conf antes de sair (e lembra q tem
      //mais instancias, nao dar return, fazer de outra forma
      if(l == maximoPercorrer)
      {
        //Acabou essa instância
        //---------------------

        //Fim de toda conf de uma instancia
        //OBRIGATORIO, mas precisa conferir também se não abortou
        //se tiver abortado descarta o valor conf do ramo:
        //checa o valorConf encontrado nessa conf do vetor
        //conferir depois o valorConf p caso nao abortou se eh isso mesmo
        if( (abortouConf == NAO) && (valorConf > valorConfMax) )
        {
          valorConfMax = valorConf;
        }

        //Imprime sobre ela
        if(valorConfMax == -1) //Se não completou nenhuma conf possivel
                               //sem estourar. Casos 3 e 4: fora do intervalo [0,X]
        {
          fprintf(pArqSaida, "N,-1\n");
        }
        else  //Se teve pelo menos uma conf no trajeto que nao estourou
        {
          if(valorConfMax >= M)
          {
            fprintf(pArqSaida, "S,%li\n", valorConfMax);
          }
          else
          {
            fprintf(pArqSaida, "N,%li\n", valorConfMax);
          }
        }

        //por ultimo sai do while infinito
        break;
      }
      else //Nao acabou essa instancia: ainda há mais configurações para testar
      {
        //Reinicia o loop
        //Soma 1 no vetor e atualiza com isso TODOS OS CAMPOS
        vetorBits[0]++;
        //Propaga o resultado em todo o numero
        confereVizinho(vetorBits, 0, tamVetorBits);

        //OBRIGATORIO, mas precisa conferir também se não abortou
        //se tiver abortado descarta o valor conf do ramo:
        //checa o valorConf encontrado nessa conf do vetor
        //conferir depois o valorConf p caso nao abortou se eh isso mesmo
        //teste
        //printf("Fim instancia %d: valorConf:%li e valorConfMax:%li.\n", (i+1), valorConf, valorConfMax);
        //fimteste
        if( (abortouConf == NAO) && (valorConf > valorConfMax) )
        {
          valorConfMax = valorConf;
        }
      }

      //Reinicia nova configuracao do vetor
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
