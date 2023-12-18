#!/bin/bash
#File Operations
read -p "Enter the File name to Check ? " a
if [ -e $a ]
then 
    echo "File exists"
else
   touch "$a.txt"
   ls "."
fi
