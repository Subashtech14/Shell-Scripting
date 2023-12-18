#!/bin/bash
a=0
while [ "$a" -lt 10 ] # this is Loop
do
  echo "The Count is $a"
  ((a++))
done
