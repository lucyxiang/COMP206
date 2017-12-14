#/bin/bash

str1=""
str2="sad"
str3="happy"

if [ "$str1" ]; then
echo "$str1 has no value"
fi

if [ -z "str1" ]; then
echo "str1 has no value"
fi

if [ "$str1" == "str$3" ]; then
echo "str2 equals str3" 
fi

if [ "$str2 > $str3" ]; then
echo "str2 greater than str3"
else
echo "str2 not greater than str3"
fi
