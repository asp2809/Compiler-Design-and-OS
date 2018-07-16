#! /bin/sh
# Shell Program to perform arithmetic operations

#prompting the user for entering two numbers
read -p "Enter first number: " num1
read -p "Enter second number: " num2

echo "The sum of $num1 and $num2 is $((num1+num2))"
echo "The difference of $num1 and $num2 is $((num1-num2))"
echo "The product of $num1 and $num2 is $((num1*num2))"
echo "The division of $num1 and $num2 is $((num1/num2))"