#!/bin/bash
# Spawns $1 instances of the program $2


A=$1

B=$2


instances1=1
instances2=4

program="./perfect_numbers"
D=$B-$A
D=($B-$A)/$instances1

for i in `seq 1 $instances1`

do



A2=$(($A+$D*$(($i-1))))
B2=$(($A+$D*$(($i))))

$program  $A2  $B2 &

done

wait 


D=$B-$A
D=($B-$A)/$instances2


for i in `seq 1 $instances2`

do


A2=$(($A+$D*$(($i-1))))
B2=$(($A+$D*$(($i))))

$program  $A2  $B2 &

done

wait 



T1=$(TIMEFORMAT='%R';time(

D=$B-$A
D=($B-$A)/$instances1



for i in `seq 1 $instances1`

do


A2=$(($A+$D*$(($i-1))))
B2=$(($A+$D*$(($i))))

$program  $A2  $B2 &

done

wait 
)2>&1 1>/dev/null )




T4=$(TIMEFORMAT='%R';time(

D=$B-$A
D=($B-$A)/$instances2


for i in `seq 1 $instances2`

do

A2=$(($A+$D*$(($i-1))))
B2=$(($A+$D*$(($i))))

$program  $A2  $B2 &

done

wait 
)2>&1 1>/dev/null )

T1=$(echo $T1 | awk -F, '{print($1*10000+$2*1000)}')
T4=$(echo $T4 | awk -F, '{print($1*10000+$2*1000)}')


SPD=$(echo "scale = 10; $T1/$T4" | bc)
EFI=$(echo "scale = 10; $SPD/4.0" | bc)
echo T1:$T1,T4:$T4
echo speedup:$SPD,eff:$EFI

#7. for 4 processors instead of a sppedup 0f 4 we get a spped-up of 2, the cause may be I/O acces and the few commands which were not in parallel
#which makes the entire problem to not be in parallel











