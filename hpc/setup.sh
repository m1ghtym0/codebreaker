#!/bin/bash

if [[ $# < 2 ]]; then
    echo "Usage: $0 wordlist passlist"
    exit 1
fi

./ssh/upload-bin.sh
scp -r torque/* emmy-frontend:
scp "$1" emmy-frontend:
scp "$2" emmy-frontend:

