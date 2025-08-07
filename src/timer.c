#include <stdlib.h>

#include "../includes/timer.h"

/*
    Declaração do struct Timer para cada sistema operacional.
*/
#if defined(_WIN32)
    #include <windows.h>
    
    struct Timer {
        LARGE_INTEGER inicio;
        LARGE_INTEGER fim;
        LARGE_INTEGER frequencia;
    };

#elif defined(__linux__) || defined(__APPLE__)
    #include <time.h>

    struct Timer {
        struct timespec inicio;
        struct timespec fim;
    };

#endif

/*
    Cria um timer para contar o tempo decorrido no computador.

    @return Um ponteiro para um novo Timer.
*/
Timer* criar_timer() {

    Timer* timer = (Timer*) malloc(sizeof(Timer));

    #if defined(_WIN32)
        QueryPerformanceFrequency(&timer->frequencia);
    #endif

    return timer;

}

/*
    Inicializa um timer, marcando o tempo do computador no campo inicio.

    @param timer Timer que será incializado.
*/
void iniciar_timer(Timer* timer) {

    #if defined(_WIN32)
    
        QueryPerformanceCounter(&timer->inicio);
    
    #elif defined(__linux__) || defined(__APPLE__)
        
        clock_gettime(CLOCK_MONOTONIC, &timer->inicio);
        
    #endif

}

/*
    Para um timer, marcando o tempo do computador no campo fim.

    @param timer Timer que será parado.
*/
void parar_timer(Timer* timer) {

    #if defined(_WIN32)

        QueryPerformanceCounter(&timer->fim);

    #elif defined(__linux__) || defined(__APPLE__)

        clock_gettime(CLOCK_MONOTONIC, &timer->fim);

    #endif

}

/*
    Calcula o tempo decorrio no timer em segundos.

    @param timer Timer onde está os dados de inicio e fim.
    @return Tempo decorrido em segundos.
*/
double tempo_timer_segundos(Timer* timer) {

    #if defined(_WIN32)

        return (double) (timer->fim.QuadPart - timer->inicio.QuadPart) / timer->frequencia.QuadPart;

    #elif defined(__linux__) || defined(__APPLE__)

        return (timer->fim.tv_sec - timer->inicio.tv_sec) + (t->fim.tv_nsec - timer->inicio.tvnsec) / 1e9;

    #endif

}

/*
    Calcula o tempo decorrido no timer em milisegundos.

    @param timer Timer onde está os dados de inicio e fim.
    @return Tempo decorrido em milisegundos.
*/
double tempo_timer_milisegundos(Timer* timer) {

    return tempo_timer_segundos(timer) * 1000.0;

}

void limpar_timer(Timer* timer) {

    free(timer);

}