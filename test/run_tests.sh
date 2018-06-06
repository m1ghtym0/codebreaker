#!/bin/bash

set -v
make build

for d in ./*/;
do
    cd $d;
    ./run.sh;
    cd ..;
done;

