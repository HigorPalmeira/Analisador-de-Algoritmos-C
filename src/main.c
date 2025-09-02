#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../includes/analisador.h"
#include "../includes/timer.h"
#include "../includes/ordenacao.h"
#include "../includes/busca.h"
#include "../includes/estatistico.h"

#include "../includes/ajuda.h"
#include "../includes/configuracao.h"

/*
    Tipagem de uma função com dois parâmetros e retorno do tipo void.

    @param int* Array de valores inteiros.
    @param int Valor inteiro
 */
typedef void (*FuncaoAlgoritmo)(int *, int);

void analisar_tempo(const char *nomeAlgoritmo, FuncaoAlgoritmo algoritmo, int nInicial, int nFinal, int passo, int repeticoes);
char *ler_arquivo(const char *filename);

void menu();

int main(int argc, char *argv[]) {

    setConsole();

    if (argc == 1) {

        ajuda(argv[0]);

        return 0;
    }

    char *opcao = argv[1];

    if (strstr(opcao, "-a") != NULL) {
        
        char *codigo = ler_arquivo(argv[2]);
    
        if (codigo == NULL) {
            return 1;
        }
    
        ResultadoAnalise resultado = analisar_codigo(codigo);
        exibir_resultado_analise(resultado, argv[2]);
    
        free(codigo);

    } else if (strstr(opcao, "-c") != NULL) {

        menu();

    } else if (strstr(opcao, "-h") != NULL) {
        
        ajuda(argv[0]);

    }

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
void analisar_tempo(const char *nomeAlgoritmo, FuncaoAlgoritmo algoritmo, int nInicial, int nFinal, int passo, int repeticoes)
{

    printf("Analisando o algoritmo: %s\n", nomeAlgoritmo);

    char nomeArquivo[256];
    sprintf(nomeArquivo, "resultados/tempo/%s.csv", nomeAlgoritmo);

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (!arquivo)
    {
        perror("Nao foi possivel criar o arquivo de resultados.");
        return;
    }

    fprintf(arquivo, "N, TempoMedio_ms\n");

    Timer *timer = criar_timer();

    for (int i = nInicial; i <= nFinal; i += passo)
    {

        double tempoTotal = 0.0;

        for (int j = 0; j < repeticoes; j++)
        {

            int *array = gerar_array_aleatorio(i);

            if (!array)
                continue;

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

char *ler_arquivo(const char *filename)
{

    FILE *arquivo = fopen(filename, "r");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char *conteudo = (char *)malloc(tamanho + 1);
    if (conteudo)
    {
        fread(conteudo, 1, tamanho, arquivo);
        conteudo[tamanho] = '\0';
    }

    fclose(arquivo);

    return conteudo;
}


void menu() {

    char opcao;

    printf("\n===\tTIPOS DE ALGORITMOS DISPONÍVEIS\t===\n");

    printf("[ 1 ] Busca\n");
    printf("[ 2 ] Estatísticos\n");
    printf("[ 3 ] Ordenação\n");

    printf("> ");
    scanf("%d", &opcao);

    switch(opcao) {

        case 1: {

            char opcaoBusca;

            printf("\n===\tALGORITMOS DE BUSCA\t===\n");

            printf("[ 1 ] Busca Binária\n");
            printf("[ 2 ] Busca Linear\n");
            printf("[ 3 ] Todas\n");

            printf("> ");
            scanf("%d", &opcaoBusca);

            switch(opcaoBusca) {
                case 1: {

                    analisar_tempo("BuscaBinaria", busca_binaria, 1000, 10000, 1000, 10);

                    break;
                }
                case 2: {

                    analisar_tempo("BuscaLinear", busca_linear, 1000, 10000, 1000, 10);

                    break;
                }
                case 3: {

                    analisar_tempo("BuscaBinaria", busca_binaria, 1000, 10000, 1000, 10);

                    analisar_tempo("BuscaLinear", busca_linear, 1000, 10000, 1000, 10);

                    break;
                }
                default: {
                    printf("Opção inválida!\n");
                    return;
                }
            }

            break;
        }

        case 2: {

            char opcaoEstatisticos;

            printf("\n===\tALGORITMOS DE ESTATÍSTICOS\t===\n");

            printf("[ 1 ] Calcular Máximo\n");
            printf("[ 2 ] Calcular Média\n");
            printf("[ 3 ] Calcular Mínimo");
            printf("[ 4 ] Calcular Soma\n");
            printf("[ 5 ] Todos\n");

            printf("> ");
            scanf("%d", &opcaoEstatisticos);

            switch(opcaoEstatisticos) {
                case 1: {

                    analisar_tempo("CalcularMaximo", encontrar_maximo, 1000, 10000, 1000, 10);

                    break;
                }

                case 2: {

                    analisar_tempo("CalcularMedia", calcular_media, 1000, 10000, 1000, 10);

                    break;
                }

                case 3: {

                    analisar_tempo("CalcularMinimo", encontrar_minimo, 1000, 10000, 1000, 10);

                    break;
                }

                case 4: {

                    analisar_tempo("CalcularSoma", calcular_soma, 1000, 10000, 1000, 10);

                    break;
                }

                case 5: {

                    analisar_tempo("CalcularMaximo", encontrar_maximo, 1000, 10000, 1000, 10);

                    analisar_tempo("CalcularMedia", calcular_media, 1000, 10000, 1000, 10);

                    analisar_tempo("CalcularMinimo", encontrar_minimo, 1000, 10000, 1000, 10);

                    analisar_tempo("CalcularSoma", calcular_soma, 1000, 10000, 1000, 10);

                    break;
                }

                default: {
                    printf("Opção inválida!\n");
                    return;
                }
            }

            break;
        }

        case 3: {

            char opcaoOrdenacao;

            printf("\n===\tALGORITMOS DE ORDENAÇÃO\t===\n");

            printf("[ 1 ] Bubble Sort\n");
            printf("[ 2 ] Insertion Sort\n");
            printf("[ 3 ] Selection Sort\n");
            printf("[ 4 ] Todos\n");

            printf("> ");
            scanf("%d", &opcaoOrdenacao);

            switch(opcaoOrdenacao) {

                case 1: {

                    analisar_tempo("BubbleSort", bubble_sort, 1000, 10000, 1000, 10);

                    break;
                }

                case 2: {

                    analisar_tempo("InsertionSort", insertion_sort, 1000, 10000, 1000, 10);

                    break;
                }

                case 3: {

                    analisar_tempo("SelectionSort", selection_sort, 1000, 10000, 1000, 10);

                    break;
                }

                case 4: {

                    analisar_tempo("BubbleSort", bubble_sort, 1000, 10000, 1000, 10);

                    analisar_tempo("InsertionSort", insertion_sort, 1000, 10000, 1000, 10);

                    analisar_tempo("SelectionSort", selection_sort, 1000, 10000, 1000, 10);

                    break;
                }

                default: {
                    printf("Opção inválida!\n");
                    return;
                }
            }

            break;
        }

    }

}
