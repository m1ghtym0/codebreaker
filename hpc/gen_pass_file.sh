#!/bin/bash

if [ $# -lt 4 ]; then
    echo "Usage: $0 <wordlist> <count> <algo> <outfile>"
    exit 1
fi

cat "$1" | shuf | head -n "$2" |
while read p; do
    echo "$p"
    ./mkpasswd.sh "$3" "$p.9" "EVAL" >> "$4"
done 
