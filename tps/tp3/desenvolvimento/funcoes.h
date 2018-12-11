#ifndef FUNCOESTP3
#define FUNCOESTP3

//Biblioteca auxiliares
#include <stdlib.h>
#include <stdio.h>
#include "qse.h"

//Constantes do programa
#define ERRO 1
#define NORMAL 0
#define NUM_PARAMETROS 4
#define INICIO 1

//Assinaturas das funcoes
int InicializaPrograma(int argc, char** argv, FILE** epArqEntrada, FILE** epArqSaida, float* elimiteMB, int* etamArea);
void LeInfoMatriz(FILE** epArqEntrada, int* enumLinhas, int* enumColunas);
int LeLinhaMatriz(FILE** epArqEntrada, FILE** epArqSaida, FILE** eArqLi, int numColunas, float* emediaGeral, int linha, int numLinhas, int tamArea);
void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida);

#endif
