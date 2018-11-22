#!/bin/bash

    for x in 1 2 3 34 5;
    do
        case $x in 
        1) 
            echo "1"
            ;;
        2)
            echo "2"
            ;;
        *) 
            echo "nothing"
            ;;
        esac
    done

exit 0