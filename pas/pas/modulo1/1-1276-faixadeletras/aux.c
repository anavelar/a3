#include <stdio.h>

int main() {

  char um = 'a';
  char dois = 'z';
  char espaco = ' ';

    printf("letra = %c, numero dela = %d\n", um, um);
    printf("letra = %c, numero dela = %d\n", dois, dois);
    printf("espaco = %c, numero dele = %d\n", espaco, espaco);
    printf("\n\n");

    int i;
    for (i=97; i <= 122; i++)
    {
      printf("%d o loop: numero %d corresponde a letra %c.\n", (i-96), i, i);
    }


    return 0;
}
