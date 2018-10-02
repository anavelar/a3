#include <stdlib.h>
#include <stdio.h>
#include <listaEncadeada.h> // Para incluir as estruturas de dados de la
                            // e as assinaturas das funcoes

// Aqui no biblioteca.c : colocar as funcoes implementadas

void ImprimeNo(tipoNo no) //varia com o no
{
  printf("No: %d.\n", no.chave);
}

void InicializaNoSentinela(tipoNo* eNo) //varia com o no
{
  *(eNo).chave = VALORSENTINELA;
}

void CriaListaVazia(tipoLista* eLista)
{
  *(eLista).inicio = (apontador) malloc(sizeof(tipoCelula));
  *(eLista).inicio->prox = NULL;
  *(eLista).fim = *(eLista).inicio;
  InicializaNoSentinela(&(eLista->inicio->no));
}

void EstaVazia(tipoLista lista)
{
  return (lista.inicio == lista.fim);
}

void Insere(tipoLista* eLista, tipoNo noNovo)
{
  *(eLista).fim->prox = (apontador) malloc(sizeof(tipoCelula));
  *(eLista).fim = *(eLista).fim->prox;
  *(eLista).fim->prox = NULL;
  *(eLista).fim->no = noNovo;
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
