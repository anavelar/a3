#include <stdlib.h>
#include <stdio.h>

//--------------------------------- ESTRUTURAS DE DADOS
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

// ---------------------------------ASSINATURAS DAS FUNCOES
void ImprimeNo(tipoNo no);
void InicializaNoSentinela(tipoNo* eNo);
void CriaListaVazia(tipoLista* eLista);
int EstaVazia(tipoLista lista);
void Insere(tipoLista* eLista, tipoNo noNovo);
//void Remove(tipoLista* eLista);
void ImprimeLista (tipoLista lista);

int main(){

  tipoLista ListaNotas;
  CriaListaVazia(&ListaNotas);
  ImprimeLista(ListaNotas);
  printf("\n");

  tipoNo prim, seg, ter;
  prim.chave = 1;
  seg.chave = 2;
  ter.chave = 3;
  Insere(&ListaNotas, prim);
  ImprimeLista(ListaNotas);
  printf("\n");

  Insere(&ListaNotas, seg);
  ImprimeLista(ListaNotas);
  printf("\n");

  Insere(&ListaNotas, ter);
  ImprimeLista(ListaNotas);
  printf("\n");

  return 0;
}

// Aqui no biblioteca.c : colocar as funcoes implementadas
void ImprimeNo(tipoNo no) //varia com o no
{
  printf("No: %d.\n", no.chave);
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

int EstaVazia(tipoLista lista)
{
  return (lista.inicio == lista.fim);
}

void Insere(tipoLista* eLista, tipoNo noNovo)
{
  eLista->fim->prox = (apontador) malloc(sizeof(tipoCelula));
  eLista->fim = eLista->fim->prox;
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
