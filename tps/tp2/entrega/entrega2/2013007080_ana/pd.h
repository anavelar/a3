#ifndef PD
#define PD

#include <stdlib.h>
#include <stdio.h>

//Estruturas de dados
typedef struct tipono* apontador;

typedef struct tipono {
  long int valor;    // Montante: ate 1 000 000, logo long int
  int indices;       //Entre 0 (raiz) e S (apos +Ss) - S max 10^3

  apontador filhoSub;
  apontador filhoAdd;
} tipoNo;


//Assinaturas das funcoes
int InicializaPrograma(int argc, char *argv[], FILE** epArqEntrada, FILE** epArqSaida);
void LeDadosInstancia(FILE** epArqEntrada, int* eS, int* eV, int* eX, long int* eM, int** esequencia);
void InicializaNo(tipoNo* eno, long int valor, int indicesPai);
void InicializaArvore(apontador* earvore, int V, long int* eValorMax);
tipoNo* VisitaNo(tipoNo* eno, int* sequencia, int X, int S, long int* evalorMax);
void ImprimeResultado(long int valorMax, FILE** epArqSaida, long int M);
void ReiniciaParaProxCaso(int** esequencia, tipoNo** earvore);
void EncerraPrograma(FILE** epArqEntrada, FILE** epArqSaida);

#endif
