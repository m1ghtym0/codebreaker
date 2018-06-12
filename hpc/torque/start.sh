#!/bin/bash

qsub -l nodes=2:ppn=40 -M moritz.eckert@fau.de torque.sh
