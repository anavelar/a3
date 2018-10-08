#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INVALIDO -1
#define BRANCO 1
#define CINZA 2
#define PRETO 3

#define INICIALIZACAO -1
#define NORMAL 1
#define DIFERENTE 0

#define VALORENORME 1000


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
int VisitaDFS(int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF);

//---------------------------------PROGRAMA
int main(){

  int j, k;

  tipoGrafo Grafo = NULL;
  int numVertices = 0;
  int numArestas = 0;
  int vOrigem, vDestino;

  int* cor = NULL;
  int* antecessor = NULL;
  int tempo = 0;
  int* d = NULL;
  int* f = NULL;
  int* setasEntrando = NULL;
  tipoLista verticesRaiz;
  tipoNo noAux;
  apontador aux = NULL;
  int indicaCiclo = NORMAL; //Se tiver ciclo, ela vira o valor DIFERENTE (ZERO)

  //Inicializacoes
  noAux.chave = INVALIDO;
  CriaListaVazia(&verticesRaiz);

  //Para cada caso:
  //Le como sera grafo
  scanf("%d %d\n", &numVertices, &numArestas);

  //Cria o Grafo como matriz Adjacencias
  InicializaGrafoSemArestas(&Grafo, numVertices);

  //Inicializa o vetor para achar, ao inserir as arestas, os vertices
  //raiz do DFS
  setasEntrando = (int*) malloc((numVertices+1)*(sizeof(int)));
  //Inicializa a sentinela
  setasEntrando[0] = VALORENORME;
  for(k=1; k<(numVertices+1); k++)
  {
    setasEntrando[k] = 0;
  }

  //Insere as arestas nele
  for(k=0; k<numArestas; k++)
  {
    scanf("%d %d\n", &vOrigem, &vDestino);
    InsereAresta(&Grafo, vOrigem, vDestino);
    setasEntrando[vDestino]++;
  }

  //Procura vertices raizes do DFS e os separa dos outros
  for(k=1; k<(numVertices+1); k++)
  {
    if(setasEntrando[k] == 0)
    {
      noAux.chave = k;
      Insere(&verticesRaiz, noAux);
    }
  }

  //Faz busca em profundidade nele
  //Prepara o Grafo para o DFS
  cor = (int*) malloc((numVertices+1)*(sizeof(int)));
  antecessor = (int*) malloc((numVertices+1)*(sizeof(int)));
  d = (int*) malloc((numVertices+1)*(sizeof(int)));
  f = (int*) malloc((numVertices+1)*(sizeof(int)));
  tempo = 0;

  //Incializa a sentinela:
  cor[k] = INVALIDO;
  antecessor[k] = INICIALIZACAO;
  d[k] = INICIALIZACAO;
  f[k] = INICIALIZACAO;

  //Inicializa os outros
  for(k=1; k<numVertices+1; k++)
  {
    cor[k] = BRANCO;
    antecessor[k] = INICIALIZACAO;
    d[k] = INICIALIZACAO;
    f[k] = INICIALIZACAO;
  }

  if(EstaVazia(verticesRaiz)) //Se não há vertices raiz
  {
    printf("Erro, nao ha vertices raiz.\n");
    return 0;
  }
  else //Se ha vertices raiz possiveis
  {
    aux = verticesRaiz.inicio->prox; //endereco da primeira celula raiz possivel
  }

  //aqui*************************************************************
  //SE RETORNAR DIFERENTE PRECISA PARAR A BUSCA: CHECAR O VALOR DE VISITADFS RETORNADO

  //Percorre a lista de vertices raiz possiveis: DFS com os verticesRaiz so
  //Cada arvore da floresta que eh essa arvores
  while(aux != NULL)
  {
    indicaCiclo = VisitaDFS(aux->no.chave, &Grafo, &cor, &antecessor, &tempo, &d, &f);
    //int VisitaDFS(int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
    //VisitaDFS(vertice k)

    if(!indicaCiclo) //Se tem ciclo
    {
      return 0;
    }
    else
    {
      aux = aux->prox;
    }

  }

  //No final: Desalocar memoria
  //free(cor);
  //free(antecessor);
  //free(d);
  //free(f);
  //free(setasEntrando);
  //Grafo = NULL; // OU free(Grafo); nao vai desalocar tudo mas ja ajuda sera?**** desalocar

  // Desalocar/limpar verticesRaiz

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
}

// retorna 1 se esta vazia, 0 se nao esta vazia.
int EstaVazia(tipoLista lista)
{
  return (lista.inicio == lista.fim);
}

void Insere(tipoLista* eLista, tipoNo noNovo)
{
  apontador apontadorAnterior = eLista->inicio; //aponta para a sentinela
  apontador apontadorProxima = eLista->inicio->prox; //aponta para a logo depois da sentinela

  if(EstaVazia(*eLista)) //Se a lista estiver vazia
  {
    eLista->fim->prox = (apontador) malloc(sizeof(tipoCelula));
    eLista->fim = eLista->fim->prox; //**************AQUI TVZ MAS NIVIO TB EH ASSIM
    eLista->fim->prox = NULL;
    eLista->fim->no = noNovo;
  }
  else //se vai inserirOrdenado
  {
    //Encontra a posicao de insercao
    while( (noNovo.chave > apontadorProxima->no.chave)  ) //&& (apontadorProxima->prox != NULL)
    {
      if(apontadorProxima->prox == NULL)
      {
          //Insere normal
          eLista->fim->prox = (apontador) malloc(sizeof(tipoCelula));
          eLista->fim = eLista->fim->prox; //**************AQUI TVZ MAS NIVIO TB EH ASSIM
          eLista->fim->prox = NULL;
          eLista->fim->no = noNovo;

          return; //----Testar break
      }

      apontadorAnterior = apontadorAnterior->prox;
      apontadorProxima = apontadorProxima->prox;
    }

    apontadorAnterior->prox = (apontador) malloc(sizeof(tipoCelula));
    apontadorAnterior->prox->prox = apontadorProxima;
    apontadorAnterior->prox->no = noNovo;
  }
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

//-- DFS
int VisitaDFS(int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF)
{
  apontador aux = NULL;
  int corAux = INICIALIZACAO;

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
        corAux = VisitaDFS(aux->no.chave, eGrafo, eCor, eAntecessor, eTempo, eD, eF);
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

  return NORMAL;

}
