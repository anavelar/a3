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

  //Programa
  //Criar estrutura para armazenar cada caso e a inicializa
  //OBS.:vou usar char para economizar espaço, pode ser decisao porca talvez
  ResetaVetorCaso(&vetorCaso);

  //Leitura de cada caso / linha
  //Um caso
  while(scanf("%c", &c) != 'EOF')
  {
    while(scanf("%c", &c) != '\n') //aqui ja vai dar pau no ultimo caso que pode nao ter \n
    {
      //teste
      printf("%c", c);
    }
    printf("\n");
  }

//Ler caracter a caracter: ja vai prrenchendo animal krl

    //1-Leitura de cada caso de teste
    char stringLida[52];

    //NAO ESQUECER DE TRATAR CASOS BIZAAROS, LINHAS EM BRANCO ETC

    // -----------------TESTES E etc

    //teste inicializacao vetorCaso
    /*
    int c;
    for(c=0; c<=25; c++)
    {
      printf("vetorCaso[%d] é %d.\n", c, vetorCaso[c]);
    }
    */

    //Uma Leitura sem espaços
    /*
    while (scanf("%s\n", stringLida) > 0 )
    {
      //teste: printf("A string lida foi %s\n", stringLida);
    }
    */

    return 0;
}
