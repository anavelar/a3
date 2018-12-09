#include "qse.h"

//int main(int argc, char *argv[])
int main()
{
  //Variaveis
  FILE *ArqLEs;
  FILE *ArqLi;
  FILE *ArqEi;
  TipoRegistro R;

  //Cria teste.dat e escreve nele os registros a serem ordenados
  ArqLi = fopen ("teste.dat", "wb");
  if(ArqLi == NULL) {printf("Arquivo nao pode ser aberto\n "); exit(1);}
  R.Chave = 5;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  R.Chave = 3;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  R.Chave = 10; fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  R.Chave = 6;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  R.Chave = 1;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  R.Chave = 7;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  R.Chave = 4;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi);
  fclose(ArqLi);

  //Faz o QSE nesse arquivo que já foi fechado de novo
  ArqLi = fopen ("teste.dat", "r+b");
  if (ArqLi == NULL) {printf("Arquivo nao pode ser aberto\n"); exit(1);}
  ArqEi = fopen ("teste.dat", "r+b");
  if (ArqEi == NULL) {printf("Arquivo nao pode ser aberto\n"); exit(1);}
  ArqLEs = fopen ("teste.dat", "r+b");
  if (ArqLEs == NULL)
  { printf ("Arquivo nao pode ser aberto\n");  exit(1);
  }

  QuicksortExterno(&ArqLi, &ArqEi, &ArqLEs, 1, 7);
  fflush(ArqLi); fclose(ArqEi); fclose(ArqLEs);
  fseek(ArqLi,0, SEEK_SET);
  while(fread(&R, sizeof(TipoRegistro), 1, ArqLi))
    { printf("Registro=%d\n", R.Chave);
    }
  fclose(ArqLi);
  return 0;
}
