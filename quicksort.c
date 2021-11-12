//
// Created by enrico on 12/11/21.
//

#include <stdbool.h>
#include "quicksort.h"
#include "utils.h"

/**
 * Split arr into two partition such that
 * 1. lower end is less than pivot
 * 2. higher end is greater than pivot
 * @param arr the integer array to be split
 * @param start first element index
 * @param stop last element index
 * @return pivot position
 */
int partition(int *arr, int start, int stop){
    int piv = arr[(int) (start + stop) / 2];

    int left = start;
    int right = stop;

    while(true){
        while((left < stop) && (arr[left] < piv)) left++;
        while((right > start) && (arr[right] > piv)) right--;

        if(left >= right) return right;

        swap(&arr[left], &arr[right]);
    }
}

void quick_sort(int * seq, int start, int stop){
    if((start < stop) && (start >= 0) && (stop >= 0)){
        int pind = partition(seq, start, stop);
        quick_sort(seq, start, pind - 1);
        quick_sort(seq, pind + 1, stop);
    }
}