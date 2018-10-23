#include <stdlib.h>
#include <stdio.h>

int main()
{
  //Contadores
  int i;

  //Variaveis
  int numBrinquedos; //Entre 0 e 100
  int tempoTotalMaximo; //Entre 0 e 600
  int* tempoBrinquedo = NULL; //Cada tempo entre 0 e 600
  int* pontuacaoBrinquedo = NULL; //Cada brinquedo tem pontuacao entre 0 e 100
  int* pontucaoMaxPorTempo = NULL;
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
      scanf("%d %d\n", &tempoBrinquedo[i], &pontuacaoBrinquedo[i]);
    }

    //Inicializacao vetor pontuacao maxima por cada tempo
    pontucaoMaxPorTempo = (int*) malloc((tempoTotalMaximo+1)*(sizeof(int)));
    for(i=0; i<(tempoTotalMaximo+1); i++)
    {
      pontucaoMaxPorTempo[i] = 0;
    }

    //Programa
    //Podemos ver subestrutura otima no problema.
    //A solucao para o tempo maximo menor é usada para chegar no tempoMaximo meta
    //do problema. Assim, eh possivel usar programacao dinamica e armazenar a
    //pontucao maxima (otima) para tempos menores.

    //Percorrendo tempos menores < TempoTotalMax para achar o otimo deles,
    //que vai ser usado para composicao da solucao e para chegar ao otimo final.
    for(tempoMax=0; tempoMax<(tempoTotalMaximo+1); tempoMax++)
    {
      //Para cada tempo menor, analisa a solucao, percorrendo todos os brinquedos
      //para calcular a solucao otima naquele tempo.
      for(brinquedo=0; brinquedo<numBrinquedos; brinquedo++)
      {
        //Se eh possivel esse brinquedo estar na solucao
        if(tempoBrinquedo[brinquedo] <= tempoMax)
        {
          //Subestrutura otima: se ((a solucao otima sem ele) + ele) fica melhor do que a solucao otima atual
          if(pontucaoMaxPorTempo[tempoMax] < (pontucaoMaxPorTempo[tempoMax-tempoBrinquedo[brinquedo]]+pontuacaoBrinquedo[brinquedo]))
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

    //Reinicia as variaveis do caso de teste
    free(pontucaoMaxPorTempo);
    free(tempoBrinquedo);
    free(pontuacaoBrinquedo);
    scanf("%d %d\n", &numBrinquedos, &tempoTotalMaximo);
  }

  //Se chegou aqui o numero de brinquedos foi zero entao nao precisa fazer nada.
  //Ou entrou num caso de teste vazio.
  //Fim da leitura e do programa.

  return 0;
}
