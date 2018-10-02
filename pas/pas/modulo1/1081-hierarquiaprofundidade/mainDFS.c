#include <stdlib.h>
#include <stdio.h>
#define BRANCO 1
#define CINZA 2
#define PRETO 3

// ------------------------------------------------------------------
// AO FINAL ********************************8888888888888888 AQUI
// TIRAR OS PRINTFS!!!
// ------------------------------------------------------------------

// POSSIVEIS PAUS
// 0 - nao esta desalocando memoria do grafo, so apontando p null: possivel pau
// de execucao.
// 0.2 - limpeza de variaveis e de tudo para o proximo caso
// 1-Funcao VisitaDFS, variavel tempo no inicio e d(vertice) = tempo tb.

// OBS.:
// 1) Melhorias possiveis:
// 0) Funcao para desalocar memoria do grafo: nao estou desalocando porque
// teria que esvazias as listas também, etc
// a) Funcao insere aresta mais generica, vertice eh um int nela.
// b) Ordenar os vertices na lista de adjacencia para melhorar buscas
// c) ao inves de vetores para o DFS, incluir esses campos no grafo e
// ver se compensa mesmo se eh otimizacao.

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
//-- DFS
void VisitaDFS(int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF);

//---------------------------------PROGRAMA
int main(){

  int j, k;
  int numCasos = 0;

  tipoGrafo Grafo = NULL;
  int numVertices = 0;
  int numArestas = 0;
  int vOrigem, vDestino;

  int* cor = NULL;
  int* antecessor = NULL;
  int tempo = 0;
  int* d = NULL;
  int* f = NULL;

  //Le num casos
  scanf("%d\n", &numCasos);
  //Para cada caso:
  for(j=0; j<numCasos; j++)
  {
    //Le como sera grafo
    scanf("%d %d\n", &numVertices, &numArestas);

    //Cria o Grafo como matriz Adjacencias
    InicializaGrafoSemArestas(&Grafo, numVertices);

    //Insere as arestas nele
    for(k=0; k<numArestas; k++)
    {
      scanf("%d %d\n", &vOrigem, &vDestino);
      InsereAresta(&Grafo, vOrigem, vDestino);
    }

    //Faz busca em profundidade nele
    //Prepara o Grafo para o DFS
    cor = (int*) malloc(numVertices*(sizeof(int)));
    antecessor = (int*) malloc(numVertices*(sizeof(int)));
    d = (int*) malloc(numVertices*(sizeof(int)));
    f = (int*) malloc(numVertices*(sizeof(int)));
    tempo = 0;
    for(k=0; k<numVertices; k++)
    {
      cor[k] = BRANCO;
      antecessor[k] = -1;
      d[k] = -1;
      f[k] = -1;
    }

    //No Grafo
    for(k=0; k<numVertices; k++)
    {
      if(cor[k] == BRANCO)
      {
        VisitaDFS(k, &Grafo, &cor, &antecessor, &tempo, &d, &f);
        //void VisitaDFS(int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
        //VisitaDFS(vertice k)
      }
    }

    //Depois: ver para inserir o pathR, impressao "caso n" e tirar alguma
    // impressao se tiver e colocar \n, tambem checar os casos na mão

    //Ao fim: destrói o grafo para o proximo caso de teste com outro grafo
    //e reinicia tudo que precisaria estar reiniciado/novo para um novo caso
    free(cor);
    free(antecessor);
    free(d);
    free(f);
    Grafo = NULL; // OU free(Grafo); nao vai desalocar tudo mas ja ajuda sera?

  }

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

// retorna 1 se esta vazia, 0 se nao esta vazia.
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

//-- DFS
void VisitaDFS(int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
{
  apontador aux = NULL;

  ((*(eCor))[vertice]) = CINZA;
  (*(eTempo)) = (*(eTempo)) + 1; //*********************************************
  (*(eD))[vertice] = (*(eTempo)); //*********************************************

  if(!EstaVazia((*eGrafo)[vertice]) //Caso o vertice tenha vizinhos / adjacentes
  {
    aux = ((*eGrafo)[vertice]).inicio->prox; //1o elemento da lista: 1o vertice adjacente
    while(aux != NULL)
    {
      if((*eCor)[aux->no.chave] == BRANCO)
      {
        (*eAntecessor)[aux->no.chave] = vertice;
        VisitaDFS(aux->no.chave, eGrafo, eCor, eAntecessor, eTempo, eD, eF);
      }

      aux = aux->prox;
    }
  }
  //int EstaVazia(tipoLista lista)
  // retorna 1 se esta vazia, 0 se nao esta vazia.
  //lista de adjacencia do vertice
  //(*(eGrafo))[vertice]

  ((*eCor)[vertice]) = PRETO;
  (*(eTempo)) = (*(eTempo)) + 1;
  ((*eF)[vertice]) = (*(eTempo));

}
