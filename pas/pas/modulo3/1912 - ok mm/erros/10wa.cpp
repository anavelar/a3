/*
Estou recebendo 10% WA. Alguém sabe me dizer algum caso de teste onde este código não passa??

Hello, try this case: input: 2 3 4 4 0 0
output:
2.5000
*/

#include <bits/stdc++.h>
using namespace std;
double soma_area(double h, vector<double> &vet){
    double soma= 0.0;
    for(int i=0;i<(int)vet.size();i++){
        if(vet[i]>h){
            soma += vet[i]-h;
        }
    }
    return soma;
}

int main() {
    int n,a;
    while(scanf("%d %d",&n,&a) && n && a){
        vector<double> vet(n);
        double soma = 0,hmax = 0;
        for(int i=0;i<n;i++){
            scanf("%lf",&vet[i]);
            soma += vet[i];
            hmax = max(hmax,vet[i]);
        }

        double area_total = soma_area(0,vet);
        if(area_total == a) {
            printf(":D\n");
            continue;
        }else if(area_total < a){
            printf("-.-\n");
            continue;
        }else{
            double a1 = 0;
            double b1 = hmax;
            double meio = 0;
            while( b1 - a1 >= 0.00001){
                meio = (b1+a1)/2.;
                double res = soma_area(meio,vet);
                if(res > a) {
                    a1 = meio;
                } else if(res < a){
                    b1 = meio;
                } else break;
            }
            printf("%.4lf\n",b1);
        }

    }
    return 0;
}
