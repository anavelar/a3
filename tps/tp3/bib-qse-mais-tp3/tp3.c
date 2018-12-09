#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//OBS.:
// ls -l --group-directories-first
//- Execucao para testes unitários:
// make -f Makefile-temp
// make -f Makefile-temp clean
//Depois:
// ./tp3 tp3-toyexample/input1.in tp3-toyexample/meuoutput1.out 32.5

int main(int argc, char** argv){

  //Declaração de variáveis
  FILE* pArqEntrada = NULL;
  FILE* pArqSaida = NULL;
  float limiteMB;
  int leituraok;
  int numLinhas, numColunas; //De 1 ate 3mil.
  float mediaGeral = 0.00f;
  int i; //Contador

  //Programa
  leituraok = InicializaPrograma(argc, argv, &pArqEntrada, &pArqSaida, &limiteMB);

  if(leituraok) //Se retornou ERRO
    return ERRO;
  else      //Se foi possivel abrir os arquivos e ler os valores. Ai o programa mesmo.
  {
    LeInfoMatriz(&pArqEntrada, &numLinhas, &numColunas);

    for(i=0; i<numLinhas; i++)
      LeLinhaMatriz(&pArqEntrada, &pArqSaida, numColunas, &mediaGeral, i, numLinhas);

    //FIM DO PROGRAMA
    EncerraPrograma(&pArqEntrada, &pArqSaida);
    return NORMAL;
  }

}
