
#include "../../includes/ordenacao.h"

// @bubble_sort
void bubble_sort(int arr[], int n) {

    int i;
    for (i = 0; i < n - 1; i++) {
        
        int trocou = 0; 
        
        int j;
        for (j = 0; j < n - i - 1; j++) {
        
            if (arr[j] > arr[j + 1]) {
        
                trocar(&arr[j], &arr[j + 1]);
                trocou = 1;
        
            }
        
        }
        
        if (trocou == 0) {
            break;
        }
    }

}
