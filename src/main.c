#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/timer.h"
#include "../includes/ordenacao.h"
#include "../includes/busca.h"

/*
    Tipagem de uma função com dois parâmetros e retorno do tipo void.

    @param int* Array de valores inteiros.
    @param int Valor inteiro
 */
typedef void (*FuncaoAlgoritmo)(int*, int);

void analisar(const char* nomeAlgoritmo, FuncaoAlgoritmo algoritmo, int nInicial, int nFinal, int passo, int repeticoes);

int main() {

    analisar("InsertionSort", insertion_sort, 1000, 10000, 1000, 10);

    analisar("BubbleSort", bubble_sort, 1000, 10000, 1000, 10);
    
    analisar("SelectionSort", selection_sort, 1000, 10000, 1000, 10);

    analisar("BuscaLinear", busca_linear, 1000, 10000, 1000, 10);
    
    return 0;

}

/*
    Analisa um algoritmo medindo o seu tempo médio de execução e escrevendo o resultado em um arquivo CSV na pasta de resultados, com o nome do algoritmo.

    @param nomeAlgoritmo Cadeia de caracteres contendo o nome do algoritmo que será analisado.
    @param algoritmo Ponteiro para uma função do tipo void que recebe dois argumentos inteiros (array e um inteiro), que será executada e medida.
    @param nInicial Número do limite inferior da medição.
    @param nFinal Número do limite superior da medição.
    @param passo Número do passo utilizado na medição.
    @param repeticoes Quantidade de vezes que o algoritmo será executado.
*/
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

    for (int i = nInicial; i<=nFinal; i+=passo) {

        double tempoTotal = 0.0;

        for (int j=0; j<repeticoes; j++) {

            int* array = gerar_array_aleatorio(i);
            
            if (!array) continue;

            iniciar_timer(timer);
            algoritmo(array, i);
            parar_timer(timer);

            tempoTotal += tempo_timer_milisegundos(timer);

            free(array);

        }

        double tempoMedio = tempoTotal / repeticoes;
        
        printf("N = %-7d | Tempo Medio = %.6f ms\n", i, tempoMedio);

        fprintf(arquivo, "%d,%.6f\n", i, tempoMedio);

    }

    fclose(arquivo);
    limpar_timer(timer);

    printf("Analise de %s concluida. Resultados salvos em %s\n\n", nomeAlgoritmo, nomeArquivo);

}