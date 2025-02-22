// APOS - RETIRAR COMENTARIOS LK
//*******************************************
//*******************************************
//*******************************************
//*******************************************
//*******************************************

//QUESTOES: ******************************************************************
// 00 - dei free e reiniciei td mundo a cada caso? ver e ver c valgrind memoria ok
// 0 - pontucaoMaxPorTempo precisa ser long int? calcular
// 1 - instancia precisa ser long int? ver na espec de novo

#include <stdlib.h>
#include <stdio.h>

int main()
{
  //Contadores
  int i;

  //Variaveis
  int numBrinquedos; //Entre 0 e 100 ---------------//n - N
  int tempoTotalMaximo; //Entre 0 e 600 ------------//W - T
  int* tempoBrinquedo = NULL; //Cada tempo entre 0 e 600 ----//wt - D
  int* pontuacaoBrinquedo = NULL; //Cada brinquedo tem pontuacao entre 0 e 100-//val - P
  int* pontucaoMaxPorTempo = NULL; //int ou maior? -----//dp
  int casoTeste = 1;
  //Auxiliares para percorrer
  int tempoMax;
  int brinquedo;

  scanf("%d %d\n", &numBrinquedos, &tempoTotalMaximo);
  //Cada caso de teste, cada instancia
  while(numBrinquedos != 0)
  {
    //Leitura dos dados sobre as atracoes
    tempoBrinquedo = (int*) malloc(numBrinquedos*(sizeof(int)));
    pontuacaoBrinquedo = (int*) malloc(numBrinquedos*(sizeof(int)));
    for(i=0; i<numBrinquedos; i++)
    {
      scanf("%d %d\n", &tempoBrinquedo[i], &pontucaoBrinquedo[i]);
    }

    //Inicializacao vetor resultados por tempo
    pontucaoMaxPorTempo = (int*) malloc((tempoTotalMaximo+1)*(sizeof(int)));
    for(i=0, i<(tempoTotalMaximo+1); i++)
    {
      pontucaoMaxPorTempo[i] = 0;
    }

    //Para cada tempoMax possivel, de tempoMax 0 ate tempoMax do problema
    for(tempoMax=0; tempoMax<(tempoTotalMaximo+1); tempoMax++) //----tempoMax:i
    {
      //Analisa cada atracao do parque
      for(brinquedo=0; brinquedo<numBrinquedos; brinquedo++) //--- brinquedo:j
      {
        if(tempoBrinquedo[brinquedo] <= tempoMax)
        {
          if(pontucaoMaxPorTempo[tempoMax]
             <
             (pontucaoMaxPorTempo[tempoMax-tempoBrinquedo[brinquedo]]+pontuacaoBrinquedo[brinquedo])
            )
          {
            pontucaoMaxPorTempo[tempoMax] = (pontucaoMaxPorTempo[tempoMax-tempoBrinquedo[brinquedo]]+pontuacaoBrinquedo[brinquedo]);
          }
        }
      }
    }

    //Imprime o resultado deste caso de teste
    printf("Instancia %d\n", casoTeste);
    casoTeste++;
    printf("%d\n\n", pontucaoMaxPorTempo[tempoTotalMaximo]);

    //VOLTAR AQUI: DA FREE EM TD MUNDO E REINICIA ***************
    //Reinicia as variaveis do caso de teste
    free(pontucaoMaxPorTempo);
    free(tempoBrinquedo);
    free(pontuacaoBrinquedo);
    scanf("%d %d\n", &numBrinquedos, &tempoTotalMaximo);
  }

  //Se chegou aqui o numero de brinquedos foi zero entao nao precisa
  //fazer nada.
  //Ou entrou num caso de teste vazio.
  //Fim da leitura e do programa.

  //Rodar valgrind no fim pra conferir, nao esquecer **********************

  return 0;
}
