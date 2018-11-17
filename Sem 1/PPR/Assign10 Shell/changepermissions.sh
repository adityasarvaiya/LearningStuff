#!/bin/bash

    x=1

    for x in `ls`; do
        chmod 777 $x
    done

exit 0

