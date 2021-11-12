#!/bin/bash
## launch 3-job array:
## sbatch -a 1-3 sequential-quick-sort.slurm

#SBATCH --job-name SeqQuickSort
#SBATCH --error err_%j.txt
#SBATCH --output out_%j.txt
#SBATCH --partition allgroups
#SBATCH --ntasks 1
#SBATCH -c 1
#SBATCH --mem 10G
#SBATCH --time 15:00

spack load intel-parallel-studio@professional.2019.4 

##sizes=10E7 10E8 5*10E8 10E9
##seeds=1 2 3 4 5
mpirun -np 1 ./SequentialQuickSort 500000000 "$SLURM_ARRAY_TASK_ID"
