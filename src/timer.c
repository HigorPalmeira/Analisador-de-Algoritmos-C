#include <stdlib.h>

#include "../includes/timer.h"

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


Timer* criar_timer() {

    Timer* timer = (Timer*) malloc(sizeof(Timer));

    #if defined(_WIN32)
        QueryPerformanceFrequency(&timer->frequencia);
    #endif

    return timer;

}


void iniciar_timer(Timer* timer) {

    #if defined(_WIN32)
    
        QueryPerformanceCounter(&timer->inicio);
    
    #elif defined(__linux__) || defined(__APPLE__)
        
        clock_gettime(CLOCK_MONOTONIC, &timer->inicio);
        
    #endif

}


void parar_timer(Timer* timer) {

    #if defined(_WIN32)

        QueryPerformanceCounter(&timer->fim);

    #elif defined(__linux__) || defined(__APPLE__)

        clock_gettime(CLOCK_MONOTONIC, &timer->fim);

    #endif

}


double tempo_timer_segundos(Timer* timer) {

    #if defined(_WIN32)

        return (double) (timer->fim.QuadPart - timer->inicio.QuadPart) / timer->frequencia.QuadPart;

    #elif defined(__linux__) || defined(__APPLE__)

        return (timer->fim.tv_sec - timer->inicio.tv_sec) + (t->fim.tv_nsec - timer->inicio.tvnsec) / 1e9;

    #endif

}