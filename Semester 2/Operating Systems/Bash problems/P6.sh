#!/bin/bash

if [ $# -lt 2 ]; then
        echo "Wrong input!"
        exit
fi

n=$1
w=$2
shift 2

for file in $@; do
        echo $file
        m=`cat $file | sed "${n}q;d" | grep -E ".*${w}.*"`
        if [[ $m ]]; then
                echo "$m"
        fi
done