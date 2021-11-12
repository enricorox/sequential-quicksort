#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "quicksort.h"
#include <mpi/mpi.h>

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
    double t_start = MPI_Wtime();
    // sort the sequence
    quick_sort(seq, 0, size - 1);
    double t_stop = MPI_Wtime();

#ifdef DEBUG
    printf("Ordered sequence:\n");
    print_seq(seq, size);
#endif
    printf("T(SequentialQuickSort) = %f\n", t_stop - t_start);
    free(seq);
    return EXIT_SUCCESS;
}
