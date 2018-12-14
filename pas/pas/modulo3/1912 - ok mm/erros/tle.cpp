/*
Opa..
Você está codando uma solução O(N^2), e como N máximo é 10^5, sua solução se torna lenta demais...
É possível resolver com uma complexidade bem melhor utilizando uma busca binária... Você basicamente
chuta o valor do corte, e dependendo da soma das áreas, decide se seu chute foi alto ou baixo demais..
Repetindo o processo até que a área resultante seja igual o bastante.

Hum. Ok, Dâmi Henrique. Obrigado pela ajuda.
Não conheço busca binária nem estrutura de dados. Tenho que dar um estudada antes
rsrs e depois tentarei novamente. Obrigado mesmo já deu o caminho das pedras.
*/

#include<iostream>
using namespace std;

void quicksort(int *items, int len);
void qs (int *items, int left,int right);

int main(){

    int A, N, k, n, a, i, j = 0,soma = 0, somai, vet[100000],vet2[100000];
    float H = 0.0000,t = 0.0000;
    cin>>N>>A;

    do{

    somai = 0;
    for (a = 0;a < N ;a++){
        cin>>vet[a]; somai = somai + vet[a];
    }
    if (somai == A)
        cout<<":D"<<'\n';
    else if(somai < A)
        cout<<"-.-"<<'\n';
    else{
        quicksort(vet,a);
        i = 0; j = 0; n = 0;
        while(i < N){
            while (j < N){
                soma = soma + vet[j] - n;
                j++;
            }
        n = vet[i];
        vet2[i] = soma;
        i++; j = i; soma = 0;
        }
        i = N - 1; soma = 0;
        t = 1;
        while (vet2[i] <= A){
            soma = soma + vet[i];
            i--; t++;
        }
        soma = soma + vet[i];
        H = (soma - A)/t;
        std::cout.precision(4);
        std::cout.setf( std::ios::fixed, std:: ios::floatfield );
        std::cout<<H<<'\n';
        }
    cin>>N>>A;
    } while (N || A);

return 0;
}

void quicksort(int *items, int len){

    qs(items, 0, len - 1);
}

void qs(int *items, int left, int right){

    int i, j, x, y;

    i = left; j = right; x = items[(left + right)/2];

    do{
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if(i <= j){
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    }while (i <= j);

    if (left < j) qs (items, left, j);
    if (i < right) qs (items,i,right);
}
