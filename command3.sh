#!/bin/bash
# assignment

for file in x*.txt ; do  mv "$file" "newname$file"; done;
ls *.txt;
ls *.txt >> assignment.log;
date >> assignment.log;
