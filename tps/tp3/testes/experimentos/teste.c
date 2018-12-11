#include <stdlib.h>
#include <stdio.h>

int main(){

  int maximo, medianaInferior;
  maximo = 27;

  medianaInferior =  ((int) (maximo / 2));
  printf("Maximo / 2 = %f.\n", ((float) medianaInferior));

  medianaInferior += 1;
  printf("Maximo + 1 = %f.\n", ((float) medianaInferior));

  return 0;
}
