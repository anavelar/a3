#ifndef LISTAENCADEADA
#define LISTAENCADEADA
// OBS.: *********************************
// 1) REMOVE NAO IMPLEMENTADA AINDA
// VOU VER SE VAI PRECISAR E COMO VAO SER AS REMOCOES
// ---------------------------------------------------------------------------
// Lista Encadeada Simples com sentinela na primeira posicao para melhorar
// as operacoes sobre ela.
// ---------------------------------------------------------------------------
// Aqui na biblioteca.h
// colocar as estruturas de dados e as
// assinaturas das funcoes, que por sua vez
// estao implementadas no .c
//DUVIDA: PODE DAR PAU
// estruturas de dados aqui antes?
// usava include, como eh com ifndef? enfim
// ---------------------------------------------------------------------------
//--------------------------------- ESTRUTURAS DE DADOS
typedef struct tipoCelulah* apontador;
typedef struct{
  int chave;
} tipoNo;
typedef struct tipoCelulah{
  tipoNo no;
  apontador prox;
} tipoCelula;
typedef struct {
  apontador inicio;
  apontador fim;
} tipoLista;

// ---------------------------------ASSINATURAS DAS FUNCOES
void ImprimeNo(tipoNo no);
void InicializaNoSentinela(tipoNo* eNo);
void CriaListaVazia(tipoLista* eLista);
int EstaVazia(tipoLista lista);
void Insere(tipoLista* eLista, tipoNo noNovo);
//void Remove(tipoLista* eLista);
void ImprimeLista (tipoLista lista);
#endif
