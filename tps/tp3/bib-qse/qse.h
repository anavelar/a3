#ifndef QSE
#define QSE

// Bibliotecas auxiliares
#include "area.h"

// Constantes
#define TRUE 1
#define FALSE 0

// Estruturas de Dados
typedef TipoItem TipoRegistro;

// Funcoes
void LeSup(FILE **ArqLEs, TipoRegistro *UltLido, int *Ls, short *OndeLer);
void LeInf(FILE **ArqLi,  TipoRegistro *UltLido, int *Li, short *OndeLer);
void InserirArea(TipoArea *Area, TipoRegistro *UltLido, int *NRArea);
void EscreveMax(FILE **ArqLEs, TipoRegistro R, int *Es);
void EscreveMin(FILE **ArqEi,  TipoRegistro R, int *Ei);
void RetiraMax(TipoArea *Area,  TipoRegistro *R, int *NRArea);
void RetiraMin(TipoArea *Area, TipoRegistro *R, int *NRArea);
void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j);
void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir);

#endif
