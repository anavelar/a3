#include "area.h"

// Funcoes

void FAVazia(TipoArea *Area)
{
  int i;
  Area->NumCelOcupadas = 0;
  Area->Primeiro = -1;
  Area->Ultimo = -1;
  Area->CelulasDisp = 0;

  for (i =0; i<TAMAREA; i++)
    {
      Area->Itens[i].Ant = -1;
      Area->Itens[i].Prox = i + 1;
    }
}

int ObterNumCelOcupadas(TipoArea *Area)
{
  return (Area->NumCelOcupadas);
}

void InsereItem(TipoRegistro Item, TipoArea *Area)
{
  int Pos, Disp, IndiceInsercao;

  if (Area->NumCelOcupadas == TAMAREA)
  {
    //Tenta inserir em lista cheia: printf("Tentativa de insercao em lista cheia.\n");
    return;
  }

  Disp = Area->CelulasDisp;
  Area->CelulasDisp = Area->Itens[Area->CelulasDisp].Prox;
  Area->Itens[Disp].Item = Item;
  Area->NumCelOcupadas++;

  if (Area->NumCelOcupadas == 1)
  {
    // Insercao do primeiro item
    Area->Primeiro = Disp;
    Area->Ultimo = Area->Primeiro;
    Area->Itens[Area->Primeiro].Prox = -1;
    Area->Itens[Area->Primeiro].Ant = -1;
    return;
  }

  Pos = Area->Primeiro;

  if (Item.Chave < Area->Itens[Pos].Item.Chave)
  {
    // Insercao realizada na primeira posicao
    Area->Itens[Disp].Ant = -1;
    Area->Itens[Disp].Prox = Pos;
    Area->Itens[Pos].Ant = Disp;
    Area->Primeiro = Disp;
    return;
  }

  IndiceInsercao = Area->Itens[Pos].Prox;
  while (IndiceInsercao != -1 && Area->Itens[IndiceInsercao].Item.Chave < Item.Chave)
    {
      Pos = IndiceInsercao;
      IndiceInsercao = Area->Itens[Pos].Prox;
    }

  if (IndiceInsercao == -1)
  {
    // Insercao realizada na ultima posicao
    Area->Itens[Disp].Ant = Pos;
    Area->Itens[Disp].Prox = -1;
    Area->Itens[Pos].Prox = Disp;
    Area->Ultimo = Disp;
    return;
  }

  Area->Itens[Disp].Ant = Pos;
  Area->Itens[Disp].Prox = Area->Itens[Pos].Prox;
  Area->Itens[Pos].Prox = Disp;
  Pos = Area->Itens[Disp].Prox;
  Area->Itens[Pos].Ant = Disp;
}

void RetiraPrimeiro(TipoArea *Area, TipoRegistro *Item)
{
  TipoApontador ProxTmp;

  if (Area->NumCelOcupadas == 0)
  {
    // Area vazia: printf("Erro - Lista vazia\n");
    return;
  }

  *Item = Area->Itens[Area->Primeiro].Item;
  ProxTmp = Area->Itens[Area->Primeiro].Prox;
  Area->Itens[Area->Primeiro].Prox = Area->CelulasDisp;
  Area->CelulasDisp = Area->Primeiro;
  Area->Primeiro = ProxTmp;

  if ((unsigned int)Area->Primeiro < TAMAREA)
    Area->Itens[Area->Primeiro].Ant = -1;

  Area->NumCelOcupadas--;
}

void RetiraUltimo(TipoArea *Area, TipoRegistro *Item)
{
  TipoApontador AntTmp;

  if (Area->NumCelOcupadas == 0)
  {
    // Area vazia: printf("Erro - Lista vazia\n");
    return;
  }

  *Item = Area->Itens[Area->Ultimo].Item;
  AntTmp = Area->Itens[Area->Ultimo].Ant;
  Area->Itens[Area->Ultimo].Prox = Area->CelulasDisp;
  Area->CelulasDisp = Area->Ultimo;
  Area->Ultimo = AntTmp;

  if ((unsigned int)Area->Ultimo < TAMAREA)
    Area->Itens[Area->Ultimo].Prox = -1;

  Area->NumCelOcupadas--;
}

void ImprimeArea(TipoArea *Area)
{
  int Pos;
  if (Area->NumCelOcupadas <= 0)
  {
    ///Lista vazia: printf("Lista Vazia\n");
    return;
  }

  printf("** LISTA **\n");
  printf("Numero de Celulas Ocupadas = %d\n", Area->NumCelOcupadas);

  Pos = Area->Primeiro;
  while (Pos != -1)
    {
      printf("%d\n", Area->Itens[Pos].Item.Chave);
      Pos = Area->Itens[Pos].Prox;
    }
}
