
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../includes/analisador.h"

Complexidade max_complexidade(Complexidade a, Complexidade b) {
    
    return a > b ? a : b;

}

Complexidade mult_complexidade(Complexidade a, Complexidade b) {

    if (a == O_1) return b;

    if (b == O_1) return a;

    if (a == O_N && b == O_N) return O_N2;

    if ((a == O_N && b == O_N2) || (a == O_N2 && b == O_N)) return O_N3;

    if ((a == O_N && b == O_LOG_N) || (a == O_LOG_N && b == O_N)) return O_N_LOG_N;

    return O_DESCONHECIDO;

}

ResultadoAnalise analisar_codigo(const char* codigo) {

    ResultadoAnalise resultado = {0, O_1};
    char copiaCodigo[strlen(codigo) + 1];
    strcpy(copiaCodigo, codigo);

    Complexidade pilhaComplexidade[MAX_ANINHAMENTO];
    int topoPilha = 0;
    pilhaComplexidade[topoPilha] = O_1;

    Complexidade complexidadeGeral = O_1;

    const char* instrucoes[] = {"=", "if", "else", "return", "+", "-", "*", "/", "<", ">", "=="};
    int numInstrucoes = sizeof(instrucoes) / sizeof(instrucoes[0]);

    char* delimitadores = " \t\n\r(){};";
    char* token = strtok(copiaCodigo, delimitadores);

    while(token != NULL) {
        
        // Contagem de Instruções Básicas
        int i;
        for (i=0; i<numInstrucoes; i++) {
            if (strcmp(token, instrucoes[i]) == 0) {
                resultado.instrucoesBasicas++;
            }
        }

        // Análise da Complexidade
        if (strcmp(token, "for") == 0 || strcmp(token, "while") == 0) {

            char* proxToken = strtok(NULL, ")");

            Complexidade complexidadeLaco = O_DESCONHECIDO;

            if (strstr(proxToken, "< n") || strstr(proxToken, "<= n")) {

                if (strstr(proxToken, "++") || strstr(proxToken, "--") || strstr(proxToken, "+=") || strstr(proxToken, "-=")) {
                    
                    complexidadeLaco = O_N;

                } else if (strstr(proxToken, "/=") || strstr(proxToken, "*=")) {

                    complexidadeLaco = O_LOG_N;

                }

            } else {

                complexidadeLaco = O_1;

            }

            pilhaComplexidade[topoPilha] = mult_complexidade(pilhaComplexidade[topoPilha], complexidadeLaco);

        } else if (strchr(token, '{') != NULL) {

            if (topoPilha < MAX_ANINHAMENTO - 1) {

                topoPilha++;
                pilhaComplexidade[topoPilha] = pilhaComplexidade[topoPilha - 1];
            }

        } else if (strchr(token, '}') != NULL) {

            if (topoPilha > 0) {

                complexidadeGeral = max_complexidade(complexidadeGeral, pilhaComplexidade[topoPilha]);
                topoPilha--;
            }

        }

        token = strtok(NULL, delimitadores);

    }

    resultado.complexidade = max_complexidade(complexidadeGeral, pilhaComplexidade[topoPilha]);

    return resultado;

}

const char* complexidade_to_string(Complexidade complexidade) {

    switch(complexidade) {
        
        case O_1: return "O(1)";

        case O_LOG_N: return "O(log n)";

        case O_N: return "O(n)";

        case O_N_LOG_N: return "O(n log n)";

        case O_N2: return "O(n^2)";

        case O_N3: return "O(n^3)";

        default: return "O(?) - Desconhecido";
    }

}

void exibir_resultado_analise(ResultadoAnalise resultado, const char* filename) {

    printf("Analisando o arquivo: %s\n", filename);
    printf("-------------------------------------\n");

    printf("Contagem de Instruções Básicas: %d\n", resultado.instrucoesBasicas);
    printf("Complexidade de Tempo Estimada: %s\n", complexidade_to_string(resultado.complexidade));

    printf("-------------------------------------\n");

}
