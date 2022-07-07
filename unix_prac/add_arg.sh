#!/bin/bash

function add(){

    num=1
    result=1
    while [ $num -ne $1 ]
    do
	let num=$num+1
	let result=$num+$result
    done
    echo result: $result
}

add $1
