//possiveis paus:
// 1 - usando char como bool varias vezes, o uri faz a conversao char para int
// automático? Se não fizer vai dar pau, trocar tudo.
// 2 - ***Está imprimindo um \n após o último caso, atentar a isso! adequar na
// função implementada.

//PRESSUPOSTOS:
// 1- ***Toda string tem um \n no final, nao termina com EOF - pelo que vi
// no caso de teste.

//OTIMIZACOES DE TEMPO POSSIVEIS - TIME LIMIT
// 1- OU NAO - checar antes de 1 se caractere eh repetido:
// acho que vai aumentar o custo com o check ao inves de
// diminuir ja q nem sempre vem repetido e o custo da
// atribuicao eh baixo

#include <stdlib.h>
#include <stdio.h>

#define NUM_LETRAS_ALFABETO 26
#define DIFERENCA 97

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
      //Le cada caso e preenche o vetor de presenca
      while(c != '\n')
      {
        if(c != ' ')
        {
          vetorCaso[c-DIFERENCA] = 1;
        }

        fimArquivo = scanf("%c", &c);
      }

      //Chegou ao fim do caso lido
      //Percorre o vetor e vai imprimindo as faixas de letras
      

      printf("\n"); //leu uma linha vazia /\ *se for o ultimo \n do arquivo nao
      fimArquivo = scanf("%c", &c);

      //Zera o vetor de presenca e comeca um novo caso

      //VER O CASO STRING VAZIA E \N ---- TESTAR TODOS OS FLUXOS
  }

  // -----------------TESTES E etc

  return 0;
}
