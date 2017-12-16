#!/bin/bash

name=$1
cd ~
if [ -d "project" ]; 
then
	echo "Project already exists"
	cd ./project
else
	mkdir project
	cd ./project
fi

if [ -d "cs206" ];
then
	echo "cs206 already exists"
	cd ./cs206
else
	mkdir cs206
	cd ./cs206
fi

if [ -d "$name" ];
then
	echo "This project has already been use"
	exit 1
else
	mkdir $name
	cd ./$name
	mkdir archive
	mkdir backup
	mkdir docs
	mkdir assets
	mkdir database
	mkdir source
	cd ./source

	touch backup.sh
	echo "cp ./*.[ch] ../backup" >> backup.sh
	chmod +x backup.sh

	echo "Your project directories have been created"
fi

