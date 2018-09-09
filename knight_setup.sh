#!/bin/bash

#making directory
mkdir knightstour
cd knightstour

#pulling code from git
git init
git pull https://github.com/nathanzhu144/knightstour.git

#makes the code
make
./knightstour_main.exe
