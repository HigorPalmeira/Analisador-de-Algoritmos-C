
#include "../../includes/busca.h"

// @busca_linear
void busca_linear(int array[], int n) {

    int valor = gerar_valor_aleatorio();

    for (int i=0; i<n; i++) {

        if (array[i] == valor) {
            return;
        }

    }

}