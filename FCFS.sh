echo "Enter Arrival time"
read -a at

echo "Enter burst time"
read -a bt

count=0
n=${#at[@]}

declare -a finish
declare -a tat
time=0
gantt=""

for ((i=0;i<n;i++)); do
    finish[$i]=0
    tat[$i]=-1
done

while ((count < n)); do
    min=9999
    index=-1
    for((i=0;i<n;i++)); do
        if((at[$i]<min)) && ((finish[$i] != 1)); then
            min=${at[$i]}
            index=$i
        fi
    done

    if ((index == -1)); then
        ((time++))
    else
        ((time+=bt[$index]))
        finish[$index]=1
        tat[$index]=$((time-at[$index]))
        ((count++))
        gantt="$gantt |  P$index"
    fi
done

echo $gantt

for((i=0;i<n;i++)); do
    echo "${tat[$i]}...."
done