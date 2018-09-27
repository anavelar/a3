//possiveis paus:
// 00 - TRATAMENTO DE CASOS BIZARROS NA ---- IMPRESSAO -----
// 01 - impressao - //PENSAR CASO FIM DO ARQUIVO TB C UMA LINHA EM BRANCO
// 0 - ********exemplo da pa: linha em branco no final nao imprime!!
// 1 - usando char como bool varias vezes, o uri faz a conversao char para int
// automático? Se não fizer vai dar pau, trocar tudo.
// 2.1 - *****olhar o caso arquivo vazio se precisa imprimir algo,
// arquivo sem nem \n, nada, so o fim de arquivo.
// 2 - ***Está imprimindo um \n após o último caso, atentar a isso! adequar na
// função implementada.
// 3 - *** feof(stdin) no final: feof sdtin vai valer p como os dados
// estao entrando no URI também?

//PRESSUPOSTOS: (possiveis paus parte 2)
// 1- ***Toda string/caso tem um \n no final, nao termina com EOF - pelo que vi
// no caso de teste.

//OTIMIZACOES DE TEMPO POSSIVEIS - TIME LIMIT
// 1- OU NAO - checar antes de 1 se caractere eh repetido:
// acho que vai aumentar o custo com o check ao inves de
// diminuir ja q nem sempre vem repetido e o custo da
// atribuicao eh baixo
// 2 - voltar alguns char para bool: conversoes pode dar time limit
// 3 - essas constantes atrapalham ou ajudam o tempo?
// 4- ****caso linha vazia: percorre o vetor mesmo assim
// 5 - TALVEZ - otimizar if-elses em switches? eh otimizar? eh possivel

#include <stdlib.h>
#include <stdio.h>

#define NUM_LETRAS_ALFABETO 26
#define DIFERENCA 97
#define ESPACO 32
#define SIM 1
#define NAO 0

void ResetaVetorCaso (char** eVetorCaso)
{
  int i;

  for (i=0; i<=25; i++)
  {
    (*(eVetorCaso))[i] = 0;
  }
}

int main() {

  //Variáveis e Estruturas de dados
  char* vetorCaso = (char*) malloc(NUM_LETRAS_ALFABETO * sizeof(char));
  char c;
  char fimArquivo = 0;
  char inicio = ESPACO;
  char final = ESPACO;
  int i;
  int jaImprimiu = NAO;

  //Programa
  //Criar estrutura para armazenar cada caso e a inicializa
  //OBS.:vou usar char para economizar espaço, pode ser decisao porca talvez
  ResetaVetorCaso(&vetorCaso);

  //Leitura de cada caso / linha
  //Cada caso
  fimArquivo = scanf("%c", &c);
  while(fimArquivo > 0) //Se o arquivo não está vazio / se chegou ao fim
  {
      //Le cada caso e preenche o vetor de presenca
      while(c != '\n')
      {
        if(c != ' ')
        {
          vetorCaso[c-DIFERENCA] = 1;
        }

        fimArquivo = scanf("%c", &c);
      }

      //Chegou ao fim do caso lido
      //Percorre o vetor e vai imprimindo as faixas de letras
      for (i=0; i<=25; i++)
      {
        if(vetorCaso[i]) // se li 1
        {
          if(i == 0) //primeira posicao, a
          {
            inicio = (i+97);
            final = (i+97);
          }
          else //outras posicoes do vetor de presenca,todas menos a
          {
            if(vetorCaso[i-1]) //o anterior eh 1
            {
              final = (i+97);

              if(i == 25) //Aí precisa tb imprimir e finalizar a sequencia ****IMP
              {
                if(jaImprimiu) //se ja imprimiu uma sequencia
                {
                  printf(", %c:%c", inicio, final);
                  inicio = ESPACO;
                  final = ESPACO;
                }
                else //se eh a primeira sequencia que vai ser impressa
                {
                  printf("%c:%c", inicio, final);
                  inicio = ESPACO;
                  final = ESPACO;
                  jaImprimiu = SIM;
                }
              }
            }
            else //o anterior eh zero
            {
              inicio = (i+97);
              final = (i+97);

              if(i == 25) //Aí precisa tb imprimir e finalizar a sequencia ****IMP
              {
                if(jaImprimiu) //se ja imprimiu uma sequencia
                {
                  printf(", %c:%c", inicio, final);
                  inicio = ESPACO;
                  final = ESPACO;
                }
                else //se eh a primeira sequencia que vai ser impressa
                {
                  printf("%c:%c", inicio, final);
                  inicio = ESPACO;
                  final = ESPACO;
                  jaImprimiu = SIM;
                }
              }
            }
          }
        }
        else // se li zero
        {
          if(i>0) //se nao estou na primeira pos, na a, ie se existe pos anterior
          {
            if(vetorCaso[i-1]) //posicao anterior eh 1
            {
              //finaliza uma sequencia ****IMP
              if(jaImprimiu) //se ja imprimiu uma sequencia
              {
                printf(", %c:%c", inicio, final);
                inicio = ESPACO;
                final = ESPACO;
              }
              else //se eh a primeira sequencia que vai ser impressa
              {
                printf("%c:%c", inicio, final);
                inicio = ESPACO;
                final = ESPACO;
                jaImprimiu = SIM;
              }
            }
            // else //posicao anterior eh zero: nao precisa fazer nada
          }
          //else (se i=0, se estou na posic a) --- ai nao precisa fazer nada
        }
      }

      if(jaImprimiu) //se algo foi impresso (se tinha letras para imprimir as faixas delas)
      {
        if(feof(stdin)) //se o arquivo acabou
        {
          //nao precisa imprimir \n
          //outras finalizações precisa? **********************88888888888888888
        }
        else //se tem mais casos a serem analisados no arquivo / mais linhas
        {
            printf("\n");
            //outras finalizações: reinicia **********************88888888888888888
        }
      }
      else //se a string era vazia: espacos em branco ou \n soh
      {
        //se era soh um \n no inicio ou so espacos em branco (string vazia)
        printf("\n");
        //outras finalizações: reinicia **********************88888888888888888
      }

      //-----------------------------------------------------------------------
      //nada aqui abaixo esta valido!!! so para base, ver ao final

      //printf("\n");
      fimArquivo = scanf("%c", &c);

      //aqui***************************************************************88
      //ELSE 1 ARRUMAR: Se eu li uma linha cheia (e ja fui imprimindo as coisas?)
      if(feof(stdin)) //vai funcionar com entradas de teste de arquivos txt?
      {

      }
      else
      {
          printf("\n");
      }
      //ELSE 2 ARRUMAR: Se eu li uma linha vazia no meio ou fim do arquivo, li um \n

      //Imprime os resultados e zera o vetor de presença para comecar novo caso
      //zera a variavel aux jaImprimiu, (inicio e fim tb ? -- acho q nao precisa) e
      //faz nova leitura precisa?

      //TIRAR ISSO AQUI AO FINAL *DE TUDO* , SO PRA BASE PROS CASOS JA FEITOS ACIMA
      printf("\n"); //leu uma linha vazia /\ *se for o ultimo \n do arquivo nao
      fimArquivo = scanf("%c", &c);

      //VER O CASO STRING VAZIA NO INICIO, NAO NO INICIO E \N ---- TESTAR TODOS OS FLUXOS
  }

  // -----------------TESTES E etc

  return 0;
}
