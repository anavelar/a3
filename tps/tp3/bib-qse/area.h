#ifndef AREA
#define AREA

// Bibliotecas auxiliares
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Constantes da biblioteca
#define TAMAREA 100

//Estruturas de dados
typedef int TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
  TipoChave Chave;
} TipoItem;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox, Ant;
} TipoCelula;

typedef struct TipoArea {
  TipoCelula Itens[TAMAREA];
  TipoApontador CelulasDisp, Primeiro, Ultimo;
  int NumCelOcupadas;
} TipoArea;

//Assinaturas das funcoes
void FAVazia(TipoArea *Area);
int ObterNumCelOcupadas(TipoArea *Area);
void InsereItem(TipoItem Item, TipoArea *Area);
void RetiraPrimeiro(TipoArea *Area, TipoItem *Item);
void RetiraUltimo(TipoArea *Area, TipoItem *Item);
void ImprimeArea(TipoArea *Area);

#endif
