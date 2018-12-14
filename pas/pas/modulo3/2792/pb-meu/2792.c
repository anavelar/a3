#include <stdlib.h>
#include <stdio.h>
//#include <limits.h>
//#include <sys/time.h>
//#define MAX  10

// Estruturas de dados
typedef long TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;    //Item da sequencia
  long int posicao;   //Posicao dele no "vetor" da questao
} TipoRegistro;

typedef struct TipoNo* TipoApontador;

typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef TipoApontador TipoDicionario;

//Assinaturas************************************
void Insere(TipoRegistro x, TipoApontador *p);

int main(){

  long int i; //Contador
  long int N;
  long int retirada;
  TipoNo* Dicionario;
  TipoRegistro x;
  long int noInicial;

  //Leitura do arquivo de entrada
  scanf("%li\n", &N);

  //Inicializa o Dicionario
  Dicionario = NULL;
  noInicial = ((long int) (N/2));
  x.Chave = noInicial;
  x.posicao = noInicial;
  Insere(x, &Dicionario);
  
  //Insere os outros nos
  for (i=1; i<(N+1); i++) //De 1 a N
  {
    x.Chave = i;
    x.posicao = i;
    Insere(x, &Dicionario);
  }

  //Leitura e efetivacao das retiradas
  //Os que tem espaco depois
  for(i=1; i<N; i++) // De 1 ate (N-1), um a menos
  {
    scanf("%li ", &retirada);
  }
  //Ultimo do arquivo
  scanf("%li", &retirada);

  //Finaliza o programa
  //Desalocacoes etc

  return 0;
}

//Funcoes
void Insere(TipoRegistro x, TipoApontador* p)
{
  //Se a arvore esta vazia
  if (*p == NULL)
  {
    *p = (TipoApontador)malloc(sizeof(TipoNo));
    (*p)->Reg = x;
    (*p)->Esq = NULL;
    (*p)->Dir = NULL;
    return;
  }

  if (x.Chave < (*p)->Reg.Chave)
  {
    Insere(x, &(*p)->Esq);
    return;
  }

  if (x.Chave > (*p)->Reg.Chave)
    Insere(x, &(*p)->Dir);
}
