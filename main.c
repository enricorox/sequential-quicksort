#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "quicksort.h"

#define DEBUG

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

#ifdef DEBUG
    printf("Sequence:\n");
    print_seq(seq, size);
#endif

    // sort the sequence
    seq = quick_sort(seq);

#ifdef DEBUG
    printf("Ordered sequence:\n");
    print_seq(seq, size);
#endif

    free(seq);
    return EXIT_SUCCESS;
}
