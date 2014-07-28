#!/bin/bash
# assignment

#renames the all files whose name starts with letter "x" inside the directory and list them on console
for file in x*.txt ; do  mv "$file" "newname$file"; done;
ls *.txt;
