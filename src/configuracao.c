#include <stdlib.h>
#include <locale.h>


void setConsole() {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

}