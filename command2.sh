#!/bin/bash
# assignment

for file in *.txt ; do  mv "$file" "x$file"; done;
ls *.txt;
ls *.txt >> assignment.log;
date >> assignment.log;
