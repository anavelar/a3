#include <stdio.h>
#include <stdlib.h>


int main() {

  // VARIAVEIS E INICIALIZACAO
  // -------------------------

  int i, j, k; //Contadores

  int numCasosTeste; //Ate 100
  long int dinheiro; //De 1 ate 10^9, 1 bilhao
  int numIngredientesExistem; //De 1 a 100
  int numBolosExistem; //De 1 a 100

  //Vetor com os ingredientes (indices) e seus precos - id de 0 a (I-1)
  //Cada ingrediente custa entre 1 e 1000
  int* precoIngrediente = NULL;

  //Leitura de cada bolo
  //Ingredientes necessarios no bolo
  int numIngredientesDesteBolo; //De 1 a 100
  long int custoIngrediente; //Entre 1 e 10^6
  int qualIngrediente; //Entre 0 e 99
  int quantidade; //Entre 1 e 1000
  long int precoDesseBolo; //Ate 10^8: 100*1000*1000
  long int precoBoloMaisBarato; //Max 10^8
  long int maxBolosPossivel;

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
    precoDesseBolo = 0;
    precoBoloMaisBarato =  100000001;
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

      if(precoDesseBolo < precoBoloMaisBarato )
      {
        precoBoloMaisBarato = precoDesseBolo;
      }
    }

    //Resultado do caso de teste
    maxBolosPossivel = dinheiro / precoBoloMaisBarato; //deve retornar int
    printf("%li\n", maxBolosPossivel);

    //Reinicia as variaveis para o novo caso de teste
    free(precoIngrediente); //ou algo similiar
    precoIngrediente = NULL;

  }

  return 0;

  //No fim, testar com valgrind
}
