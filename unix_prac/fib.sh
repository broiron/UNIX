#!/bin/bash

function fib(){

    value=""
    n=$1
    x=0;y=1;i=2
    echo "--------------"
    while [ $i -lt $n ]
    do
	let i=$i+1
	let z=$x+$y
	x=$y; y=$z
    done
    value=$z
    	}

fib $1
echo "result=$value"
