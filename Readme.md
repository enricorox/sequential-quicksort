# Sequential Quick Sort algorithm for Parallel Computing @ Padova

## Requirements
1. Install MPI: `sudo apt install libcr-dev mpich mpich-doc`

## How to compile
1. `cmake .`
2. `make`

## How to run
* On your PC: `mpirun -np <num-process> ./SerialQuickSort <size> <seed>`
* On CAPRI HPC: `sbatch sequential-quick-sort.slurm`
