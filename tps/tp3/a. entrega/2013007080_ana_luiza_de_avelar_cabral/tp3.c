#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//OBS.:
//1 - Usando alias do time
// alias time="$(which time) -f '\t%E real,\t%U user,\t%S sys,\t%K amem,\t%M mmem'"
//K Average total (data+stack+text) memory use of the process, in Kilobytes.
//M Maximum resident set size of the process during its lifetime, in Kilobytes.
// 2- Usando timeout:
// ./timeout [comando de exec do tp]
// https://github.com/pshved/timeout
//--------------------------------------------------------------------------------
// ls -l --group-directories-first
//- Execucao para testes unitários:
// make -f Makefile-temp
// make -f Makefile-temp clean
//Depois:
// ./tp3 ../tp3-toyexample/input1.in ../tp3-toyexample/meuoutput1.out 32.5
// ./timeout ./tp3 ../tp3-toyexample/inputmax-1-linha.in  ../tp3-toyexample/saida-max-1-linha.out 256

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
  // ta em MB, vezes 10^6 so?
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
