#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  char oi[] = "oi";
  //printf("Oi tem comprimento %d.\n", strlen(oi));
  char tchau[] = "x e tchau!";
  //printf("Tchau tem compriemento %d.\n", strlen(tchau));

  strcpy(tchau, oi);
  //strcpy(oi, tchau);
  //strcat(oi, tchau);

  //printf("Novo string tem comprimento %d.\n", strlen(oi));
  printf("O string virou: %s\n",tchau);
  printf("Ela tem compriemento %d.\n", strlen(tchau));
  return 0;
}
