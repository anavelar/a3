#ifndef GRAFOS
#define GRAFOS

#include "listaEncadeada.h"

#define BRANCO 1
#define CINZA 2
#define PRETO 3
#define INICIALIZACAO -1

#define DIFERENTE 0
#define NORMAL 1

//Estruturas de dados
typedef tipoLista* tipoGrafo;

//Assinaturas das funcoes
void InicializaGrafoSemArestas(tipoGrafo* eGrafo, int numVertices);
void InsereAresta(tipoGrafo* eGrafo, int verticeOrigem, int verticeDestino);
int VisitaDFS(FILE** eponteiroArqSaida, int** vetorRamos, int* eNumRamos, int* tamanhoDesseRamo, int* ramoBusca, int* eTamanhoRamoBusca, int vertice, tipoGrafo* eGrafo, int** eCor, int** eAntecessor, int* eTempo, int** eD, int** eF);

#endif
