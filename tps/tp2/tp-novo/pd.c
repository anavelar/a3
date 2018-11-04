#include "pd.h"

//Funcoes

int InicializaPrograma(int argc, char** argv, FILE** epArqEntrada, FILE** epArqSaida){

  if(argc != 3)
  {
    printf("\nERRO. Faltam parametros para a execucao do programa,");
    printf("falta especificar o arquivo de entrada, de saida ou o executavel.\n");
    printf("\nNao foi possivel executar o programa.\n\n");
    return 0;
  }

  *(epArqEntrada) = fopen(argv[1],"r");
  *(epArqSaida) = fopen(argv[2],"w");

  if( *(epArqEntrada) == NULL)
  {
    printf("\nNao foi possivel encontrar o arquivo de entrada.\n");
    printf("\nNao foi possivel executar o programa.\n\n");
    fclose(*(epArqSaida));
    return 0;
  }
}

void LeDadosInstancia(FILE** epArqEntrada, int* eS, int* eV, int* eX, long int* eM, int** esequencia){

  int j; //Contador

  fscanf(*(epArqEntrada), "%d %d ", eS, eV);
  fscanf(*(epArqEntrada), "%d %li\n", eX, eM);
  *(esequencia) = (int*) malloc((*(eS))*(sizeof(int)));

  for(j=0; j< ((*(eS))-1); j++)
  {
    fscanf(*(epArqEntrada), "%d ", &((*esequencia)[j]));
  }
  fscanf(*(epArqEntrada), "%d\n", &((*esequencia)[j]));
}

void InicializaPD(long int** epd, int* es, int* sequencia, int V, int X){

  *(es) = 1;
  *(epd) = (long int*) malloc(2*(sizeof(long int)));

  //Preenche primeiro campo
  if( (V + sequencia[0]) <= X ) //Se esta nos limites
  {
    (*epd)[0] = V + sequencia[0];
  }
  else // Se estourou
  {
    (*epd)[0] = -1;
  }

  //Preenche segundo campo
  if( (V - sequencia[0]) >= 0) //Se esta nos limites
  {
    (*epd)[1] = V - sequencia[0];
  }
  else
  {
    (*epd)[1] = -1;
  }

  //teste
  printf("s=%d: pd[0]=%li, pd[1]=%li.\n", (*es), (*epd)[0], (*epd)[1]);
  //fimteste

}

void PDdes(long int** epd, long int** epdAnterior, int* es, int X, int* sequencia){

  long long int k; //Contadores
  long long int numCasos, tampdAnterior;

  //Atualiza para o atual
  (*es)++;
  (*epdAnterior) = (*epd);
  numCasos = (int) pow(((double) 2), ((double) (*es)));
  (*epd) = (long int*) malloc(numCasos*sizeof(long int));
  tampdAnterior = (int) pow(((double) 2), ((double) ((*es)-1)));

  //Constroi pd
  for(k=0; k<tampdAnterior; k++)
  {
    //Para cada celula do vetor pdAnterior

    if( (*epdAnterior)[k] == -1 ) //Se eh um ramo estourado
    {
      (*epd)[(2*k)] = -1;
      (*epd)[(2*k)+1] = -1;
    }
    else //Se nao eh um ramo estourado
    {
      //Gera o valor da celula com a soma
      //Soma o valor da sequencia
      if( ( (*epdAnterior)[k] + sequencia[(*es)-1]) <= X ) //Se esta nos limites
      {
        (*epd)[(2*k)] = (*epdAnterior)[k] + sequencia[(*es)-1];
      }
      else // Se estourou
      {
        (*epd)[(2*k)] = -1;
      }

      //Gera o valor da celula com a subtracao
      //Subtrai o valor da sequencia
      if( ( (*epdAnterior)[k] - sequencia[(*es)-1] ) >= 0 ) //Se esta nos limites
      {
        (*epd)[(2*k)+1] = (*epdAnterior)[k] - sequencia[(*es)-1];
      }
      else
      {
        (*epd)[(2*k)+1] = -1;
      }
    }
  }

  //Desaloca
  free((*epdAnterior));

  //teste
  printf("s=%d: ", (*es));
  for(k=0; k<numCasos; k++)
  {
    printf("pd[%d]=%li, ", k, ((*epd)[k]));
  }
  printf("\n");
  //fimteste
}

void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida){
  fclose(*(epArqEntrada));
  fclose(*(epArqSaida));
}
