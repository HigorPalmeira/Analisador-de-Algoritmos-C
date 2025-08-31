#ifndef ANALISADOR_H
    #define ANALISADOR_H

    #define MAX_ANINHAMENTO 50

    typedef enum {
        O_1,
        O_LOG_N,
        O_N,
        O_N_LOG_N,
        O_N2,
        O_N3,
        O_DESCONHECIDO
    } Complexidade;

    typedef struct {
        int instrucoesBasicas;
        Complexidade complexidade;
    } ResultadoAnalise;


    ResultadoAnalise analisar_codigo(const char* codigo);
    
    const char* complexidade_to_string(Complexidade complexidade);
    
    void exibir_resultado_analise(ResultadoAnalise resultado, const 
    char* filename);

#endif