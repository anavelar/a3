int maximo;

maximo = 0;
for(k=0; k<=bitsAmais-1; k++)
{
  maximo = (maximo | (1 << k));
}
