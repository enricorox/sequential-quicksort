#!/bin/bash

#SBATCH --job-name SequentialQuickSort
#SBATCH --error SequentialQuickSort_err_%j.txt
#SBATCH --output SequentialQuickSort_out_%j.txt
#SBATCH --partition allgroups
#SBATCH --ntasks 1
#SBATCH -c 1
#SBATCH --mem 1G
#SBATCH --time 0:30

spack load intel-parallel-studio@professional.2019.4 

## sizes: 10^4 10^5 10^6 10^7 10^8 10^9
## seeds: 1 2 3 4 5
srun ./SequentianQuickSort 10000 1

