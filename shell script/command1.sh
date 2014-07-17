#!/bin/bash
# assignment

echo "host name is ";
hostname;
hostname > assignment.log;
echo "OS version and type " 
uname -vm;
uname -vm >> assignment.log;

echo "The full path to your home directory" 
$HOME;
$HOME >> assignment.log;

echo "logged user ";
who;
who >> assignment.log;
echo "Groups i belong to ";
groups;
groups >> assignment.log;
echo "All files in Home Direcoty Sub directories in Home Direcoty ";
#ls -R /home/webonise/;
ls -R /home/webonise/ >> assignment.log;
date >> assignment.log;
