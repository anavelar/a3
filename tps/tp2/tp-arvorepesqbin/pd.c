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

void InicializaNo(tipoNo* eno, long int valor, int indicesPai){

  (*eno).valor = valor;
  (*eno).indices =  (indicesPai + 1);

  (*eno).filhoSub = NULL;
  (*eno).filhoAdd = NULL;
}

void InicializaArvore(apontador* earvore, int V, long int* eValorMax){

  //Inicializacoes para cada caso
  (*eValorMax) = -1;

  //Cria arvore, insere o primeiro no e inicializa o no.
  (*earvore) = (apontador) malloc(sizeof(tipoNo));

  InicializaNo((*earvore), V, (-1));
}

void VisitaNo(tipoNo* eno, int* sequencia, int X, int S, long int* evalorMax){

  long int valorNovo;

  //Checa se estou num no folha
  //----------------------------
  if( (*eno).indices == S )
  {
    if((*eno).valor > (*evalorMax))
    {
      (*evalorMax) = (*eno).valor;
    }

    return;
  }

  //Adiciona os filhos dele se ele tiver
  //------------------------------------

  //Soma a sequencia a esse no
  valorNovo =  (*eno).valor + sequencia[(*eno).indices];
  if( valorNovo <= X)
  {
    (*eno).filhoAdd = (apontador) malloc(sizeof(tipoNo));
    InicializaNo(((*eno).filhoAdd), valorNovo, (*eno).indices);

    VisitaNo(((*eno).filhoAdd), sequencia, X, S, evalorMax);
  }
  //else //Estourou

  //Subtrai a sequencia a esse no
  valorNovo = (*eno).valor - sequencia[(*eno).indices];
  if(valorNovo >= 0)
  {
    (*eno).filhoSub = (apontador) malloc(sizeof(tipoNo));
    InicializaNo(((*eno).filhoSub), valorNovo, (*eno).indices);
    VisitaNo(((*eno).filhoSub), sequencia, X, S, evalorMax);
  }
  //else //Estourou

}

void ImprimeResultado(long int valorMax, FILE** epArqSaida, long int M){

  if(valorMax == -1)
  {
    fprintf((*epArqSaida), "N,-1\n");
  }
  else
  {
    if(valorMax >= M)
    {
      fprintf((*epArqSaida), "S,%li\n", valorMax);
    }
    else
    {
      fprintf((*epArqSaida), "N,%li\n", valorMax);
    }
  }

}

void ReiniciaParaProxCaso(int** esequencia){

  free(*esequencia);
  
}

void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida){
  fclose(*(epArqEntrada));
  fclose(*(epArqSaida));
}
