#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int numNomes;
    char* n1;
    char* n2;
}tipoNota;

//Entra o vetor de notas em nota e a string com a nota lida em notalida.
//Retorna o indice do vetor de notas que representa a nota lida.
int identificaNota(char* notalida, tipoNota* nota)
{
    int k;

    for(k=0; k<12; k++)
    {
        if(nota[k].numNomes == 1)
        {
            if (!strcmp(nota[k].n1, notalida))
            {
                return k;
            }
        }
        else //notas[k].numNomes == 2
        {
            if (!strcmp(nota[k].n1, notalida))
            {
                return k;
            }

            if (!strcmp(nota[k].n2, notalida))
            {
                return k;
            }

        }
    }
}


int main()
{
    long int m;
    int t;

    char* stringm;
    char* stringt;
    int im, it; //índices nos strings stringm e stringt
    int valor1, valor2; //indice de uma nota no vetor de notas

    int i;
    char* leit;

    //cria o vetor de notas e inicializa ele
    tipoNota nota[12];
    nota[0].numNomes = 1;
    nota[0].n1 = (char*)malloc(2*sizeof(char));
    nota[0].n1[0] = 'A';
    nota[0].n1[1] = '\0';
    nota[0].n2 = NULL;

    nota[1].numNomes = 2;
    nota[1].n1 = (char*)malloc(3*sizeof(char));
    nota[1].n1[0] = 'A';
    nota[1].n1[1] = '#';
    nota[1].n1[2] = '\0';
    nota[1].n2 = (char*)malloc(3*sizeof(char));
    nota[1].n2[0] = 'B';
    nota[1].n2[1] = 'b';
    nota[1].n2[2] = '\0';

    nota[2].numNomes = 2;
    nota[2].n1 = (char*)malloc(2*sizeof(char));
    nota[2].n1[0] = 'B';
    nota[2].n1[1] = '\0';
    nota[2].n2 = (char*)malloc(3*sizeof(char));
    nota[2].n2[0] = 'C';
    nota[2].n2[1] = 'b';
    nota[2].n2[2] = '\0';

    nota[3].numNomes = 2;
    nota[3].n1 = (char*)malloc(2*sizeof(char));
    nota[3].n1[0] = 'C';
    nota[3].n1[1] = '\0';
    nota[3].n2 = (char*)malloc(3*sizeof(char));
    nota[3].n2[0] = 'B';
    nota[3].n2[1] = '#';
    nota[3].n2[2] = '\0';

    nota[4].numNomes = 2;
    nota[4].n1 = (char*)malloc(3*sizeof(char));
    nota[4].n1[0] = 'C';
    nota[4].n1[1] = '#';
    nota[4].n1[2] = '\0';
    nota[4].n2 = (char*)malloc(3*sizeof(char));
    nota[4].n2[0] = 'D';
    nota[4].n2[1] = 'b';
    nota[4].n2[2] = '\0';

    nota[5].numNomes = 1;
    nota[5].n1 = (char*)malloc(2*sizeof(char));
    nota[5].n1[0] = 'D';
    nota[5].n1[1] = '\0';
    nota[5].n2 = NULL;

    nota[6].numNomes = 2;
    nota[6].n1 = (char*)malloc(3*sizeof(char));
    nota[6].n1[0] = 'D';
    nota[6].n1[1] = '#';
    nota[6].n1[2] = '\0';
    nota[6].n2 = (char*)malloc(3*sizeof(char));
    nota[6].n2[0] = 'E';
    nota[6].n2[1] = 'b';
    nota[6].n2[2] = '\0';

    nota[7].numNomes = 2;
    nota[7].n1 = (char*)malloc(2*sizeof(char));
    nota[7].n1[0] = 'E';
    nota[7].n1[1] = '\0';
    nota[7].n2 = (char*)malloc(3*sizeof(char));
    nota[7].n2[0] = 'F';
    nota[7].n2[1] = 'b';
    nota[7].n2[2] = '\0';

    nota[8].numNomes = 2;
    nota[8].n1 = (char*)malloc(2*sizeof(char));
    nota[8].n1[0] = 'F';
    nota[8].n1[1] = '\0';
    nota[8].n2 = (char*)malloc(3*sizeof(char));
    nota[8].n2[0] = 'E';
    nota[8].n2[1] = '#';
    nota[8].n2[2] = '\0';

    nota[9].numNomes = 2;
    nota[9].n1 = (char*)malloc(3*sizeof(char));
    nota[9].n1[0] = 'F';
    nota[9].n1[1] = '#';
    nota[9].n1[2] = '\0';
    nota[9].n2 = (char*)malloc(3*sizeof(char));
    nota[9].n2[0] = 'G';
    nota[9].n2[1] = 'b';
    nota[9].n2[2] = '\0';

    nota[10].numNomes = 1;
    nota[10].n1 = (char*)malloc(2*sizeof(char));
    nota[10].n1[0] = 'G';
    nota[10].n1[1] = '\0';
    nota[10].n2 = NULL;

    nota[11].numNomes = 2;
    nota[11].n1 = (char*)malloc(3*sizeof(char));
    nota[11].n1[0] = 'G';
    nota[11].n1[1] = '#';
    nota[11].n1[2] = '\0';
    nota[11].n2 = (char*)malloc(3*sizeof(char));
    nota[11].n2[0] = 'A';
    nota[11].n2[1] = 'b';
    nota[11].n2[2] = '\0';

    //começa a analisar cada caso
    scanf("%ld %d ", &m, &t);
    while( m && t)  //cada caso de teste (obs.: pela espec do problema m>=1 e t>=1 sempre)
    {
        stringm = (char*)malloc(100001*sizeof(char));
        stringt = (char*)malloc(10001*sizeof(char));
        im = 0;
        it = 0;

        leit = (char*)malloc(3*sizeof(char)); //vai ler notas, dois mais \0 no max, logo 3 no max

        //primeira nota
        scanf("%s ", leit);
        valor1 = identificaNota(leit, nota);

        if (m>1)
        {
            for(i=1; i<m; i++)
            {
                scanf("%s ", leit);
                valor2 = identificaNota(leit, nota);

                stringm[im] = ((valor2-valor1+12)%12)+48; //distancia entre valor2-valor1
                im++;

                valor1 = valor2;
            }
        }

        //chega aqui ao final
        stringm[im] = '\0';

        //agora lendo o trecho:
        //primeira nota
        scanf("%s ", leit);
        valor1 = identificaNota(leit, nota);

        if (t>1)
        {
            for(i=1; i<t; i++)
            {
                scanf("%s ", leit);
                valor2 = identificaNota(leit, nota);

                stringt[it] = ((valor2-valor1+12)%12)+48; //distancia entre valor2-valor1
                it++;

                valor1 = valor2;
            }
        }

        //chega aqui ao final
        stringt[it] = '\0';


        if((m>1 && t>1) && (strstr(stringm, stringt) != NULL)) //*************uma nota não conta como copia da musica
        {
            printf("S\n");
            //teste
            //printf("stringt lida foi %s e stringm lida foi %s.\n", stringt, stringm);
        }
        else
        {
            printf("N\n");
            //teste
            //printf("stringt lida foi %s e stringm lida foi %s.\n", stringt, stringm);
        }

        //fim, acaba ou passa para o proximo caso:
        free(leit);
        free(stringm);
        free(stringt);
        scanf("%ld %d ", &m, &t);
    }

    return 0;
}
