#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[ ]) {

  unsigned char a;
  int n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
  //int n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
         //0 o mais a direita, 7 o  mais a esquerda.
  unsigned char valorBit; //Indica se bit eh zero ou 1.
                //Se valorBit = 0, esse bit eh zero.
                //Se valorBit > 0, esse bit eh um.
                //OBS.: >0 porque retorna o numero que eh.
                //Para retornar 1 precisa fazer (valorBit/a).
                //Mais uma operacao e nao precisa.

  //ATRIBUICOES
  a = 9;
  printf("O binario de %d eh ", a);

  for(n=7; n>=0; n--) //Aqui, n de 7 a 0.
  {
    valorBit = (a & (1 << n));

    if(valorBit != 0)
    {
      printf("1");
    }
    else
    {
      printf("0");
    }

  }
  printf("\n");
  return 0;
}
