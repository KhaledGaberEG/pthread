#!/bin/bash
diff=0
equ=0

trials=0
echo -n "[+] How Many trials you want to make: "
read trials


for (( c=1; c<=$trials; c++ ))
do  
   echo "...Trail $c..."
   output=$(./prog2)
   v1=$(sed -n 1p <<< "$output")
   v2=$(sed -n 2p <<< "$output")
   # Dont change this following 2 line they extrace output from program 
   # so they depend on exact position in the output
   v1="${v1:67}"
   v2="${v2:67}"
   echo "  [+] with locking:    $v1"
   echo "  [+] without locking: $v2"
   if [ "$v1" == "$v2" ]
    then
        ((equ=equ+1))
    else
        ((diff=diff+1))
    fi
    echo "...Done..."
done

echo "=================================="
echo "[+] Outputs differ in $diff Runs"
echo "[+] Output matches in $equ Runs"