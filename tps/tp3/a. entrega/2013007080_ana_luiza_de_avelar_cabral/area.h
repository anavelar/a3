#ifndef AREA
#define AREA

// Bibliotecas auxiliares
#include <stdlib.h>
#include <stdio.h>

//Estruturas de dados
typedef int TipoApontador;

typedef struct TipoRegistro {
  long long int Chave;
} TipoRegistro;

typedef struct TipoCelula {
  TipoRegistro Item;
  TipoApontador Prox, Ant;
} TipoCelula;

typedef struct TipoArea {
  TipoCelula* Itens;
  TipoApontador CelulasDisp, Primeiro, Ultimo;
  int NumCelOcupadas;
} TipoArea;

//Assinaturas das funcoes
void FAVazia(TipoArea *Area, int tamArea);
int ObterNumCelOcupadas(TipoArea *Area);
void InsereItem(TipoRegistro Item, TipoArea *Area, int tamArea);
void RetiraPrimeiro(TipoArea *Area, TipoRegistro *Item, int tamArea);
void RetiraUltimo(TipoArea *Area, TipoRegistro *Item, int tamArea);

#endif
