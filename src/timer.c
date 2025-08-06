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