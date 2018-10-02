#include <stdlib.h>
#include <stdio.h>
#include "listaencadeada.h"

int main(){

  tipoLista ListaNotas;
  CriaListaVazia(&ListaNotas);
  ImprimeLista(ListaNotas);
  printf("\n");

  tipoNo prim, seg, ter;
  prim.chave = 1;
  seg.chave = 2;
  ter.chave = 3;
  Insere(&ListaNotas, prim);
  ImprimeLista(ListaNotas);
  printf("\n");

  Insere(&ListaNotas, seg);
  ImprimeLista(ListaNotas);
  printf("\n");

  Insere(&ListaNotas, ter);
  ImprimeLista(ListaNotas);
  printf("\n");

  return 0;
}
