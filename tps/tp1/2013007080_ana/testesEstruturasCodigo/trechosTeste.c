  //TESTE 1 - Estrutura de Ramos ok
  //Colocado no main, no final apos construir os ramos (arquivo tp1.c)
  //teste: Imprime os ramos construidos
  //Cada ramo
  for(k=0; k<numRamos; k++) //tem pelo menos 1 ramo
  {
    printf("Ramo %d:\n", (k+1));
    //Elementos em cada ramo:
    for(j=0; j<(tamanhoDesseRamo[k]); j++)
    {
      printf("%d\n", vetorRamos[k][j]);
    }
    printf("\n");
  }

  //TESTE 2
