#!/bin/bash

echo "Enter arrival time"
read -a arrival

echo "Enter Burst time"
read -a burst

echo "Enter priority"
read -a priority

echo "Enter time quantum"
read tq


time=0
completed=0
gantt=""
n=${#arrival[@]}

while [ $completed -lt $n ]
do 
    high=0
    index=-1
    for((i=0;i<n;i++)) 
    do
        if [ ${arrival[i]} -le $time ] && [ ${priority[i]} -gt $high ] && [ ${burst[i]} -gt 0 ]; then
            high=${priority[i]}
            index=$i
        fi
    done

    if (( ${burst[$index]} > tq )); then
        (( burst[$index] -= tq ))
        ((time += tq))
    else
        (( time += ${burst[$index]} ))
        burst[$index]=0
        ((completed++))
    fi

    gantt=" $gantt | $index"
done

echo "$gantt"