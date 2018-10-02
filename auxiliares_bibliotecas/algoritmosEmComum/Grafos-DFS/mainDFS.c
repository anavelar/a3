#include <stdlib.h>
#include <stdio.h>

// ------------------------------------------------------------------
// AO FINAL ********************************8888888888888888 AQUI
// TIRAR OS PRINTFS!!!
// ------------------------------------------------------------------

// POSSIVEIS PAUS

// OBS.:
// 1) Melhorias possiveis:
// a) Funcao insere aresta mais generica, vertice eh um int nela.
// b) Ordenar os vertices na lista de adjacencia para melhorar buscas

// ---------------------------------------------------------------------------
//--------------------------------- ESTRUTURAS DE DADOS
//-- LISTAS ENCADEADAS
typedef struct tipoCelulah* apontador;
typedef struct{
  int chave;
} tipoNo;
typedef struct tipoCelulah{
  tipoNo no;
  apontador prox;
} tipoCelula;
typedef struct {
  apontador inicio;
  apontador fim;
} tipoLista;
//-- GRAFOS
typedef tipoLista* tipoGrafo;


// ---------------------------------ASSINATURAS DAS FUNCOES
//-- LISTAS ENCADEADAS
void ImprimeNo(tipoNo no);
void InicializaNoSentinela(tipoNo* eNo);
void CriaListaVazia(tipoLista* eLista);
int EstaVazia(tipoLista lista);
void Insere(tipoLista* eLista, tipoNo noNovo);
//void Remove(tipoLista* eLista);
void ImprimeLista (tipoLista lista);
//-- GRAFOS
void InicializaGrafoSemArestas(tipoGrafo* eGrafo, int numVertices);
void InsereAresta(tipoGrafo* eGrafo, int verticeOrigem, int verticeDestino);

//---------------------------------PROGRAMA
int main(){

  //Cria as variáveis principais do main
  tipoGrafo Grafo = NULL;
  int vertices = 7;

  //Monta a Estrutura de Dados para representar o Grafo lido
  //Cria o Grafo vazio (com o numero de vertices lido)
  InicializaGrafoSemArestas(&Grafo, vertices);
  //Insere as arestas dele
  //InsereAresta(tipoGrafo* eGrafo, int verticeOrigem, int verticeDestino)
  //Exemplo para uma aresta 1->2
  //InsereAresta(&Grafo, 1, 2);
  InsereAresta(&Grafo, 1, 2);
  InsereAresta(&Grafo, 1, 4);
  InsereAresta(&Grafo, 4, 2);
  InsereAresta(&Grafo, 2, 3);
  InsereAresta(&Grafo, 3, 4);
  InsereAresta(&Grafo, 5, 3);
  InsereAresta(&Grafo, 5, 6);

  //teste
  int a;
  for(a=0; a<vertices; a++)
  {
    printf("Lista do vertice %d:\n", a);
    ImprimeLista(Grafo[a]);
    printf("\n");
  }

  //Faz a varredura do Grafo com o DFS

  return 0;
}

// ---------------------------------FUNCOES
//-- LISTAS ENCADEADAS
void ImprimeNo(tipoNo no) //varia com o no
{
  printf("No: %d ", no.chave);
}

void InicializaNoSentinela(tipoNo* eNo) //varia com o no
{
  eNo->chave = -1;
}

void CriaListaVazia(tipoLista* eLista)
{
  eLista->inicio = (apontador) malloc(sizeof(tipoCelula));
  eLista->inicio->prox = NULL;
  eLista->fim = eLista->inicio;
  InicializaNoSentinela(&(eLista->inicio->no));
  //printf("Lista vazia criada.\n");
}

int EstaVazia(tipoLista lista)
{
  return (lista.inicio == lista.fim);
}

void Insere(tipoLista* eLista, tipoNo noNovo)
{
  eLista->fim->prox = (apontador) malloc(sizeof(tipoCelula));
  eLista->fim = eLista->fim->prox; //**************AQUI TVZ MAS NIVIO TB EH ASSIM
  eLista->fim->prox = NULL;
  eLista->fim->no = noNovo;
}
/*
void Remove(tipoLista* eLista)
{

}
*/

void ImprimeLista (tipoLista lista)
{
  apontador aux = lista.inicio->prox;

  if(EstaVazia(lista))
  {
    printf("A lista esta vazia.\n");
  }
  else{

    while(aux != NULL)
    {
      ImprimeNo(aux->no);
      aux = aux->prox;
    }
  }
}

//-- GRAFOS
//Cria um Grafo vazio com n vertices mas sem arestas
//Precisa inserir as arestas ainda
void InicializaGrafoSemArestas(tipoGrafo* eGrafo, int numVertices)
{
  int i;

  (*(eGrafo)) = (tipoLista*) malloc(numVertices*sizeof(tipoLista));

  //Inicializa cada uma dessas listas
  for(i=0; i<numVertices; i++)
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
