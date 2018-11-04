#ifndef PD
#define PD

#include <stdlib.h>
#include <stdio.h>
#include <math.h>   //para a pow do inicializa e pd

//Para nao esquecer no PD so, deixar comentado
//MAIS = 0
//MENOS = 1

//Assinaturas das funcoes
int InicializaPrograma(int argc, char *argv[], FILE** epArqEntrada, FILE** epArqSaida);
void LeDadosInstancia(FILE** epArqEntrada, int* eS, int* eV, int* eX, long int* eM, int** esequencia);
void InicializaPD(long int** epd, int* es, int* sequencia, int V, int X);
void PDdes(long int** epd, long int** epdAnterior, int* es, int X, int* sequencia);
void BuscaResultadoeImprime(FILE** epArqSaida, long int** epd, int* es, int M, int** esequencia);
void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida);

#endif
