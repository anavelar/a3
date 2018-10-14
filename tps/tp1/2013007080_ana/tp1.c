// Ja inclui as bib padrao:
// sdtlib, sdtio, string, math
// constantes usadas estao aqui tb, alem da estr dados e funcoes
#include "grafos.h"

#define INVALIDO -1
#define VALORENORME 1000

//---------------------------------PROGRAMA
int main(int argc, char** argv){

  int j, k;

  FILE *ponteiroArqEntrada;
  FILE *ponteiroArqSaida;
  tipoGrafo Grafo = NULL;
  int numVertices = 0;
  int numArestas = 0;
  int vOrigem, vDestino;

  int* cor = NULL;
  int* antecessor = NULL;
  int tempo = 0;
  int* d = NULL;
  int* f = NULL;
  int* setasEntrando = NULL;
  tipoLista verticesRaiz;
  tipoNo noAux;
  apontador aux = NULL;
  int indicaCiclo = NORMAL; //Se tiver ciclo, ela vira o valor DIFERENTE (ZERO)

  //Ramo de busca
  int* ramoBusca = NULL;
  int tamanhoRamoBusca = 0;
  //Vetor com os ramos de busca
  int** vetorRamos = NULL;
  int numRamos = 0;
  int* tamanhoDesseRamo = NULL;
  int* vetorResultado = NULL;
  int verticesInseridos = 0;
  int* inicioRamo = NULL;
  int verticeMax = INVALIDO;
  int ramoVerticeMax = INVALIDO;

  //Inicializacoes
  noAux.chave = INVALIDO;
  CriaListaVazia(&verticesRaiz);

  //Entrada dos dados
  if(argc != 3)
  {
    printf("\nERRO. Faltam parametros para a execucao do programa,");
    printf("falta especificar o arquivo de entrada, de saida ou o executavel.\n");
    printf("\nNao foi possivel executar o programa.\n\n");
    return 0;
  }

  ponteiroArqSaida = fopen(argv[2],"w");
  ponteiroArqEntrada = fopen(argv[1],"r");
  if(ponteiroArqEntrada == NULL)
  {
    printf("\nNao foi possivel encontrar o arquivo de entrada.\n");
    printf("\nNao foi possivel executar o programa.\n\n");
    fclose(ponteiroArqSaida);
    return 0;
  }

  //Para cada caso:
  //Le como sera grafo
  fscanf(ponteiroArqEntrada, "%d %d\n", &numVertices, &numArestas);
  //Inicializa o ramo de busca
  ramoBusca = (int*) malloc(numVertices*(sizeof(int)));
  tamanhoRamoBusca = 0;
  //Inicializa o vetor de ramos encontrados
  vetorRamos = (int**) malloc(numVertices*(sizeof(int*)));
  tamanhoDesseRamo = (int*) malloc(numVertices*(sizeof(int)));
  inicioRamo = (int*) malloc(numVertices*(sizeof(int)));
  for(j=0; j<numVertices; j++)
  {
    vetorRamos[j] = NULL;
    inicioRamo[j] = 0;
    //tamanhoDesseRamo = 0; //Nao precisa inicializar e vai gastar tempo
  }

  //Cria o Grafo como matriz Adjacencias
  InicializaGrafoSemArestas(&Grafo, numVertices);

  //Inicializa o vetor para achar, ao inserir as arestas, os vertices
  //raiz do DFS
  setasEntrando = (int*) malloc((numVertices+1)*(sizeof(int)));
  //Inicializa a sentinela
  setasEntrando[0] = VALORENORME;
  for(k=1; k<(numVertices+1); k++)
  {
    setasEntrando[k] = 0;
  }

  //Insere as arestas nele
  for(k=0; k<numArestas; k++)
  {
    fscanf(ponteiroArqEntrada, "%d %d\n", &vOrigem, &vDestino);
    InsereAresta(&Grafo, vOrigem, vDestino);
    setasEntrando[vDestino]++;
  }

  //Procura vertices raizes do DFS e os separa dos outros
  for(k=1; k<(numVertices+1); k++)
  {
    if(setasEntrando[k] == 0)
    {
      noAux.chave = k;
      Insere(&verticesRaiz, noAux);
    }
  }

  //Faz busca em profundidade nele
  //Prepara o Grafo para o DFS
  cor = (int*) malloc((numVertices+1)*(sizeof(int)));
  antecessor = (int*) malloc((numVertices+1)*(sizeof(int)));
  d = (int*) malloc((numVertices+1)*(sizeof(int)));
  f = (int*) malloc((numVertices+1)*(sizeof(int)));
  tempo = 0;

  //Incializa a sentinela:
  cor[0] = INVALIDO;
  antecessor[0] = INVALIDO;
  d[0] = INVALIDO;
  f[0] = INVALIDO;

  //Inicializa os outros
  for(k=1; k<numVertices+1; k++)
  {
    cor[k] = BRANCO;
    antecessor[k] = INICIALIZACAO;
    d[k] = INICIALIZACAO;
    f[k] = INICIALIZACAO;
  }

  if(EstaVazia(verticesRaiz)) //Se não há vertices raiz
  {
    //fprintf(ponteiroArqSaida, "Erro, nao ha vertices raiz.\n");
    //*************************************************************************
    //VOLTAR AQUI PARA VER SE EH ISSO MESMO
    fprintf(ponteiroArqSaida, "0 -1");

    fclose(ponteiroArqEntrada);
    fclose(ponteiroArqSaida);
    return 0;
  }
  else //Se ha vertices raiz possiveis
  {
    aux = verticesRaiz.inicio->prox; //endereco da primeira celula raiz possivel
  }

  //Percorre a lista de vertices raiz possiveis: DFS com os verticesRaiz so
  //Cada arvore da floresta que eh essa arvores
  while(aux != NULL)
  {
    indicaCiclo = VisitaDFS(&ponteiroArqSaida, vetorRamos, &numRamos, tamanhoDesseRamo, ramoBusca, &tamanhoRamoBusca, aux->no.chave, &Grafo, &cor, &antecessor, &tempo, &d, &f);
    //VisitaDFS(vertice k)

    if(!indicaCiclo) //Se tem ciclo
    {
      fclose(ponteiroArqEntrada);
      fclose(ponteiroArqSaida);
      return 0; //nao precisa imprimir: impressao feita quando achou o ciclo
    }
    else
    {
      aux = aux->prox;
    }

  }

  //Gera resultado a partir dos Ramos e o imprime no arquivo
  //******************************AQUI
  //Inicializa o vetor de resultados
  vetorResultado = (int*) malloc(numVertices*(sizeof(int)));
  verticesInseridos = 0;

  //Ate inserir todos os vertices no vetor de Resultados:
  //Procura pelo vertice max da vez e on insere no vetor de resultados
  for(j=0; j<numVertices; j++)
  {
    //Procura o vertice max entre os ramos
    for(k=0; k<numRamos; k++)
    {
      if((0+inicioRamo[k]) < tamanhoDesseRamo[k]) //Se ainda ha vertices nesse ramo
      {
        if( vetorRamos[k][0+inicioRamo[k]] > verticeMax )
        {
          verticeMax = vetorRamos[k][0+inicioRamo[k]];
          ramoVerticeMax = k;
        }
      }
    }

    //Apos achar verticeMax (e seu ramo ramoVerticeMax)
    //Insere o max no vetor de resultados
    vetorResultado[verticesInseridos] = verticeMax;
    verticesInseridos++;

    //Retira verticeMax da busca nos ramos
    inicioRamo[ramoVerticeMax]++;

    //Reinicializa para busca
    verticeMax = INVALIDO;
    ramoVerticeMax = INVALIDO;
  }

  //teste
  //Imprime os resultados
  //ARRUMAR ISSO, EH O X QUE VAI SER 1 OU 2 (CASO X=O JA TRATADO).
  fprintf(ponteiroArqSaida, "%d ", 27);
  //imprime cada vertice
  for(k=(numVertices-1); k>=0; k--)
  {
    if(k==0)
    {
      fprintf(ponteiroArqSaida, "%d", vetorResultado[k]);
    }
    else
    {
      fprintf(ponteiroArqSaida, "%d,", vetorResultado[k]);
    }
  }

  //No final: Desalocar memoria
  //free(cor);
  //free(antecessor);
  //free(d);
  //free(f);
  //free(setasEntrando);
  //Grafo = NULL; // OU free(Grafo); nao vai desalocar tudo mas ja ajuda sera?**** desalocar
  //desalocar variavel ramo
  //desalocar ramo de busca, reinicializar seu tamanho (se necessario esta parte)
  //procurar tudo alocado para desalocar

  // Desalocar/limpar verticesRaiz
  fclose(ponteiroArqEntrada);
  fclose(ponteiroArqSaida);
  return 0;
}
