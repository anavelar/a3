#include "funcoes.h"

//Funcoes
int InicializaPrograma(int argc, char** argv, FILE** epArqEntrada, FILE** epArqSaida, float* elimiteMB){

  if(argc != NUM_PARAMETROS) //Se os parametros na linha de comando nao esao presentes
  {
    printf("\nERRO. Faltam parametros para a execucao do programa,");
    printf("falta especificar o arquivo de entrada, de saida, o executavel ou o limite em MB.\n");
    printf("\nNao foi possivel executar o programa.\n\n");

    return ERRO;
  }
  else //Se o pedido de execucao foi ok com relacao a quantidade
  {
    *(epArqEntrada) = fopen(argv[1],"r");
    *(epArqSaida) = fopen(argv[2],"w");
    *(elimiteMB) = ((float) atof(argv[3]));

    if( *(epArqEntrada) == NULL) //Se houve erro ao abrir os arquivos
    {
      printf("\nNao foi possivel encontrar o arquivo de entrada.\n");
      printf("\nNao foi possivel executar o programa.\n\n");
      fclose(*(epArqSaida));
      return ERRO;
    }
    else //Se nao houve erro na abertura de arquivos
      return NORMAL;

  }
}

void LeInfoMatriz(FILE** epArqEntrada, int* enumLinhas, int* enumColunas)
{
  fscanf((*epArqEntrada),"%d %d\n", enumLinhas, enumColunas);
}

void LeLinhaMatriz(FILE** epArqEntrada, FILE** epArqSaida, int numColunas, float* emediaGeral, int linha, int numLinhas)
{
  long long int valor;
  float mediaLinha = 0.00f;
  int i; //Contador

  //Le cada elemento da linha
  for(i=0; i<(numColunas-1); i++)
  {
    fscanf((*epArqEntrada),"%lli ", &valor);
    mediaLinha += ((float) valor);
    (*emediaGeral) += ((float) valor);
  }
  fscanf((*epArqEntrada),"%lli\n", &valor);
  mediaLinha += ((float) valor);
  (*emediaGeral) += ((float) valor);

  //Calcula a media da linha e adiciona a media geral
  mediaLinha /= ((float) numColunas);

  //Imprime os resultados
  fprintf((*epArqSaida),"%.2f,\n", mediaLinha);
  if(linha == (numLinhas-1)) //Se esta na ultima linha
  {
    (*emediaGeral) /= ((float) (numColunas*numLinhas));
    fprintf((*epArqSaida),"%.2f", (*emediaGeral));
  }
}

void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida)
{
  fclose(*(epArqEntrada));
  fclose(*(epArqSaida));
}
