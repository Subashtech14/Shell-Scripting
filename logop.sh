#!/bin/sh
read -p "Enter a : " a
read -p "Enter b : " b
if [ "$a" = "true" ] && [ "$b" = "true" ]
then
     echo "Both are true"
else
     echo "Both are False"
fi
