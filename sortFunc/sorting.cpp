#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
int* beginning, *ending;


#include "sort.h"

int int_comparator(int* a, int* b){
    //printf("Comparison completed\n");
    return *a - *b;
}
define_sort(int)


int main(){
    static const size_t size = 10;
    int arr[size] = {22, 5, 8, 1, 4, 2, 6, 7, 10, 11};
    beginning = &(arr[0]);
    ending = &(arr[0]) + size;
    quick_sort(arr, arr + size, int_comparator);

    for(int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }
}