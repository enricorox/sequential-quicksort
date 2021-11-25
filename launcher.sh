#!/bin/bash
jobs=$(ls job*.slurm)

for job in $jobs
do
  sbatch -a 1-5 "$job"
done