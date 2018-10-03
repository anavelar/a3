#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  char nome[50] = "12345";
  char nome2[50] = "67";
  
  printf("string antes do strcpy:%s\n", nome);
  strcpy(nome, nome2);
  printf("nova string:%s\n", nome);

  return 0;
}
