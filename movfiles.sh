#!/bin/bash
#Program to move files if the directory is present otherwise the directory is created with the name which is passed as a command-line argument, but if there is a file in the pwd with the same name then program is exitted

size="+$2c"
fName="$1.*"

if [ -f $1 ];
then
    echo "File Present with the name $1"
    exit 0
elif [ -d $1 ];
then
    echo "Directory is Present"
else
    echo "Directory Missing, Creating One with the name $1"
    mkdir $1
fi

find . -type f -size $size |
while read x
do
    mv $x $1
done