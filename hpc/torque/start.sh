#!/bin/bash

rm codebreaker.out codebreaker.err

echo -n "Starting codebreaker..."
qsub -l nodes=8:ppn=40 -M moritz.eckert@fau.de torque.sh > job.id

stat='Q'
while [ $stat = "Q" ];
do
    stat=`qstat -f | sed -n 4p | sed 's/.\s\+job_state = //'`
    echo -n '.'
    sleep 1
done


echo ""
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
echo ""
cat codebreaker.found

