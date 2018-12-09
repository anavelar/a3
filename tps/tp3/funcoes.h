#ifndef FUNCOESTP3
#define FUNCOESTP3

#include <stdlib.h>
#include <stdio.h>

//Constantes do programa
#define ERRO 1
#define NORMAL 0
#define NUM_PARAMETROS 4

//Estruturas de dados


//Assinaturas das funcoes
int InicializaPrograma(int argc, char** argv, FILE** epArqEntrada, FILE** epArqSaida, float* elimiteMB);
void LeInfoMatriz(FILE** epArqEntrada, int* enumLinhas, int* enumColunas);
void LeLinhaMatriz(FILE** epArqEntrada, FILE** epArqSaida, int numColunas, float* emediaGeral, int linha, int numLinhas);
void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida);

#endif
