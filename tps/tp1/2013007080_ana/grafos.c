#include "grafos.h"

//Cria um Grafo vazio com n vertices mas sem arestas
//Precisa inserir as arestas ainda
void InicializaGrafoSemArestas(tipoGrafo* eGrafo, int numVertices)
{
  int i;

  (*(eGrafo)) = (tipoLista*) malloc((numVertices+1)*sizeof(tipoLista));

  //Inicializa cada uma dessas listas
  for(i=0; i<(numVertices+1); i++)
  {
    CriaListaVazia(&((*(eGrafo))[i]));
  }

}

//Insere aresta direcionada: verticeOrigem -> verticeDestino
void InsereAresta(tipoGrafo* eGrafo, int verticeOrigem, int verticeDestino)
{
  // Cria Noh que vai ser inserido na nova celula na lista de adj de um vertice
  tipoNo vizinho;
  vizinho.chave = verticeDestino;

  //Insere esse vizinho no vertice de Origem
  Insere(&((*(eGrafo))[verticeOrigem]), vizinho);

}

//DFS
int VisitaDFS(char* ramo, int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
{
  apontador aux = NULL;
  int corAux = INICIALIZACAO;
  char verticeConvertido[] = "padrao";
  sprintf(verticeConvertido, "%d", vertice);
  //teste - printf("vertice convertido eh %s, de comprimento %d.\n", verticeConvertido, strlen(verticeConvertido));
  strcat(ramo, verticeConvertido);

  ((*(eCor))[vertice]) = CINZA;
  (*(eTempo)) = (*(eTempo)) + 1;
  (*(eD))[vertice] = (*(eTempo));

  if(!EstaVazia((*eGrafo)[vertice])) //Caso o vertice tenha vizinhos / adjacentes
  {
    aux = ((*eGrafo)[vertice]).inicio->prox; //1o elemento da lista: 1o vertice adjacente
    while(aux != NULL)
    {
      if((*eCor)[aux->no.chave] == BRANCO)
      {
        (*eAntecessor)[aux->no.chave] = vertice;
        corAux = VisitaDFS(ramo, aux->no.chave, eGrafo, eCor, eAntecessor, eTempo, eD, eF);
        //corAux = VisitaDFS(ramo, aux->no.chave, eGrafo, eCor, eAntecessor, eTempo, eD, eF);
        if (corAux == DIFERENTE)
        {
          return DIFERENTE;
        }
      }
      else
      {
        if((*eCor)[aux->no.chave] == CINZA) //tem aresta de retorno: tem ciclo nesse demonio
        {
          printf("0 -1\n");
          return DIFERENTE;
        }
      }

      aux = aux->prox;
    }
  }

  ((*eCor)[vertice]) = PRETO;
  (*(eTempo)) = (*(eTempo)) + 1;
  ((*eF)[vertice]) = (*(eTempo));

  if( ((*eF)[vertice]) == (((*eD)[vertice])+1) )
  {
    printf("%s\n", ramo);
  }

  ramo[strlen(ramo)-strlen(verticeConvertido)] = '\0'; //marretada do capetaaaaaaaaaaaaaaaaaaaa
  return NORMAL;

}
