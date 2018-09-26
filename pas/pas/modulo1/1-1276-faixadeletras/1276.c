//possiveis paus:
// 1 - usando char como bool varias vezes, o uri faz a conversao char para int
// automático? Se não fizer vai dar pau, trocar tudo.
// 2 - ***Está imprimindo um \n após o último caso, atentar a isso! adequar na
// função implementada.

//PRESSUPOSTOS:
// 1- Toda string tem um \n no final, nao termina com EOF - pelo que vi
// no caso de teste.

#include <stdlib.h>
#include <stdio.h>

#define NUM_LETRAS_ALFABETO 26

void ResetaVetorCaso (char** eVetorCaso)
{
  int i;

  for (i=0; i<=25; i++)
  {
    (*(eVetorCaso))[i] = 0;
  }
}

int main() {

  //Variáveis e Estruturas de dados
  char* vetorCaso = (char*) malloc(NUM_LETRAS_ALFABETO * sizeof(char));
  char c;
  char fimArquivo = 0;

  //Programa
  //Criar estrutura para armazenar cada caso e a inicializa
  //OBS.:vou usar char para economizar espaço, pode ser decisao porca talvez
  ResetaVetorCaso(&vetorCaso);

  //Leitura de cada caso / linha
  //Cada caso
  fimArquivo = scanf("%c", &c);
  while(fimArquivo > 0) //Se o arquivo não está vazio / se chegou ao fim
  {
      while(c != '\n')
      {
        printf("%c", c);
        fimArquivo = scanf("%c", &c);
      }

      printf("\n"); //leu uma linha vazia /\ *se for o ultimo \n do arquivo nao
      fimArquivo = scanf("%c", &c);
  }

  // -----------------TESTES E etc

  return 0;
}
