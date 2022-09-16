#!/bin/bash

count=0

for file in $(find $1 '*.c'); do
        count+=1
done

echo $count