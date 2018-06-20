#!/bin/bash

if [ $# -lt 3 ]; then
    echo "Usage: $0 <md5|sha256|sha512> <passwd> <salt>"
    exit 1
fi

if [ "$1" = "md5" ]; then
    hash=$(echo -n "$3$2" | md5sum | cut -d' ' -f1)
    echo "1\$$3\$$hash\$"
elif [ "$1" = "sha256" ]; then
    hash=$(echo -n "$3$2" | sha256sum | cut -d' ' -f1)
    echo "5\$$3\$$hash\$"
elif [ "$1" = "sha512" ]; then
    hash=$(echo -n "$3$2" | sha512sum | cut -d' ' -f1)
    echo "6\$$3\$$hash\$"
else
    echo "bla"
    echo "Usage: $0 <md5|sha256|sha512> <passwd> <salt>"
    exit 1
fi
     
