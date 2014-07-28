#!/bin/bash
# assignment


#determines the host name
echo "host name is ";
hostname;
hostname > assignment.log;

#determines the OS version and type
echo "OS version and type " 
uname -vm;
uname -vm >> assignment.log;


#gives the full path to home directory
echo "The full path to your home directory" 
$HOME;
$HOME >> assignment.log;

#tells which all users are logged in
echo "logged user ";
who;
who >> assignment.log;

#determines the belonging group
echo "Groups i belong to ";
groups;
groups >> assignment.log;

#gives All files in Home Direcoty Sub directories in Home Direcoty
echo "All files in Home Direcoty Sub directories in Home Direcoty ";
ls -R /home/webonise/;
ls -R /home/webonise/ >> assignment.log;
date >> assignment.log;
