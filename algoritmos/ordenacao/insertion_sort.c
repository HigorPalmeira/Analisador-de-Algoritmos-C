
#include "../../includes/ordenacao.h"

// @insertion_sort
void insertion_sort(int array[], int n) {

    int i;
    for (i = 1; i < n; i++) {
        int k = array[i];
        int j = i - 1;

        while (j >= 0 && k < array[j]) {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = k;
    }

}