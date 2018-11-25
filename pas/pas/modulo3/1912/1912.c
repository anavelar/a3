//OBS:
////Depois adicionar uma condicao de parada**************************************************8
// SENAO TIME LIMIT EXCEEDED

#include <stdlib.h>
#include <stdio.h>

float corteMediano(float hBase, float hTeto, int* tira, long int A, long int N, long int areaTotal);

int main(int argc, char* argv[]){

  long int i; //Contador
  long int A, N, areaTotal;
  int* tira = NULL;
  int maiorTira = 0;
  float resultado, maiorTiraF;

  //Execucao
  scanf("%li %li\n", &N, &A);
  while((A!=0) && (N!=0)) //*************************
  {
    //Inicializacoes
    areaTotal = 0;
    tira = (int*) malloc(N*sizeof(int));

    //Le e insere as tiras
    for(i=0; i<(N-1); i++)
    {
      scanf("%d ",&tira[i]);
      if(tira[i] > maiorTira)
      {
        maiorTira = tira[i];
      }
      areaTotal = areaTotal + ((long int) tira[i]);
    }
    scanf("%d\n",&tira[i]);
    if(tira[i] > maiorTira)
    {
      maiorTira = tira[i];
    }
    areaTotal = areaTotal + ((long int) tira[i]);

    if(A > areaTotal) //Caso a area pedida seja maior do que a area total
    {
      printf("-.-\n");
    }
    else
    {
      if(A == areaTotal) //Se a area pedida for igual a area total
      {
        printf(":D\n");
      }
      else // Se A for < areaTotal: vai ter corte
      {
        //opcional: ordena as tiras decrescente? *************************
        //testar se melhora ou piora o time

        maiorTiraF = (float) maiorTira;
        resultado = corteMediano(0.0000, maiorTiraF, tira, A, N, areaTotal);
        printf("%.4f\n", resultado); //**************************
        
      }
    }

    //Proximo caso de teste
    free(tira);
    scanf("%li %li\n", &N, &A);;
  }

  return 0;
}

//Funcao recursiva de corte
//Retorna na ultima entrada a altura que gera o valor certo
float corteMediano(float hBase, float hTeto, int* tira, long int A, long int N, long int areaTotal)
{
  float H, areaSuperiorCorte, areaInferiorCorte, tiraF, Af;
  long int i;

  //Calcula H
  Af = (float) A;
  H = ((hBase + hTeto) / ((float) 2));
  areaSuperiorCorte = (float) 0.0;

  //Calcula a area *superior* resultante desse H
  for(i=0; i<N; i++)
  {
    tiraF = (float) tira[i];
    if(tiraF > H)
    {
      areaSuperiorCorte = areaSuperiorCorte + (tiraF-H);
    }
  }
  //Calcula a area *inferior* resultante desse corte
  areaInferiorCorte = areaTotal - areaSuperiorCorte;

  //Se ao cortar encontrei exatamente a area que queria
  if((areaSuperiorCorte == Af) || (areaInferiorCorte == Af))
  {
    return H;
  }
  else //Caso cortei mas não encontrei a area que queria, eh maior ou menor do que ela
  {
    //Depois adicionar uma condicao de parada**************************************************8
    //exemplo:
    /*2
    if( (hTeto - hBase) < 0.0001 ) //Se esta na hora de parar de iterar
    {
      return H;
    }
    else
    {
    2.meio*/

      if(areaSuperiorCorte > Af) //Caso a area acima eh maior do que eu preciso
      {
        //Aumenta o valor de H para diminuir a area acima do corte
        return (corteMediano(H, hTeto, tira, A, N, areaTotal));
      }
      else //Caso a area acima eh menor do que eu preciso
      {
        //Desce o valor de H para a area Superior ao corte aumentar
        return( corteMediano(hBase, H, tira, A, N, areaTotal) );
      }

    //2}

  }
}
