
#include <stdio.h>

#include "../includes/ajuda.h"

void ajuda(const char* filename) {
    
    printf("Uso: %s <opcao> [<arquivo>]\n", filename);

    guia_opcoes();
    
}

void guia_opcoes() {

    char* opcoes[] = {
        "-a : análise de arquivo, complexidade de tempo estimada",
        "-c : análise do tempo médio de execução de algoritmo",
        "-h : exibe o guia de ajuda"
    };

    int tam = sizeof(opcoes) / sizeof(opcoes[0]);
    int i;

    printf("Opções:\n");

    for (i=0; i<tam; i++) {
        printf("\t%s\n", opcoes[i]);
    }

    printf("\n");

}