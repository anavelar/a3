#include <stdio.h>
#include <stdlib.h>

#define INICIALIZACAO 0

int main() {

  // VARIAVEIS E INICIALIZACAO
  // -------------------------

  int i; //Contadores

  int numCasosTeste = INICIALIZACAO; //Ate 100
  long int dinheiro = INICIALIZACAO; //De 1 ate 10^9, 1 bilhao
  int numIngredientesExistem = INICIALIZACAO; //De 1 a 100
  int numBolosExistem = INICIALIZACAO; //De 1 a 100

  //Vetor com os ingredientes (indices) e seus precos - id de 0 a (I-1)
  //Cada ingrediente custa entre 1 e 1000
  int* ingrediente = NULL;

  //Leitura de cada bolo
  //Ingredientes necessarios no bolo
  int numIngredientesDesteBolo = INICIALIZACAO; //De 1 a 100
  long int precoDesseBolo = INICIALIZACAO; //Ate 10^8: 100*1000*1000
  long int precoBoloMaisBarato =  INICIALIZACAO;

  //talve precise de variaveis auxiliares aqui.

  //PROGRAMA MESMO
  //--------------
  scanf("%d\n", numCasosTeste);

  //Para cada caso de teste
  for(i=0; i<numCasosTeste; i++)
  {






    //Reinicia as variaveis para o novo caso de teste
    dinheiro = INICIALIZACAO;
    numIngredientesExistem = INICIALIZACAO;
    numBolosExistem = INICIALIZACAO;
    //free(ingrediente); //ou algo similiar
    //int* ingrediente = NULL;
    numIngredientesDesteBolo = INICIALIZACAO;
    precoDesseBolo = INICIALIZACAO;
    precoBoloMaisBarato =  INICIALIZACAO;
    //talve mais variaveis auxiliares aqui.

  }


  return 0;

  //No fim, testar com valgrind
}
