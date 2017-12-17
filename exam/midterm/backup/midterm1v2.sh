#!/bin/bash

if [ $# -lt 1 ];
then
exit
fi

#for var in "$@"
while [ $# -gt 0 ];
do
  for f in $(ls $1)
  do
    cp $f ./backup
  done
  shift
done
exit
