#include "qse.h"

//Funcoes
void LeSup(FILE **ArqLEs, TipoRegistro *UltLido, int *Ls, short *OndeLer)
{
  fseek(*ArqLEs, (*Ls - 1) * sizeof(TipoRegistro), SEEK_SET);
  fread(UltLido, sizeof(TipoRegistro), 1, *ArqLEs);
  (*Ls)--;
  *OndeLer = FALSE;
}

void LeInf(FILE **ArqLi,  TipoRegistro *UltLido, int *Li, short *OndeLer)
{
  fread(UltLido, sizeof(TipoRegistro), 1, *ArqLi);
  (*Li)++;
  *OndeLer = TRUE;
}

void InserirArea(TipoArea *Area, TipoRegistro *UltLido, int *NRArea, int tamArea)
{
  InsereItem(*UltLido, Area, tamArea);
  *NRArea = ObterNumCelOcupadas(Area);
}

void EscreveMax(FILE **ArqLEs, TipoRegistro R, int *Es)
{
  fseek(*ArqLEs, (*Es - 1) * sizeof(TipoRegistro), SEEK_SET);
  fwrite(&R, sizeof(TipoRegistro), 1, *ArqLEs);
  (*Es)--;
}

void EscreveMin(FILE **ArqEi,  TipoRegistro R, int *Ei)
{
  fwrite(&R, sizeof(TipoRegistro), 1, *ArqEi);
  (*Ei)++;
}

void RetiraMax(TipoArea *Area,  TipoRegistro *R, int *NRArea, int tamArea)
{
  RetiraUltimo(Area, R, tamArea);
  *NRArea = ObterNumCelOcupadas(Area);
}

void RetiraMin(TipoArea *Area, TipoRegistro *R, int *NRArea, int tamArea)
{
  RetiraPrimeiro(Area, R, tamArea);
  *NRArea = ObterNumCelOcupadas(Area);
}

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j, int tamArea)
{
  long long int Lsup = MAIOR_VLR_POSSIVEL_PROBL, Linf = MENOR_VLR_POSSIVEL_PROBL;
  int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq, NRArea = 0;
  short OndeLer = TRUE;
  TipoRegistro UltLido, R;

  fseek (*ArqLi, (Li - 1)* sizeof(TipoRegistro), SEEK_SET );
  fseek (*ArqEi, (Ei - 1)* sizeof(TipoRegistro), SEEK_SET );

  *i = Esq - 1;
  *j = Dir + 1;

  while (Ls >= Li)
  {
    if (NRArea < tamArea - 1)
    {
      if(OndeLer)
        LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
      else
        LeInf(ArqLi, &UltLido, &Li, &OndeLer);

      InserirArea(&Area, &UltLido, &NRArea, tamArea);
      continue;
    }

    if (Ls == Es)
      LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
    else if (Li == Ei) LeInf(ArqLi, &UltLido, &Li, &OndeLer);
         else if (OndeLer) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
              else LeInf(ArqLi, &UltLido, &Li, &OndeLer);

    if (UltLido.Chave > Lsup)
    {
      *j = Es;
      EscreveMax(ArqLEs, UltLido, &Es);
      continue;
    }

    if (UltLido.Chave < Linf)
    {
      *i = Ei;
      EscreveMin(ArqEi, UltLido, &Ei);
      continue;
    }

    InserirArea(&Area, &UltLido, &NRArea, tamArea);
    if (Ei - Esq < Dir - Es)
    {
      RetiraMin(&Area, &R, &NRArea, tamArea);
      EscreveMin(ArqEi, R, &Ei);
      Linf = R.Chave;
    }
    else
    {
     RetiraMax(&Area, &R, &NRArea, tamArea);
     EscreveMax(ArqLEs, R, &Es);
     Lsup = R.Chave;
    }
  }
  while (Ei <= Es)
  {
    RetiraMin(&Area, &R, &NRArea, tamArea);
    EscreveMin(ArqEi, R, &Ei);
  }
}

void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir, int tamArea)
{
  int i, j;
  TipoArea Area;

  if (Dir - Esq < 1)
    return;

  FAVazia(&Area, tamArea);

  Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j, tamArea);

  if (i - Esq < Dir - j)
  {
    QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, tamArea);
    QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, tamArea);
  }
  else
  {
    QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir, tamArea);
    QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i, tamArea);
  }
}
