#include <stdlib.h>

#include "../includes/ordenacao.h"

/*
    Algoritmo de ordenação Insertion Sort, utilizado como exemplo para medir seu tempo de execução.
*/
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

void bubble_sort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        
        int trocou = 0; 
        
        for (int j = 0; j < n - i - 1; j++) {
        
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

/* 
    Gera um array com valores aleatórios, com tamanho de n entradas.

    @param n Tamanho do vetor.
    @return array com tamanho de n.
*/
int* gerar_array_aleatorio(int n) {
    
    int* array = (int*) malloc(sizeof(int) * n);

    if (!array) return NULL;

    for (int i=0; i<n; i++) {
        array[i] = rand();
    }

    return array;
}