#include <stdio.h>
#include <stdlib.h>

//Conclusao: um vetor é passado SEMPRE POR REFERENCIA.

void mudaVetor(int* vetor)
{
  int k;
  for(k=0; k<10; k++)
  {
    vetor[k] = (k+1);
  }

}

int main(int argc, char *argv[ ]) {

  int* vetorInt = (int*) malloc(10*sizeof(int));
  int i;

  for(i=0; i<10; i++)
  {
    vetorInt[i] = 0;
  }

  //Imprime para ver
  printf("Vetor Inicial:\n");
  for(i=0; i<10; i++)
  {
    printf("%d\n", vetorInt[i]);
  }

  mudaVetor(vetorInt);

  //Imprime para ver
  printf("Vetor depois:\n");
  for(i=0; i<10; i++)
  {
    printf("%d\n", vetorInt[i]);
  }

  //Fim
  free(vetorInt);
  return 0;
}
