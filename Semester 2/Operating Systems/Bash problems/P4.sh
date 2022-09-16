#!/bin/bash

if [ $# -lt 1 ]; then
        echo "Wrong input!"
        exit
fi

num=$1
lib=""
shift

for file in $@; do
        lib="$lib `grep -x -E "#include <.*>" $file | sed 's/#include <//g' | sed 's/>//g'`"
done

echo "`echo $lib | tr ' ' '\n' | sort | uniq -c | sort -nr | head -n $num`"