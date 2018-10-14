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
int VisitaDFS(FILE** eponteiroArqSaida, int** vetorRamos, int* eNumRamos, int* tamanhoDesseRamo, int* ramoBusca, int* eTamanhoRamoBusca, int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
{
  int i; //contador
  apontador aux = NULL;
  int corAux = INICIALIZACAO;
  //Insere o vertice visitado aqui no ramo
  //char verticeConvertido[] = "padraozao";
  //sprintf(verticeConvertido, "%d", vertice);
  //strcat(ramo, verticeConvertido);
  ramoBusca[(*eTamanhoRamoBusca)] = vertice;
  (*eTamanhoRamoBusca) = (*eTamanhoRamoBusca) + 1;

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
        //chamada de funcao aqui usando ramo, removi, olhar (soh olhar) nos commits anteriores.
        corAux = VisitaDFS(eponteiroArqSaida, vetorRamos, eNumRamos, tamanhoDesseRamo, ramoBusca, eTamanhoRamoBusca, aux->no.chave, eGrafo, eCor, eAntecessor, eTempo, eD, eF);
        if (corAux == DIFERENTE)
        {
          return DIFERENTE;
        }
      }
      else
      {
        if((*eCor)[aux->no.chave] == CINZA) //tem aresta de retorno: tem ciclo nesse demonio
        {
          fprintf((*eponteiroArqSaida),"0 -1\n");
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
    //Chegou ao fim do ramo de busca.
    //fprintf((*eponteiroArqSaida), "%s\n", ramo);

    //Insere o ramo no vetor de Ramos:
    vetorRamos[(*eNumRamos)] = (int*) malloc((*eTamanhoRamoBusca)*sizeof(int));
    tamanhoDesseRamo[(*eNumRamos)] = (*eTamanhoRamoBusca);
    for(i=0; i<(*eTamanhoRamoBusca); i++)
    {
      vetorRamos[(*eNumRamos)][i] = ramoBusca[i];
    }

    //Por ultimo de tudo!!:
    (*eNumRamos) = (*eNumRamos) + 1;
  }

  //Remove esse vertice do ramo de busca
  //ramo[strlen(ramo)-strlen(verticeConvertido)] = '\0'; //marretada do capetaaaaaaaaaaaaaaaaaaaa
  (*eTamanhoRamoBusca) = (*eTamanhoRamoBusca) - 1;
  return NORMAL;
}
