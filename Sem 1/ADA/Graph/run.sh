#!/bin/bash

# g++ -g transitive_closer.cpp -o tc
# g++ transitive_closer.cpp -o tc
g++ loop_detection.cpp -o tc


if [ "$1" == "r" ]
then 
    # gdb tc
    ./tc < "test.in"
fi