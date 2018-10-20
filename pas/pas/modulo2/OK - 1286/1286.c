#include <stdlib.h>
#include <stdio.h>

//supondo tempo pedido cabe num int (no struct)
//supondo tempo maximo cabe num int

int main()
{
    int numPedidos;//entre 1 e 20
    int maxPizzas; //entre 1 e 30
    int i, j; //contadores

    int* tempo;
    int* numPiz;
    int** s;
    int t1, t2;

    scanf("%d ", &numPedidos);
    while(numPedidos != 0)    //cada caso de teste
    {
        scanf("%d ", &maxPizzas);
        tempo = malloc((numPedidos+1)*sizeof(int));
        numPiz = malloc((numPedidos+1)*sizeof(int));

        //lê cada pedido e insere nos vetores
        tempo[0] = 0;
        numPiz[0] = 0;
        for(i=1; i<numPedidos+1; i++)
        {
            scanf("%d %d ", &(tempo[i]), &(numPiz[i]));
        }

        //matriz de soluções para usar na recursividade do problema
        s = malloc ((numPedidos+1) * sizeof(int*));
        for (i = 0; i < (numPedidos+1); i++)
        {
            s[i] = malloc ((maxPizzas+1) * sizeof(int));
        }

        //inicializa 1a coluna da matriz
        for(i=0; i<(numPedidos+1); i++)
        {
            s[i][0] = 0;
        }

        //preenche matriz
        for(j=1; j<(maxPizzas+1); j++)
        {
            s[0][j] = 0; //inicializa 1a linha

            for(i=1; i<(numPedidos+1); i++)
            {
                t1 = s[i-1][j];

                if(j-numPiz[i] >= 0) //quando numPiz[i] for no max j
                {
                    t2 = s[i-1][j-numPiz[i]] + tempo[i];

                    if(t1<t2)
                    {
                        t1 = t2;
                    }
                }

                s[i][j] = t1;
            }
        }

        /*
        //teste
        for(i=0; i<(numPedidos+1); i++)
        {
            for(j=0; j<(maxPizzas+1); j++)
            {
                printf("%d ", s[i][j]);
            }

            printf("\n");
        }
        //fimteste
        */

        //FIM DO CASO ANALISADO
        printf("%d min.\n", s[numPedidos][maxPizzas]);

        //fim do caso de teste e prepara p inicio do outro:
        //desaloca td e reinicializa
        free(tempo);
        free(numPiz);
        for(i=0; i<(numPedidos+1); i++)
        {
            free(s[i]);
        }
        free(s);

        scanf("%d ", &numPedidos);
    }

    return 0;
}
