#include <stdlib.h>

void encontrar_maximo(int array[], int n) {

    if (n <= 0) return;

    int maximo = array[0];

    for (int i=1; i<n; i++) {

        if (array[i] > maximo) {
            
            maximo = array[i];
        
        }

    }

}