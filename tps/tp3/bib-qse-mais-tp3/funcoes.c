#include "funcoes.h"

//Funcoes
int InicializaPrograma(int argc, char** argv, FILE** epArqEntrada, FILE** epArqSaida, float* elimiteMB, int* etamArea){

  if(argc != NUM_PARAMETROS) //Se os parametros na linha de comando nao esao presentes
  {
    printf("\nERRO. Faltam parametros para a execucao do programa,");
    printf("falta especificar o arquivo de entrada, de saida, o executavel ou o limite em MB.\n");
    printf("\nNao foi possivel executar o programa.\n\n");

    return ERRO;
  }
  else //Se o pedido de execucao foi ok com relacao a quantidade
  {
    (*epArqEntrada) = fopen(argv[1],"r");
    (*epArqSaida) = fopen(argv[2],"w");
    (*elimiteMB) = ((float) atof(argv[3]));
    (*etamArea) = ((int) (*elimiteMB));

    if( *(epArqEntrada) == NULL) //Se houve erro ao abrir os arquivos
    {
      printf("\nNao foi possivel encontrar o arquivo de entrada.\n");
      printf("\nNao foi possivel executar o programa.\n\n");
      fclose(*(epArqSaida));
      return ERRO;
    }
    else //Se nao houve erro na abertura de arquivos de leitura
      return NORMAL;
  }
}

void LeInfoMatriz(FILE** epArqEntrada, int* enumLinhas, int* enumColunas)
{
  fscanf((*epArqEntrada),"%d %d\n", enumLinhas, enumColunas);
}

int LeLinhaMatriz(FILE** epArqEntrada, FILE** epArqSaida, FILE** eArqLi, int numColunas, float* emediaGeral, int linha, int numLinhas, int tamArea)
{
  long long int valor;
  float mediaLinha = 0.00f;
  int i; //Contador
  FILE *ArqLEs, *ArqEi;
  TipoRegistro R;
  long long int medianaInferior, medianaSuperior;
  int indiceMedianaInferior, indiceMedianaSuperior;
  float mediana;

  // Arquivo auxiliar para calculo da mediana por linha
  (*eArqLi) = fopen ("auxlinha.dat", "wb");

  //Le cada elemento da linha
  for(i=0; i<(numColunas-1); i++)
  {
    fscanf((*epArqEntrada),"%lli ", &valor);
    mediaLinha += ((float) valor);
    (*emediaGeral) += ((float) valor);
    R.Chave = valor;
    fwrite(&R, sizeof(TipoRegistro), 1, (*eArqLi));
  }
  fscanf((*epArqEntrada),"%lli\n", &valor);
  mediaLinha += ((float) valor);
  (*emediaGeral) += ((float) valor);
  R.Chave = valor;
  fwrite(&R, sizeof(TipoRegistro), 1, (*eArqLi));
  fclose(*eArqLi);

  //Calcula a media da linha
  mediaLinha /= ((float) numColunas);

  //Calcula a mediana da linha: Ordena a linha
  (*eArqLi) = fopen ("auxlinha.dat", "r+b");
  ArqEi = fopen ("auxlinha.dat", "r+b");
  ArqLEs = fopen ("auxlinha.dat", "r+b");
  if( ((*eArqLi) == NULL) || ArqEi == NULL || ArqLEs == NULL )
  {
    printf("Foram encontrados problemas ao manipular o arquivo ");
    printf("auxiliar do QuickSort Externo, logo foi abortado o programa.\n");
    fclose(*epArqEntrada); fclose(*epArqSaida);
    fclose(*eArqLi); fclose(ArqEi); fclose(ArqLEs);
    return ERRO;
  }

  QuicksortExterno(eArqLi, &ArqEi, &ArqLEs, INICIO, numColunas, tamArea);
  fflush(*eArqLi);
  fclose(ArqEi); fclose(ArqLEs);
  fseek((*eArqLi), 0, SEEK_SET);

  //Calcula a mediana da linha
  if(numColunas % 2)  //Se ha na linha um numero impar de elementos
  {
    indiceMedianaInferior = ((int) (numColunas / 2)) + 1;
    for(i=1; i<(numColunas+1); i++)
    {
      fread(&R, sizeof(TipoRegistro), 1, (*eArqLi));

      if(i==indiceMedianaInferior)
      {
        mediana = ((float) R.Chave);
        break;
      }
    }
  }
  else //Se ha na linha um numero par de elementos
  {
    indiceMedianaInferior = (numColunas / 2);
    indiceMedianaSuperior = indiceMedianaInferior + 1;

    for(i=1; i<(numColunas+1); i++)
    {
      fread(&R, sizeof(TipoRegistro), 1, (*eArqLi));

      if(i==indiceMedianaInferior)
      {
        medianaInferior = R.Chave;
      }
      else
      {
        if (i==indiceMedianaSuperior)
        {
          medianaSuperior = R.Chave;
          break;
        }
      }
    }

    mediana =  ((((float) medianaInferior) + ((float) medianaSuperior))/2.00f);
  }
  fclose(*eArqLi);

  //Imprime os resultados
  fprintf((*epArqSaida),"%.2f,%.2f\n", mediaLinha, mediana);
  if(linha == (numLinhas-1)) //Se esta na ultima linha
  {
    (*emediaGeral) /= ((float) (numColunas*numLinhas));
    fprintf((*epArqSaida),"%.2f\n", (*emediaGeral));
  }

  return NORMAL;
}

void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida)
{
  fclose(*(epArqEntrada));
  fclose(*(epArqSaida));
}
