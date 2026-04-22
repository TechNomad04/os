#!/bin/bash

echo "--- Banker's Algorithm: Deadlock Avoidance ---"

read -p "Enter number of processes: " P
read -p "Enter number of resources: " R

declare -a max
declare -a alloc
declare -a need
declare -a avail
declare -a finish
declare -a safe_seq

echo "Enter Maximum Resource Matrix:"
for ((i=0;i<P;i++)); do
    read -a row
    for((j=0;j<R;j++)); do
        max[$((i*R + j))]=${row[$j]}
    done
done

echo "Enter Allocation Matrix"
for ((i=0;i<P;i++)); do
    read -a row
    for((j=0;j<R;j++)); do
        alloc[$((i*R + j))]=${row[$j]}
    done
done

echo "Enter Available Resources:"
read -a avail

for ((i=0;i<P;i++)); do
    for ((j=0;j<R;j++)); do
        need[$((i*R + j))]=$((max[$((i*R+j))]-alloc[$((i*R+j))]))
    done
done

for ((i=0;i<P;i++)); do
    finish[$i]=0
done

count=0

while ((count < P)); do
    found=0

    for ((i=0;i<P;i++)); do
        if((finish[$i] == 0)); then
            possible=1
            for ((j=0;j<R;j++)); do
                if (( need[$((i*R+j))] > avail[$j])); then
                    possible=0
                    break;
                fi
            done

            if ((possible == 1)); then
                for((j=0;j<R;j++)); do
                    avail[$j]=$((avail[$j]+alloc[$((i*R+j))]))
                done

                finish[$i]=1
                safe_seq+=("P$i")
                found=1

                ((count++))
                break
            fi
        fi
    done

    if((found == 0)); then
    break
    fi
done

echo "---------------------------------------"

if ((count == P)); then
    echo "System is in a SAFE state."
    echo -n "Safe sequence: "
    for ((i=0;i<P;i++)); do
        echo -n "${safe_seq[$i]}"
        if ((i < P-1)); then echo -n " -> "; fi
    done
    echo
else
    echo "System is NOT in a safe state (Deadlock risk)."
fi

echo "---------------------------------------"