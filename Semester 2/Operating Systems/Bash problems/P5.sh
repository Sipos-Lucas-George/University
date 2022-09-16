#!/bin/bash

if [ $# -lt 2 ]; then
        echo "Wrong input!"
        exit
fi

file1=$1
file2=$2
shift 2
file11=""
file22=""
users=`cat /etc/passwd | awk -F: '{print $1}'`
for arg in $@; do
        if [[ "$users" == *"$arg"* ]]; then
                echo 1
                file11="$file11 `cat /etc/passwd | grep -x "$arg.*"`"
        else
                echo 2
                file22="$file22 $arg"
        fi
done
echo $file1
echo "`echo ${file11} | tr ' ' '\n'`"
echo
echo $file2
echo "`echo ${file22} | tr ' ' '\n'`"