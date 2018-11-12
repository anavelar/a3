#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[ ]) {

  int k; //contador
  int n;

  //variaveis
  unsigned char uc = 0;
  int i = 0;

  /* teste 1
  i = 257;
  uc = i;

  printf("i=%d uc=%hhu\n", i, uc);
  */

  /* teste 2
  unsigned char valorBitUC;
  int valorBitI;

  for(k=0; k<259; k++)
  {
    printf("uc = %hhu = ", uc);
    for(n=7; n>=0; n--) //Aqui, n de 7 a 0.
    {
      valorBitUC = (uc & (1 << n));

      if(valorBitUC != 0)
      {
        printf("1");
      }
      else
      {
        printf("0");
      }
    }
    printf("\n");

    printf("i = %d = ", i);
    for(n=15; n>=0; n--) //Aqui, n de 7 a 0.
    {
      valorBitI = (i & (1 << n));

      if(valorBitI != 0)
      {
        printf("1");
      }
      else
      {
        printf("0");
      }
    }
    printf("\n");

    uc++;
    i++;
  }
  */

  return 0;
}
