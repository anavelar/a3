#include <stdio.h>

int main() {

    //1-Leitura de cada caso de teste
    char stringLida[52];

    while (scanf("%s\n", stringLida) > 0 )
    {
      //teste
      printf("A string lida foi %s\n", stringLida);
    }

    return 0;
}
