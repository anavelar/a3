#include "listaEncadeada.h"

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
