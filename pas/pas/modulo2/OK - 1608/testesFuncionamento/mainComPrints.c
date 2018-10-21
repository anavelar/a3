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

  //Vetor com os ingredientes (indices) e seus precos - id de 0 a 99
  //Cada ingrediente custa entre 1 e 1000: int
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
  //teste
  printf("Casos de teste: %d.\n", numCasosTeste);
  //fimteste


  //Para cada caso de teste
  for(i=0; i<numCasosTeste; i++)
  {
    scanf("%li %d %d\n", &dinheiro, &numIngredientesExistem, &numBolosExistem);
    //teste
    printf("Dinheiro:%li, numIngredientesExistes:%d e numBolosExistem:%d.\n", dinheiro, numIngredientesExistem, numBolosExistem);
    //fimteste
    precoIngrediente = (int*) malloc(numIngredientesExistem*(sizeof(int)));
    for(j=0; j<(numIngredientesExistem-1); j++)
    {
      scanf("%d ", &(precoIngrediente[j]));
    }
    //teste
    printf("Ingredientes:\n");
    for(j=0; j<(numIngredientesExistem-1); j++)
    {
      printf("Ingrediente %d: preco %d.\n", j, precoIngrediente[j]);
    }
    //fimteste
    //leitura do ultimo
    scanf("%d\n", &(precoIngrediente[(numIngredientesExistem-1)]));
    //teste
    printf("Ingrediente %d: preco %d.\n", j, precoIngrediente[j]);
    //fimteste

    precoBoloMaisBarato =  100000001;
    //Para cada bolo existente
    for(j=0; j<numBolosExistem; j++)
    {
      //Inicializacao basica
      precoDesseBolo = 0;
      scanf("%d ", &numIngredientesDesteBolo);
      //teste
      printf("Ingredientes no %do bolo: %d\n", (j+1), numIngredientesDesteBolo);
      //fimteste

      //Le cada dupla ingrediente e quantidade dele
      for(k=0; k<(numIngredientesDesteBolo-1); k++)
      {
        scanf("%d %d ", &qualIngrediente, &quantidade);
        custoIngrediente = precoIngrediente[qualIngrediente]*quantidade;
        precoDesseBolo = precoDesseBolo + custoIngrediente;
        //teste
        printf("Ingrediente %d:%d unidades.", qualIngrediente, quantidade);
        printf("Logo custa %li colocar o ingrediente %d no bolo.\n", custoIngrediente, qualIngrediente);
        printf("Apos soma-lo, preco total do bolo vira: %li.\n\n",precoDesseBolo);
        //fimteste
      }

      //leitura do ultimo par:
      scanf("%d %d\n", &qualIngrediente, &quantidade);
      custoIngrediente = precoIngrediente[qualIngrediente]*quantidade;
      precoDesseBolo = precoDesseBolo + custoIngrediente;
      //teste
      printf("Ingrediente %d:%d unidades.", qualIngrediente, quantidade);
      printf("Logo custa %li colocar o ingrediente %d no bolo.\n", custoIngrediente, qualIngrediente);
      printf("Apos soma-lo, preco total do bolo vira: %li.\n\n",precoDesseBolo);
      //fimteste

      if(precoDesseBolo < precoBoloMaisBarato )
      {
        precoBoloMaisBarato = precoDesseBolo;
      }
      //teste
      printf("Bolo mais barato ate agora: %li.\n", precoBoloMaisBarato);
      //fimteste

    }

    //Resultado do caso de teste
    maxBolosPossivel = dinheiro / precoBoloMaisBarato; //deve retornar int
    //teste
    printf("Dinheiro:%li.Preco Bolo mais barato:%li. Max bolos possivel:%li.\n\n",
    dinheiro, precoBoloMaisBarato, maxBolosPossivel);
    //fimteste

    //VOLTAR DEPOIS DO DEBUGADO: printf("%li\n", maxBolosPossivel);

    //Reinicia as variaveis para o novo caso de teste
    free(precoIngrediente); //ou algo similiar
    precoIngrediente = NULL;

  }

  return 0;

  //No fim, testar com valgrind
}
