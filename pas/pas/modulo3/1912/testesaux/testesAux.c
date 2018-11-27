#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float mexe1(float conver)
{
  conver = conver* ((float) 10000);
  conver = (conver > (floor(conver)+ ((float) 0.5))) ? ceil(conver) : floor(conver);
  //conver = conver/ ((float) 1000);

  return conver;
}


float mexe3(float conver)
{
  conver = roundf(conver*1000.0f)/1000.0f;

  return conver;
}

float mexe2(float conver)
{
  conver = conver * ((float) 1000);
  conver = roundf(conver);
  conver = conver / ((float) 1000);

  return conver;
}


int main(int argc, char *argv[]) {

  float a, b, c, d;

  a = 52.98094940;
  b = 17.88174820;
  c = 68.30435181;
  d = 93.89654541;

  printf("A impresso vale %0.4f.\n", a);
  printf("A com mexe vale %f.\n\n", mexe1(a));

  printf("B impresso vale %0.4f\n", b);
  printf("B com mexe vale %f.\n\n", mexe1(b));

  printf("C impresso vale %0.4f\n", c);
  printf("C com mexe vale %f.\n\n", mexe1(c));

  printf("D impresso vale %0.4f\n", d);
  printf("D com mexe vale %f.\n\n", mexe1(d));


  /*
  float conver = 45.592346543;
  printf("conver is %0.1f\n",conver);

  conver = conver*10.0f;
  conver = (conver > (floor(conver)+0.5f)) ? ceil(conver) : floor(conver);
  conver = conver/10.0f;

  //If you're using C99 or better, rather than ANSI C/C89/C90, the following will also work.
  //conver = roundf(conver*10.0f)/10.0f;

  printf("conver is now %f\n",conver);
  return 0;
  */



  return 0;
}
