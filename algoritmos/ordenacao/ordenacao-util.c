
#include <stdlib.h>

#include "../../includes/ordenacao.h"

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* gerar_array_aleatorio(int n) {
    
    int* array = (int*) malloc(sizeof(int) * n);

    if (!array) return NULL;

    int i;
    for (i = 0; i < n; i++) {
        array[i] = rand();
    }

    return array;
}
