/*
Está dando 10% de erro. Alguém sabe em que caso pode ser?

Hello, try this case: input: 2 3 4 4 0 0
output:
2.5000
*/
#include <stdio.h>
#include <stdlib.h>
#define ERRO 0.00001 //**************

float buscaBinaria(int area, int tira[], int n, float inicio, float fim) {
    int i;
    float corte = (fim + inicio) / 2.0, areaCorte = 0;
    for(i = 0; i < n; i++) {
        if((float)tira[i] > corte) {
            areaCorte += ((float)tira[i] - corte);
        }
    }
    if(fim - inicio < ERRO) {
        return corte;
    } else if(areaCorte > (float)area) {
        return buscaBinaria(area, tira, n, corte, fim);
    } else {
        return buscaBinaria(area, tira, n, inicio, corte);
    }
}

int main(void) {
    int a, n, i, areaTira;
    int tira[100000];
    float h, maior = 0;

    scanf("%d %d", &n, &a);
    while(n != 0 && a != 0) {
        areaTira = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &tira[i]);
            areaTira += tira[i];
            if((float)tira[i] > maior) {
                maior = (float)tira[i];
            }
        }

        if(areaTira == a) {
            printf(":D\n");
        } else if(areaTira < a) {
            printf("-.-\n");
        } else {
            h = buscaBinaria(a, tira, n, 0.0, maior);
            printf("%.4f\n", h);
        }


        scanf("%d %d", &n, &a);
    }
    return 0;
}
