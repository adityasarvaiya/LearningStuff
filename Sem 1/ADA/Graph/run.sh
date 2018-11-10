#!/bin/bash

g++ transitive_closer.cpp -o tc
# g++ -g transitive_closer.cpp -o tc

if [ "$1" == "r" ]
then 
    # gdb tc
    ./tc < "test.in"
fi