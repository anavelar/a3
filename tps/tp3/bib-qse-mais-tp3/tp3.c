#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//OBS.:
// ls -l --group-directories-first
//- Execucao para testes unitários:
// make -f Makefile-temp
// make -f Makefile-temp clean
//Depois:
// ./tp3 ../tp3-toyexample/input1.in ../tp3-toyexample/meuoutput1.out 32.5

int main(int argc, char** argv){

  //Declaração de variáveis
  FILE *pArqEntrada = NULL, *pArqSaida = NULL, *ArqLi = NULL;
  float limiteMB;
  int leituraok;
  int numLinhas, numColunas; //De 1 ate 3mil.
  float mediaGeral = 0.00f;
  int i; //Contador
  int tamArea;

  //Programa
  //aqui********88 -- definir tamarea aqui dentro direito  CASOS DE TESTE ***************************888
  leituraok = InicializaPrograma(argc, argv, &pArqEntrada, &pArqSaida, &limiteMB, &tamArea);
  if(leituraok) //Se retornou ERRO
    return ERRO;

  LeInfoMatriz(&pArqEntrada, &numLinhas, &numColunas);
  for(i=0; i<numLinhas; i++)
  {
    leituraok = LeLinhaMatriz(&pArqEntrada, &pArqSaida, &ArqLi, numColunas, &mediaGeral, i, numLinhas, tamArea);
    if(leituraok) //Se retornou ERRO
      return ERRO;
  }

  //FIM DO PROGRAMA
  EncerraPrograma(&pArqEntrada, &pArqSaida);
  return NORMAL;

}
