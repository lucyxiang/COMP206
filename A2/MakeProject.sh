#!/bin/sh

cd ~/
if [ ! -d "project" ];
then
mkdir -p project
fi

cd project

if [ ! -d "cs206" ];
then
mkdir -p cs206
fi

cd cs206

if [ -d $1 ];
then
    echo "This project name has already been used."
    exit
else

mkdir -p $1/{archive,backup,docs,assets,database,source}
cd $1/source

cat > backup.sh <<- E0F
#!/bin/bash
cp *.[ch] ../backup
E0F

echo "You project directories have been created."
fi
