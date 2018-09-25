#include <stdio.h>

int main() {

  char um = 'a';
  char dois = 'z';

    printf("letra = %c, numero dela = %d\n", um, um);
    printf("letra = %c, numero dela = %d\n", dois, dois);
    printf("\n\n");

    int i;
    for (i=97; i <= 122; i++)
    {
      printf("%d o loop: numero %d corresponde a letra %c.\n", (i-96), i, i);
    }


    return 0;
}
