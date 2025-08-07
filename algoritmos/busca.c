
#include <stdlib.h>

#include "../includes/busca.h"

void busca_linear(int array[], int n) {

    int valor = gerar_valor_aleatorio();

    for (int i=0; i<n; i++) {

        if (array[i] == valor) {
            return;
        }

    }

}

int gerar_valor_aleatorio() {
    
    return rand();

}
