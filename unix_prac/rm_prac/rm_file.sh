#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Usage $0 `basename`"
	exit 1
fi

for file in $1.*
do
	rm -f $file
done

exit 0
