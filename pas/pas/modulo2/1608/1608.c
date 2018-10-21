#include <stdio.h>
#include <stdlib.h>

#define INICIALIZACAO 0

int main() {

  // VARIAVEIS E INICIALIZACAO
  // -------------------------

  int i, j, k; //Contadores

  int numCasosTeste = INICIALIZACAO; //Ate 100
  long int dinheiro = INICIALIZACAO; //De 1 ate 10^9, 1 bilhao
  int numIngredientesExistem = INICIALIZACAO; //De 1 a 100
  int numBolosExistem = INICIALIZACAO; //De 1 a 100

  //Vetor com os ingredientes (indices) e seus precos - id de 0 a (I-1)
  //Cada ingrediente custa entre 1 e 1000
  int* precoIngrediente = NULL;

  //Leitura de cada bolo
  //Ingredientes necessarios no bolo
  int numIngredientesDesteBolo = INICIALIZACAO; //De 1 a 100
  long int custoIngrediente = INICIALIZACAO; //Entre 1 e 10^6
  int qualIngrediente = INICIALIZACAO; //Entre 0 e 99
  int quantidade = INICIALIZACAO; //Entre 1 e 1000
  long int precoDesseBolo = INICIALIZACAO; //Ate 10^8: 100*1000*1000
  //long int precoBoloMaisBarato =  MAISCARO; **************************

  //talve precise de variaveis auxiliares aqui.

  //PROGRAMA MESMO
  //--------------
  scanf("%d\n", &numCasosTeste);

  //Para cada caso de teste
  for(i=0; i<numCasosTeste; i++)
  {
    scanf("%li %d %d\n", &dinheiro, &numIngredientesExistem, &numBolosExistem);
    precoIngrediente = (int*) malloc(numIngredientesExistem*(sizeof(int)));
    for(j=0; j<(numIngredientesExistem-1); j++)
    {
      scanf("%d ", &(precoIngrediente[j]));
    }
    //leitura do ultimo
    scanf("%d\n", &(precoIngrediente[(numIngredientesExistem-1)]));

    //Para cada bolo existente
    precoDesseBolo = INICIALIZACAO; //pode remover talvez *****************
    //precoBoloMaisBarato =  MAISCARO; *****************************
    for(j=0; j<numBolosExistem; j++)
    {
      scanf("%d ", &numIngredientesDesteBolo);
      for(k=0; k<((numIngredientesDesteBolo-1)*2); k++)
      {
        scanf("%d %d ", &qualIngrediente, &quantidade);
        custoIngrediente = precoIngrediente[qualIngrediente]*quantidade;
        precoDesseBolo = precoDesseBolo + custoIngrediente;
      }
      //leitura do ultimo par:
      scanf("%d %d\n", &qualIngrediente, &quantidade);
      custoIngrediente = precoIngrediente[qualIngrediente]*quantidade;
      precoDesseBolo = precoDesseBolo + custoIngrediente;

      //aqui e nos dependentes daqui anteriores**********************8
    }





    //CONFERIR DE NOVO SE DESALOQUEI TUDO
    //Reinicia as variaveis para o novo caso de teste
    dinheiro = INICIALIZACAO;
    numIngredientesExistem = INICIALIZACAO;
    numBolosExistem = INICIALIZACAO;
    free(precoIngrediente); //ou algo similiar
    precoIngrediente = NULL;
    numIngredientesDesteBolo = INICIALIZACAO;
    precoDesseBolo = INICIALIZACAO;
    precoBoloMaisBarato =  INICIALIZACAO;
    //talve mais variaveis auxiliares aqui.

  }

  return 0;

  //No fim, testar com valgrind
}
