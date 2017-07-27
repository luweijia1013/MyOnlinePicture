#!/bin/bash

read -p "Input your name:  " USERNAME
#echo $USERNAME
USERLIST=$(cut -d: -f1 /etc/passwd)
#echo $USERLIST
echo $USERLIST | grep -w "$USERNAME$" > /dev/null

if [ $? -eq 0 ]
then
    echo "exist"
else
    echo "not exits"
fi

