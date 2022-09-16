#!/bin/bash

for file in $@; do
        echo $file
        echo "`cat $file | tr ' ' '\n' | sort | uniq -c | awk -v total=0 '$2%2==0 {total+=1} END{{print total}}'`"
done