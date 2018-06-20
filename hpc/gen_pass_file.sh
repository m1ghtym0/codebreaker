#!/bin/bash

if [ $# -lt 4 ]; then
    echo "Usage: $0 <wordlist> <count> <algo> <outfile>"
    exit 1
fi

head -"$2" "$1" |
while read p; do
   ./mkpasswd.sh "$3" "$p" "GENENERATED" >> "$4"
done 
