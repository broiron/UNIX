#!/bin/bash

let sum=0;

for i in "$@"
do
    if [ -e $i ]
    then
	pwd=`stat -c %s $i`
	let sum=$pwd+$sum
	echo "$i $pwd"
    else
	echo "No such file or directory"
	exit 1
    fi
done

echo $sum

exit 0
