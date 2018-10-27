#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[ ]) {

  /*
  unsigned char a;
  unsigned char novoa;

  a = 4;
  printf("a foi atribuido %d.\n", a);

  novoa = a << 1;
  printf("novoa = a << 1 eh igual a %d.\n", novoa);
  */


  /* --- VERSAO BASICA DE TESTE
  int n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
  a = 4; // 4 = 000 00 100
  n = 3;
  printf("valor calculado para a=%d e indice n=%d.\n",a,n);
  printf("%d.\n\n", (a & (1 << n)));
  */



  //sofisticacao
  unsigned char a;
  unsigned char n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
  //int n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
         //0 o mais a direita, 7 o  mais a esquerda.
  unsigned char valorBit; //Indica se bit eh zero ou 1.
                //Se valorBit = 0, esse bit eh zero.
                //Se valorBit > 0, esse bit eh um.
                //OBS.: >0 porque retorna o numero que eh.
                //Para retornar 1 precisa fazer (valorBit/a).
                //Mais uma operacao e nao precisa.

  //ATRIBUICOES
  a = 4;
  //n=0;
  //teste da funcao
  printf("O binario de %d eh ", a);
  //for(n=0; n<8; n++)
  for(n=7; n<8; n--) //n eh unsigned int: n-1 = 0-1 = 255. Aqui, n de 7 a 0.
  {
    //printf("Antes: a=%d, n=%d, valorBit=%d.\n", a,n,valorBit);
    //valorBit = (a & (1 << n));
    valorBit = (a & (1 << n));
    //printf("Depois: a=%d, n=%d, valorBit=%d.\n\n", a,n,valorBit);
    /*
    if(n>7)
    {
      break;
    }
    */

    //printf("%d", valorBit);

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
  //OBS.: Esta impresso o binario na ordem contraria porque estou imprindo
  //da esquerda p direita, se eu inverter vai.
  return 0;
}
