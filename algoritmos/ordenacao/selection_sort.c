
#include "../../includes/ordenacao.h"

// @selection_sort
void selection_sort(int arr[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
    
        int indice_minimo = i;
    
        for (int j = i + 1; j < n; j++) {
    
            if (arr[j] < arr[indice_minimo]) {
    
                indice_minimo = j;
    
            }
    
        }
        
        trocar(&arr[i], &arr[indice_minimo]);
    
    }
}
