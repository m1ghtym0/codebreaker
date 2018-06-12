#!/bin/bash -l
#
# allocate 20 nodes (168 CPUs) for 6 hours
#PBS -l nodes=2:ppn=40,walltime=01:00:00
#
# job name 
#PBS -N codebreaker_42
#
# stdout and stderr files
#PBS -o codebreaker.out -e codebreaker.err
#
# first non-empty non-comment line ends PBS options

# jobs always start in $HOME -
# change to a temporary job directory on $FASTTMP
mkdir -p ${FASTTMP}/$PBS_JOBID
cd ${FASTTMP}/$PBS_JOBID
# copy input file from location where job was submitted
cp ${PBS_O_WORKDIR}/wordlist .
cp ${PBS_O_WORKDIR}/passlist .

# load moduls
#module load intel64	
#module load openmpi
module load openmpi/2.0.1-intel16.0

# run
mpirun ${HOME}/bin/codebreaker -w wordlist -p passlist

# save output on parallel file system
#mkdir -p ${FASTTMP}/output/$PBS_JOBID
#cp outputfile ${FASTTMP}/output/$PBS_JOBID
cd 
# get rid of the temporary job dir
rm -rf ${FASTTMP}/$PBS_JOBID
# unload module
#module unload intel64
#module unload openmpi
module unload openmpi/2.0.1-intel16.0
