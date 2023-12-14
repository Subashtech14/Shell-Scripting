#!/bin/bash
a=10
b=20
if [ $a = $b ]
then
    echo "Both are equal"
elif [ $a -gt $b ]
then
    echo "A is Greater than B"
else
    echo "B is Greater than A"
fi
