#ifndef QSE
#define QSE

// Bibliotecas auxiliares
#include "area.h"

// Constantes
#define TRUE 1
#define FALSE 0
// De acordo com o enunciado, cada valor eh positivo e menor que esse
#define MAIOR_VLR_POSSIVEL_PROBL 4294967297
#define MENOR_VLR_POSSIVEL_PROBL -1

// Funcoes
void LeSup(FILE **ArqLEs, TipoRegistro *UltLido, int *Ls, short *OndeLer);
void LeInf(FILE **ArqLi,  TipoRegistro *UltLido, int *Li, short *OndeLer);
void InserirArea(TipoArea *Area, TipoRegistro *UltLido, int *NRArea, int tamArea);
void EscreveMax(FILE **ArqLEs, TipoRegistro R, int *Es);
void EscreveMin(FILE **ArqEi,  TipoRegistro R, int *Ei);
void RetiraMax(TipoArea *Area,  TipoRegistro *R, int *NRArea, int tamArea);
void RetiraMin(TipoArea *Area, TipoRegistro *R, int *NRArea, int tamArea);
void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j, int tamArea);
void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int tamArea);

#endif
