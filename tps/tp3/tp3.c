#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//OBS.:
//- Execucao para testes unitários: make
//- Execucao definitiva: make -f Makefile-entrega
//Depois:
//- ./tp3 tp3-toyexample/input1.in tp3-toyexample/output1meu.out 32.5
//- make clean

int main(int argc, char** argv){

  //Declaração de variáveis
  FILE* pArqEntrada = NULL;
  FILE* pArqSaida = NULL;
  float limiteMB;
  int leituraok;

  //Programa
  leituraok = InicializaPrograma(argc, argv, &pArqEntrada, &pArqSaida, &limiteMB);

  if(leituraok) //Se retornou ERRO
    return ERRO;
  else //Se foi possivel abrir os arquivos e ler os valores. Ai o programa mesmo.
  {


    //FIM DO PROGRAMA
    EncerraPrograma(&pArqEntrada, &pArqSaida);
    return NORMAL;
  }

}
