#!/bin/bash

echo $#
echo "hello"
if [ $# -lt 1 ];
then
  echo "Need minimum 2 arguments"
  exit 1
fi

if [ -d ! $1 ];
then
  mkdir $1
fi

backup=$1
for var in $@
do
files = `ls $var`
for f in files
if [ $f != '*.out' ]
cp $f ./backup
fi

done
done
