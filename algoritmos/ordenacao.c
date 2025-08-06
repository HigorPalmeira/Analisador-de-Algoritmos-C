#include <stdlib.h>

#include "../includes/ordenacao.h"

void insertion_sort(int array[], int n) {

    for (int i=1; i<n; i++) {
        int k = array[i];
        int j = i - 1;

        while (j >= 0 && k < array[j]) {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = k;
    }

}

int* gerar_array_aleatorio(int n) {
    
    int* array = (int*) malloc(sizeof(int) * n);

    if (!array) return NULL;

    for (int i=0; i<n; i++) {
        array[i] = rand();
    }

    return array;
}