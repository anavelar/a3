#include "pd.h"

//Funcoes

int InicializaPrograma(int argc, char** argv, FILE** epArqEntrada, FILE** epArqSaida){

  if(argc != 3) //Se os parametros na linha de comando nao esao presentes
  {
    printf("\nERRO. Faltam parametros para a execucao do programa,");
    printf("falta especificar o arquivo de entrada, de saida ou o executavel.\n");
    printf("\nNao foi possivel executar o programa.\n\n");
    return 0;
  }
  else //Se o pedido de execucao foi ok com relacao a quantidade
  {
    *(epArqEntrada) = fopen(argv[1],"r");
    *(epArqSaida) = fopen(argv[2],"w");

    if( *(epArqEntrada) == NULL) //Se houve erro ao abrir os arquivos
    {
      printf("\nNao foi possivel encontrar o arquivo de entrada.\n");
      printf("\nNao foi possivel executar o programa.\n\n");
      fclose(*(epArqSaida));
      return 0;
    }
    else //Se nao houve erro na abertura de arquivos
    {
      return 1;
    }
  }

}

void LeDadosInstancia(FILE** epArqEntrada, int* eS, int* eV, int* eX, long int* eM, int** esequencia){

  int j; //Contador

  fscanf(*(epArqEntrada), "%d %d ", eS, eV);
  fscanf(*(epArqEntrada), "%d %li\n", eX, eM);

  *(esequencia) = (int*) malloc((*(eS))*(sizeof(int)));

  for(j=0; j < ((*eS)-1); j++)
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

  //teste
  (*eno).cor = 0;
  //fimteste
}

void InicializaArvore(apontador* earvore, int V, long int* eValorMax){

  int indiceAserPassado = -1;
  long int valorAserPassado = (long int) V;

  //Inicializacoes para cada caso
  (*eValorMax) = -1;

  //Cria arvore, insere o primeiro no e inicializa o no.
  (*earvore) = (apontador) malloc(sizeof(tipoNo));

  InicializaNo((*earvore), valorAserPassado, indiceAserPassado);
}

tipoNo* VisitaNo(tipoNo* eno, int* sequencia, int X, int S, long int* evalorMax, int* eac){

  long int valorNovo;
  long int sequenciaS = (long int) (sequencia[(*eno).indices]);
  long int limiteX = (long int) (X);
  long int limiteZero = 0;
  tipoNo* libera;

  //teste
  if( (*eno).cor == 1 )
  {
    printf("Voltei num no fechado.\n");
    return eno;
  } //fimteste
  else
  {
    //debigando
    (*eac)++;
    //printf("Entrou no No %li nivel %d.\n", (*eno).valor, (*eno).indices);

    //Checa se estou num no folha
    //Isto e: valor final, nao tem mais ninguem para adicionar da sequencia
    if( (*eno).indices == S )
    {
      if((*eno).valor > (*evalorMax))
      {
        (*evalorMax) = (*eno).valor;
      }

      //teste
      //printf("%d: Fundo: valor %li - valor max: %li.\n", (*eno).indices, (*eno).valor, (*evalorMax));
      //fimteste

      return eno;
    }
    else //Se estou em um no normal, nao folha
    {
      //Adiciona os filhos dele se ele tiver

      //Soma a sequencia a esse no
      valorNovo =  (*eno).valor + sequenciaS;
      //teste
      //printf("Valor da sequencia: s[%d]:%li.\n", (*eno).indices, sequenciaS);
      //fimteste
      if((valorNovo <= limiteX) && (valorNovo >= limiteZero))
      {
        (*eno).filhoAdd = (apontador) malloc(sizeof(tipoNo));
        InicializaNo(((*eno).filhoAdd), valorNovo, (*eno).indices);
        libera = VisitaNo(((*eno).filhoAdd), sequencia, X, S, evalorMax, eac);
        free(libera);
        (*eno).filhoAdd = NULL;
      }
      else //teste
      {
        //printf("%d: Abortou ramo por valor %li.\n", (*eno).indices, valorNovo);
      } //fim teste
      //else //Estourou

      //Subtrai a sequencia a esse no
      valorNovo = (*eno).valor - sequenciaS;
      //teste
      //printf("Valor da sequencia: s[%d]:%li.\n", (*eno).indices, sequenciaS);
      //fimteste
      if((valorNovo >= limiteZero) && (valorNovo <= limiteX))
      {
        (*eno).filhoSub = (apontador) malloc(sizeof(tipoNo));
        InicializaNo(((*eno).filhoSub), valorNovo, (*eno).indices);
        libera = VisitaNo(((*eno).filhoSub), sequencia, X, S, evalorMax, eac);
        free(libera);
        (*eno).filhoSub = NULL;
      }
      else //teste
      {
        //printf("%d: Abortou ramo por valor %li.\n", (*eno).indices, valorNovo);
      } //fim teste
      //else //Estourou

      //teste
      //printf("No %li nivel %d.\n", (*eno).valor, (*eno).indices);

      //teste
      (*eno).cor = 1;
      //fimteste
      return eno;
    }
  }
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

void ReiniciaParaProxCaso(int** esequencia, tipoNo** earvore, int* eac){
  (*eac) = 0;
  free(*earvore);
  (*earvore) = NULL;
  free(*esequencia);
  (*esequencia) = NULL;
}

void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida){
  fclose(*(epArqEntrada));
  fclose(*(epArqSaida));
}
