#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/timer.h"
#include "../includes/ordenacao.h"

typedef void (*FuncaoAlgoritmo)(int*, int);

int main() {

    return 0;

}


void analisar(const char* nomeAlgoritmo, FuncaoAlgoritmo algoritmo, int nInicial, int nFinal, int passo, int repeticoes) {

    printf("Analisando o algoritmo: %s\n", nomeAlgoritmo);

    char nomeArquivo[256];
    sprintf(nomeArquivo, "resultados/%s.csv", nomeAlgoritmo);

    FILE* arquivo = fopen(nomeArquivo, "w");
    
    if (!arquivo) {
        perror("Nao foi possivel criar o arquivo de resultados.");
        return;
    }

    fprintf(arquivo, "N, TempoMedio_ms\n");

    Timer* timer = criar_timer();

    

}