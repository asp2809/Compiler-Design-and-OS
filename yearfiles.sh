#! /bin/bash
#program to list all the files created in the path in that specified year

if [ -d $1 ];
then
    cd $1
    find . -type f -newermt "$2-01-01" ! -newermt "$2-12-31"
else
    echo "Directory Not Found!!"
fi