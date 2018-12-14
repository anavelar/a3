/*
Estou tomando um TLE de 4 segundos! Nunca tomei um TLE tão grande numa busca binária,
desconfio que seja a forma de ordenação feita (não conheço muito o c++). Alguém sabe
qual seria a melhor forma de otimizar essa ordenação decrescente dos valores?

Pra passar este problema precisei fazer um ajuste fino nos valores do EPS e da quantidade de iterações máximas da busca binária.

Dependendo do valor de EPS que você escolher ele dará wrong answer. Um bom valor é 0.0001.
*/

#include <bits/stdc++.h>

using namespace std;

float busca_binaria(float tiras[], int tamanho, float valor_busca){
    float minimo = 0;
    float maximo = tiras[0];
    float meio, tiras_cortadas;

    do{
        meio = (minimo+maximo)/2;
        tiras_cortadas = 0;

        for(int i=0; (i < tamanho) && (tiras[i] > meio) && (tiras_cortadas <= valor_busca); i++){
            tiras_cortadas += tiras[i]-meio;
        }

        if(tiras_cortadas < valor_busca){
            maximo = meio;
        }else if(tiras_cortadas > valor_busca){
            minimo = meio;
        }
    }while(tiras_cortadas != valor_busca);

    return meio;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int N, A, soma;

    while((cin >> N >> A) && ((N != 0) && (A != 0))){
        float tiras[N];
        soma = 0;

        for(int i=0; i < N; i++){
            cin >> tiras[i];
            soma += tiras[i];
        }

        if(soma < A){
            printf("-.-\n");
        }else if(soma == A){
            printf(":D\n");
        }else{
            sort(tiras, tiras + N, greater<float>()); // Ordem decrescente
            printf("%.4f\n", busca_binaria(tiras, N, A));
        }
    }

    return 0;
}
