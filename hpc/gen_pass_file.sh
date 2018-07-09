#!/bin/bash

if [ $# -lt 4 ]; then
    echo "Usage: $0 <wordlist> <count> <algo> <outfile>"
    exit 1
fi

MYDIR="$(dirname "$(realpath "$0")")"

cat "$1" | shuf | head -n "$2" |
while read p; do
    echo "$p"
    $MYDIR/mkpasswd.sh "$3" "$p" "SALT" >> "$4"
done 
