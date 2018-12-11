#include <stdlib.h>
#include <stdio.h>
#define VALOR_MAX 4294967296

int main()
{
  int i, j; //ate 3000
  FILE* pArqSaida = fopen("../../tp3-toyexample/max.in", "w");

  fprintf(pArqSaida,"3000 3000\n");

  //Cada uma das 3000 linhas
  for(j=0; j<3000; j++)
  {
    //Cada elemento da linha
    for(i=0; i<2999; i++)
    {
      fprintf(pArqSaida,"%li ", VALOR_MAX);
    }
    fprintf(pArqSaida,"%li\n", VALOR_MAX);
  }

  //teste
  fclose(pArqSaida);
  return 0;
}
