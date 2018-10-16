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
int VisitaDFS(FILE** eponteiroArqSaida, int* verticesAPartirDaqui, int** vetorRamos, int* eNumRamos, int* tamanhoDesseRamo, int* ramoBusca, int* eTamanhoRamoBusca, int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
{
  int i; //contador
  apontador aux = NULL;
  int vd = 0;
  //Insere o vertice visitado aqui no ramo
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
        vd = VisitaDFS(eponteiroArqSaida, verticesAPartirDaqui, vetorRamos, eNumRamos, tamanhoDesseRamo, ramoBusca, eTamanhoRamoBusca, aux->no.chave, eGrafo, eCor, eAntecessor, eTempo, eD, eF);
        if (vd == DIFERENTE) //caso X=0
        {
          return DIFERENTE;
        }
        else
        {
          if((vd+1) > verticesAPartirDaqui[vertice])
          {
            verticesAPartirDaqui[vertice] = (vd+1);
          }
        }
      }
      else
      {
        if((*eCor)[aux->no.chave] == CINZA) //tem aresta de retorno: tem ciclo nesse demonio
        {
          fprintf((*eponteiroArqSaida),"0 -1\n");
          return DIFERENTE;
        }
        else
        {
          //Se o vizinho eh preto
          if((*eCor)[aux->no.chave] == PRETO)
          {
            if( (verticesAPartirDaqui[aux->no.chave]+1) > verticesAPartirDaqui[vertice] ) //***************************8PAU AQUI?
            {
              verticesAPartirDaqui[vertice] = (verticesAPartirDaqui[aux->no.chave] + 1);
            }
          }
        }
      }

      aux = aux->prox; //************
    }
  }

  ((*eCor)[vertice]) = PRETO;
  (*(eTempo)) = (*(eTempo)) + 1;
  ((*eF)[vertice]) = (*(eTempo));

  //Se esse vertice eh folha? NAO
  //Fim do ramo DE BUSCA.
  //Pode ser :
  //- fim do ramo pq prox preto
  //- fim do ramo com folha
  //- fim do ramo pq prox pretos ou cinzas - istoe - tem adj mas nao te prox branco
  if( ((*eF)[vertice]) == (((*eD)[vertice])+1) )
  {
    //Chegou ao fim do ramo de busca.
    //Insere o ramo no vetor de Ramos:
    vetorRamos[(*eNumRamos)] = (int*) malloc((*eTamanhoRamoBusca)*sizeof(int));
    tamanhoDesseRamo[(*eNumRamos)] = (*eTamanhoRamoBusca);
    for(i=0; i<(*eTamanhoRamoBusca); i++)
    {
      vetorRamos[(*eNumRamos)][i] = ramoBusca[i];
    }

    //Por ultimo de tudo!!:
    (*eNumRamos) = (*eNumRamos) + 1;

    //questao aqui tem o 4 do teste (prox pretos ou cinzas) *******************************************************8AQUI
    //Se esse no eh uma folha
    if(EstaVazia((*eGrafo)[vertice])) //Caso o vertice nao tenha vizinhos / adjacentes
    {
      verticesAPartirDaqui[vertice] = 1;
    }
  }

  //Remove esse vertice do ramo de busca
  (*eTamanhoRamoBusca) = (*eTamanhoRamoBusca) - 1;

  return verticesAPartirDaqui[vertice];
}
