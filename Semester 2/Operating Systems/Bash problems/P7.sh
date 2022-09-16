#!/bin/bash

n=$1
shift

for file in $@; do
        echo $file
        echo "`cat $file | tr ' ' '\n' | sort | uniq -c | sort -nr | awk -v nr="$n" '$1 > nr {print $2}'`"
done