#!/bin/bash

for i in {1..5}
do
    echo "Iteration $i"
    if [ $i -eq 3 ]; then
        break  # exit the loop when i is 3
    fi
done
