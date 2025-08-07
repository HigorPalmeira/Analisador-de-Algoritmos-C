
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

void busca_binaria(int array[], int n) {

    int valor = gerar_valor_aleatorio();

    int baixo = 0;
    int alto = n - 1;

    while(baixo <= alto) {

        int meio = baixo + (alto - baixo) / 2;

        if (array[meio] == valor) {
            return;
        }

        if (array[meio] < valor) {
            
            baixo = meio + 1;
        
        } else {
        
            alto = meio - 1;
        
        }

    }

}

int gerar_valor_aleatorio() {
    
    return rand();

}
