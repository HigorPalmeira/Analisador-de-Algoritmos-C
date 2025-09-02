#include <stdlib.h>
#include <locale.h>

#include "../includes/configuracao.h"

void setConsole() {

    setlocale(LC_ALL, LOCALE);

    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

}