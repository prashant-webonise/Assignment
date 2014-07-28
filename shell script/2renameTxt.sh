#!/bin/bash
# assignment


#renames the all files with extension .txt inside the directory and list them on console
for file in *.txt ; do  mv "$file" "x$file"; done;
ls *.txt;
ls *.txt >> assignment.log;
date >> assignment.log;
