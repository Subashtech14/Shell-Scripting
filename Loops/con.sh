#!/bin/bash

for i in {1..5}
do
    if [ $i -eq 3 ]; then
        continue  # skip the code below and move to the next iteration when i is 3
    fi
    echo "Iteration $i"
done
