#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BITS_CAMPO 8
#define SIM 1
#define NAO 0

//ESTRUTURAS DE DADOS - PASSAR P TAD
typedef struct tipocampo* apontador;

typedef struct tipocampo{
  int indiceVB; //indice desse campo do vetor de bits
  unsigned char conf; //configuracao, de 0 a 255, desse campo. (valida
                      //considerando os anteriores claro.
  long int valor;      //valor calculado que vai ser salvo por prog dinamica;
  apontador* confProxCampo; //vetor para o proximo campo onde cada item
                                //eh uma configuracao possivel
} tipoCampo;

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
  //Usados para percorrer campo do vetor de bits
  unsigned char valorBit;
  int n;
  //resultado para cada conf do vetor e p conf global colocar aqui tb?
  long int valorConf; //valor de uma configuracao do vetor de bits
  long int valorConfMax; //maior valorConf ja encontrado ate agora
  long int temp; //para checar se passou o limite ao add
  //Para aborts
  int abortouConf; //uma booleana na verdade aqui
  tipoCampo* vb0;
  int numDiferentesConfig; //de 2^1, 2, ate 2^7, ate 128.
  //PD
  apontador aux;

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

    //Parte de programacao dinamica: cria vetor dos vetores para armazenar espacos
    //Cria vb0
    if(bitsAmais != 0) //se ha bits a mais, calcula essa variavel.
    {
      numDiferentesConfig = (int) (pow(((double) 2), ((double) bitsAmais)));
    }
    if( (tamVetorBits == 1) && (bitsAmais != 0) ) //Se o vetorBits so tem uma celula (1o caso de toy por exemplo)
    {
      vb0 = (tipoCampo*) malloc(numDiferentesConfig*(sizeof(tipoCampo)));

      //inicializa
      for(j=0; j<numDiferentesConfig; j++)
      {
        vb0[j].indiceVB = 0;
        vb0[j].conf = j;
        vb0[j].valor = -1;
        vb0[j].confProxCampo = NULL;
      }
    }
    else //Se o vetor de bits tem mais de uma celula OU se tem uma unica celula porem 100% cheia
    {
      vb0 = (tipoCampo*) malloc(256*(sizeof(tipoCampo)));

      //inicializa
      for(j=0; j<256; j++)
      {
        vb0[j].indiceVB = 0;
        vb0[j].conf = j;
        vb0[j].valor = -1;
        vb0[j].confProxCampo = NULL;
      }
    }


    //Varre a espaco de solucoes
    //--------------------------

    //Inicializacoes
    //Do vetor de bits todo zero 00000... a todo 1 11111...
    //Inicializa para a 1a configuracao do vetor
    for(j=0; j<tamVetorBits; j++)
    {
      vetorBits[j] = 0;
    }
    l = 0;

    aux = vb0[0]; //Aquie depende de onde começa o loop
    valorConfMax = -1;

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

          if((*aux).valor == -1) //Se o valor desse campo ainda não foi calculado
          {
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

            //- coloca no vetor
            if(abortouConf == NAO)
            {
              (*aux).valor = valorConf;
            }
            else //caso tenha abortado: salva isso no vetor pra nao precisar calular de novo
            {
              (*aux).valor = -1000;
            }

          }
          else //Se o valor desse campo já foi calculado + se eh um campo estourado
          {
            if((*aux).valor == -1000) //Se ja calculou e eh um campo estourado
            {
              abortouConf = SIM;
            }
            else //Se ja calculou e não estourou
            {
              valorConf = (*aux).valor;
            }
          }

          //Atualiza o aux de PD
          //--------------------

          if( (*aux).confProxCampo == NULL ) //Se nao tem lista dos proxcampos criadas para o aux mover
          {
            //cria a lista com todas as conf possiveis do proximo campo de bits
            //-----------------------------------------------------------------
            if(j == (tamVetorBits - 2)) //Se o proximo campo eh (tamVetorBits-1), o ultimo campo
            {
              if(bitsAmais == 0) //se eh um campo cheio normal
              {
                (*aux).confProxCampo = (apontador*) malloc(256*(sizeof(apontador)));
                //inicializa
                for(k=0; k<256; k++)
                {
                  (*aux).confProxCampo[k] = NULL;
                }
              }
              else //se nao eh um campo cheio, tem bitsAmais bits nele ativos so
              {
                (*aux).confProxCampo = (apontador*) malloc(numDiferentesConfig*(sizeof(apontador)));
                //inicializa
                for(k=0; k<numDiferentesConfig; k++)
                {
                  (*aux).confProxCampo[k] = NULL;
                }
              }
            }
            else //Se o proximo campo nao eh o ultimo campo (entao com certeza eh cheio, 8 bits)
            {
              (*aux).confProxCampo = (apontador*) malloc(256*(sizeof(apontador)));
              //inicializa
              for(k=0; k<256; k++)
              {
                (*aux).confProxCampo[k] = NULL;
              }
            }
          }

          //Anda com o aux
          if((*aux).confProxCampo[vetorBits[j+1]] == NULL)
          {
            //Cria essa celula e inicializa (basico?)
            (*aux).confProxCampo[vetorBits[j+1]] = (tipoCampo*) malloc(sizeof(tipoCampo));

            k = (*aux).indiceVB; //k atuando como temp
            *((*aux).confProxCampo[vetorBits[j+1]]).indiceVB = k+1;
            *((*aux).confProxCampo[vetorBits[j+1]]).conf = vetorBits[j+1];
            *((*aux).confProxCampo[vetorBits[j+1]]).valor = -1;
            *((*aux).confProxCampo[vetorBits[j+1]]).confProxCampo = NULL;

            //move o aux
            aux = (*aux).confProxCampo[vetorBits[j+1]];
          }
          else //Se o aux para o qual eu vou mover ja existe
          {
            aux = (*aux).confProxCampo[vetorBits[j+1]];
          }
        }

        if(abortouConf == SIM)
        {
          break;
        }

      }

      //---------------------------------------------------------------------
      //Agora muda o vetor todo para novos 010101100.. aqui abaixo:
      //-------------------REVER TUDO ISSO, LOGICA DE PERCORRER MUDEI UM POUCO

      //Confere se este eh o loop final
      l = 0;
      for(j=0; j<tamVetorBits; j++)
      {
        l = l + vetorBits[j];
      }
      //Confere se eh o loop final.
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
