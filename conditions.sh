#! /bin/bash
#program to show the use of conditional if, elif and else statements

read -p "Enter your age: " age

if ((age < 16)); then
    echo "Sorry, you are too small to drive..."

elif (( ((age > 16)) && ((age < 18)) )); then
    echo "You can drive but with a person at the back..."

else
    echo "Yay!! You can drive..."
fi