#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[ ]) {

  //teste da operacao ^

  int a;
  int b;
  double resultadoDouble;
  int resultado;

  a = 2;
  b = 3;
  resultadoDouble = pow( ((double)a), ((double)b) );
  resultado = (int) resultadoDouble; //ta certo essa conv?

  printf("a:%d, b:%d, e a^b=%d.\n", a, b, resultado);

  return 0;
}
