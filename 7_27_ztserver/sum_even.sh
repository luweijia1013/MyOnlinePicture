#!/bin/bash

let "sum = 0"
for i in $(seq 1 100)
do
    let "part = i%2 "
    if [ "$part" -eq  0 ]
    then
        let "sum = sum + i"
    fi
done
echo  "the sum is: "$sum

