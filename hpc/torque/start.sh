#!/bin/bash

rm codebreaker.out codebreaker.err

echo "Starting codebreaker..."
qsub -l nodes=2:ppn=40 -M moritz.eckert@fau.de torque.sh > job.id

echo -n "Running..."
ready=0
while [ $ready -eq 0 ];
do
    qstat `cat job.id` > /dev/null 2>&1
    ready=$?
    echo -n '.'
    sleep 1
done

echo ""
echo "Done!"
echo -n "Waiting for results..."

while [ ! -f codebreaker.out ]; do
    echo -n "."
    sleep 1
done

./parse-output.py codebreaker.out codebreaker.found
cat codebreaker.found
