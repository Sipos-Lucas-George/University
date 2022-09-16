#!/bin/bash
echo $@ $#
for A in $@; do
        if [ -d $A ]; then
                echo "$A is a directory"
        elif [ -f $A ]; then
                echo "$A is a file"
        elif echo $A | grep -E -q "^-?[0-9]+$"; then
                echo "$A is a number"
        else
                echo "$A is neither of them"
        fi
done