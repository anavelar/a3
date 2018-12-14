/*
Mesmo usando Busca Binaria está dando TLE :/

Existe alguma sacada nesse problema ? Implementei uma Busca binária e fica dando TLE
Alguem pode dar uma dica ?

Cuidado com a condição de parada, pode acontecer dela nunca ser aceita e seu programa ficar em loop infinito.
O que tu pode fazer é determinar um número máximo de iterações para a busca binária.

Eu tinha pensado nisso, mas não dá muito certo, não consigo encontrar
nenhum exemplo onde não há resposta e caia em um loop infinito.
Todas os exemplos que eu penso onde não há resposta caem na condição que coloquei.

RESPOSTA E RESOLUCAO NO CODIGO
*/

#include <stdio.h>
#include <stdlib.h>

double tiras (int *t, double p, double r, double a, double n);

int main(){

  int i, t[100000], nn;
  double n, a, soma = 0, maior = 0;

  while(scanf("%lf %lf", &n, &a) && n != 0) {
    soma = maior = 0;
    nn = (int) n;

    for (i = 0; i < nn; i++) {
      scanf("%d", &t[i]);
      if (i == 0 || maior < t[i])
        maior = t[i];
      soma += t[i];
    }

    if (soma == a)
      printf(":D\n");
    else
    if (soma < a)
      printf("-.-\n");
    else
      printf("%.4lf\n", tiras(t, 0, maior, a, n));

  }

}

double tiras (int *t, double p, double r, double a, double n) {
  int i;
  double corte, soma = 0;

  corte = (r + p) / 2.0;
  for (i = 0; i < n; i++)
    if (corte < t[i])
      soma += t[i] - corte;

  if (soma == a)
    return corte;

  if (soma > a)
    return tiras(t, corte, r, a, n);
  else
    return tiras(t, p, corte, a, n);

}
