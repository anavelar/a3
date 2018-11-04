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

//sequencia esta sendo passado por referencia
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

//vetores passados por referencia
//v e x por valor nao esquecer
void InicializaPD(long int* pd, int* es, int* sequencia, int V, int X){

  int numCasos; //temp

  *(es) = 1;
  numCasos = (int) pow(((double) 2), ((double) (*(es))));
  pd = (long int*) malloc(numCasos*(sizeof(long int)));

  //Preenche primeiro campo
  if( (V + sequencia[(*es)-1]) <= X ) //Se esta nos limites
  {
    pd[0] = V + sequencia[(*es)-1];
  }
  else // Se estourou
  {
    pd[0] = -1;
  }

  //Preenche segundo campo
  if( (V - sequencia[(*es)-1]) >= 0) //Se esta nos limites
  {
    pd[1] = V - sequencia[(*es)-1];
  }
  else
  {
    pd[1] = -1;
  }
}

void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida){
  fclose(*(epArqEntrada));
  fclose(*(epArqSaida));
}
