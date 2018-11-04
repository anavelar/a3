#ifndef PD
#define PD

#include <stdlib.h>
#include <stdio.h>
#include <math.h> //para a pow do inicializa e pd

#define MAIS 0
#define MENOS 1
//para nao esquecer no PD

//Estruturas de dados


//Assinaturas das funcoes
int InicializaPrograma(int argc, char *argv[], FILE** epArqEntrada, FILE** epArqSaida);
void LeDadosInstancia(FILE** epArqEntrada, int* eS, int* eV, int* eX, long int* eM, int** esequencia);
void InicializaPD(long int* pd, int* es, int* sequencia, int V, int X);
void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida);

#endif
