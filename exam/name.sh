#!/bin/bash

read -p "What is your name?" name
echo "Hello $name"

read -p "Enter a number: " num

if((num==10));
then
echo "Pour number equals 10"
fi 

if ((num > 10));then
echo "It is greater than 10"
else
echo "It is less then ten"
fi


read -p "How old are you?" age

if [ $age -ge 16 ] 
then
echo "You can drive"
elif [ $age -eq 15 ]
then
echo "You can drive next year"
else
echo "You can't drive"
fi
