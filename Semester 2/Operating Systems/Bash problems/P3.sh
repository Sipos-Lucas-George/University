#!/bin/bash

if [ $# -lt 1 ]; then
        echo "Wrong input!"
        exit
fi
word=$1
shift
for file in $@; do
        echo $file
        echo $( grep -o -w $word $file | wc -l )
done