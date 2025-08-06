#ifndef TIMER_H
    #define TIMER_H

    typedef struct Timer Timer;

    Timer* criar_timer();

    void iniciar_timer(Timer* timer);

    void parar_timer(Timer* timer);

    double tempo_timer_segundos(Timer* timer);

    double tempo_timer_milisegundos(Timer* timer);

    void limpar_timer(Timer* t);

#endif