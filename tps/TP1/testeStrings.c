#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

  /*
  char oi[] = "a";
  int i = 19887;

  sprintf(oi, "%d", i);
  printf("a string eh: %s, comprimento %d.\n", oi, strlen(oi));
  */



  char oi[] = "oi";
  //printf("Oi tem comprimento %d.\n", strlen(oi));
  char tchau[] = " e tchau!";
  //printf("Tchau tem compriemento %d.\n", strlen(tchau));

  //strcpy(tchau, oi);
  //strcpy(oi, tchau);
  strcat(oi, tchau);

  //printf("Novo string tem comprimento %d.\n", strlen(oi));
  printf("O string virou: %s\n",oi);
  printf("Ela tem compriemento %d.\n", strlen(oi));

  return 0;
}
