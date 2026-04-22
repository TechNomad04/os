echo "Enter Arrival time"
read -a at

echo "Enter Burst Time"
read -a bt

declare -a rt
n=${#at[@]}

for((i=0;i<n;i++)); do
    rt[$i]=${bt[$i]}
done

time=0
gantt=""

count=0
while ((count < n)); do
    min=9999
    index=-1
    for((i=0;i<n;i++)); do
        if ((at[$i] <= time)) && ((rt[$i] < min)) && ((rt[$i] > 0)); then
            min=${rt[$i]}
            index=$i
        fi
    done

    if ((index != -1)); then
        gantt="$gantt | P$index"
        rt[$index]=$((rt[$index]-1))
        ((time++))
        if ((rt[$index] == 0)); then
            ((count++))
        fi
    else
        ((time++))
    fi
done

echo $gantt