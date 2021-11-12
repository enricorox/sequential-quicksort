#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include "utils.h"
#include "quicksort.h"

#define nDEBUG

int main(int argc, char **argv) {
    // parse arguments
    if(argc < 2){
        printf("Usage: %s <size> <seed>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    int seed = time(NULL);

    // set a random seed
    if(argc == 3) seed = atoi(argv[2]);
    srand(seed);

    printf("Going to generate a sequence of size %d\n", size);
    printf("Memory needed: %.3f MB\n", size*sizeof(int)/1000000.0);
    printf("seed = %d\n", seed);

    // generate the sequence
    int * seq = ran_seq(size);

#ifdef DEBUG
    printf("Sequence:\n");
    print_seq(seq, size);
#endif

    MPI_Init(&argc, &argv);
    double t_start = MPI_Wtime();
    // sort the sequence
    quick_sort(seq, 0, size - 1);
    double t_stop = MPI_Wtime();
    MPI_Finalize();

#ifdef DEBUG
    printf("Ordered sequence:\n");
    print_seq(seq, size);
#endif

    printf("T(SequentialQuickSort, %d) = %f seconds\n", size, t_stop - t_start);
    free(seq);
    return EXIT_SUCCESS;
}
