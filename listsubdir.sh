#! /bin/sh
# program to list all the subdirectories under a path

if [ -d $1 ];
then
    cd $1
    ls -l

else
    echo "Sorry, directory not found!!"
fi