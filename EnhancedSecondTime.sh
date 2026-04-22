#!/bin/bash

echo "--- Enhanced Second Chance Page Replacement ---"

read -p "Enter number of frames: " f
read -p "Enter number of pages: " n

echo "Enter page reference string:"
read -a pages

echo "Enter modify bits (0 or 1 for each page):"
read -a mod

declare -a frame
declare -a R
declare -a M

pointer=0
faults=0

# Initialize frames
for ((i=0;i<f;i++)); do
    frame[$i]=-1
    R[$i]=0
    M[$i]=0
done

