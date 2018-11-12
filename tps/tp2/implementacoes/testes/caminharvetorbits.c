#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[ ]) {

  unsigned char a;
  int b;
  int n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
  //int n; //indice do bit, de 0 a 7 (8 bits, 1 byte).
         //0 o mais a direita, 7 o  mais a esquerda.
  unsigned char valorBit; //Indica se bit eh zero ou 1.
                //Se valorBit = 0, esse bit eh zero.
                //Se valorBit > 0, esse bit eh um.
                //OBS.: >0 porque retorna o numero que eh.
                //Para retornar 1 precisa fazer (valorBit/a).
                //Mais uma operacao e nao precisa.
  int parar = 0;

  //ATRIBUICOES
  for(a=0; a<=255; a++)
  {
    b = a;
    printf("a vale %hhu, b vale %d.\n", a, b);
    printf("a= ");
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
    printf("b= ");
    for(n=7; n>=0; n--) //Aqui, n de 7 a 0.
    {
      valorBit = (b & (1 << n));

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

  // LOOP INFINITO PORQUE DE 255 VAI P ZERO NO UNSIGNED CHAR
  //Coloquei aqui para ver
    parar++;
    if (parar == 260) //para no 1 do 3o loop
    {
      break;
    }
  }

  return 0;
}
