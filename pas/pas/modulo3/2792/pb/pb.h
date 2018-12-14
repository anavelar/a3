#ifndef PESQBIN
#define PESQBIN

// Bibliotecas auxiliares
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

// Constantes
#define MAX  10

// Estruturas de dados
typedef long TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;
  /* outros componentes */
} TipoRegistro;

typedef struct TipoNo * TipoApontador;

typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef TipoApontador TipoDicionario;

// Funcoes
void Pesquisa(TipoRegistro *x, TipoApontador *p);
void Insere(TipoRegistro x, TipoApontador *p);
void Inicializa(TipoApontador *Dicionario);
void Antecessor(TipoApontador q, TipoApontador *r);
void Retira(TipoRegistro x, TipoApontador *p);
void Central(TipoApontador p);
void TestaI(TipoNo *p, int pai);
void Testa(TipoNo *p);
double rand0a1();
void Permut( TipoChave A[], int n);

#endif
