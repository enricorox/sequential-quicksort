//
// Created by enrico on 12/11/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

/**
 * Generate a shuffled sequence of consecutive integers
 * @param size sequence size
 * @return
 */
int * ran_seq(int size){
    int *seq = calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) seq[i] = i;

    for(int i = 0; i < size; i++){
        int k = rand() % size;
        swap(&seq[i], &seq[k]);
    }
    return seq;
}

/**
 * Printing utility
 * @param seq integer array
 * @param size array size
 */
void print_seq(int * seq, int size){
    for(int k = 0; k < size; k++) {
        printf("%4d ", seq[k]);
        if((k+1) % 20 == 0) printf("\n");
    }
    printf("\n");
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
