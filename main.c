#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int * quick_sort(int * seq){
    return seq;
}

int main(int argc, char **argv) {
    // parse arguments
    if(argc < 2){
        printf("Usage: %s <size>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);

    // set a random seed
    int seed = 123 * size;
    srand(seed);

    // generate the sequence
    int * seq = ran_seq(size);
    printf("Sequence:\n");
    print_seq(seq, size);

    // sort the sequence
    seq = quick_sort(seq);
    printf("Ordered sequence:\n");
    print_seq(seq, size);

    free(seq);
    return EXIT_SUCCESS;
}
