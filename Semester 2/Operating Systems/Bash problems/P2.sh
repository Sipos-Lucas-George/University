#!/bin/bash

if [ $# -lt 3 ]; then
        echo "Wrong input!"
        exit
fi

word=$1
m=$2
n=$3
shift 3

for file in $@; do
        if [[ $(cat $file | sed "${n}q;d" | grep -E ".*$w{$m}") ]]; then
                echo $file
        fi
done