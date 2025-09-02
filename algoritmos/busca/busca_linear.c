
#include "../../includes/busca.h"

// @busca_linear
void busca_linear(int array[], int n) {

    int valor = gerar_valor_aleatorio();

    int i;
    for (i = 0; i < n; i++) {

        if (array[i] == valor) {
            return;
        }

    }

}