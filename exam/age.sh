#!/bin/sh

echo "How old are you?"
read age
x=$(expr $age \* 365)

echo "You are $x days old!"
