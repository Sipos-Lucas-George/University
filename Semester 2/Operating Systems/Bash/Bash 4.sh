#!/bin/bash

D=$1
if [ -z $D ]; then
        echo "ERROR!!! Argument was not sent"
        exit 1
fi
if [ ! -d $D ]; then
        echo "ERROR!!! This is not a directory"
        exit 1
fi

PS=""
while true; do
        S=""
        for F in `find $D`; do
                if [ -f $F ]; then
                        PROPERTIES=`ls -l $F | sha1sum`
                        CONTENT=`cat $F | sha1sum`
                elif [ -d $F ]; then
                        PROPERTIES=`ls -l -d $F | sha1sum`
                        CONTENT=`ls -l $F | sha1sum`
                fi
                S="$S\n$PROPERTIES $CONTENT"
        done
        if [ -n $PS ] && [ "$PS" != "$S" ]; then
                echo "Some change occurred"
        fi
        PS=$S
        sleep 1
done