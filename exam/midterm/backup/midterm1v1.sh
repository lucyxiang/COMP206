#!/bin/bash

if [ $# -lt 2 ];
then
  echo "Need minimum 2 arguments"
  exit 1
fi

if ! [ -d $1 ];
then
  mkdir $1
fi

backup=$1
shift

while [ $# -gt 0 ]
do
  if [ $1 != *.out ]
  then
    cp $1 ./backup
  fi
  shift
done
