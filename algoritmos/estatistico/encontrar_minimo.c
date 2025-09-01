
#include "../../includes/estatistico.h"

// @encontrar_minimo
void encontrar_minimo(int array[], int n) {

    if (n <= 0) return;

    int minimo = array[0];

    for (int i=1; i<n; i++) {

        if (array[i] < minimo) {

            minimo = array[i];

        }

    }

}