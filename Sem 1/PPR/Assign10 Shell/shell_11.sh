#!/bin/bash

sum()
{
	x=$1
	y=$2

	return $(($x + $y))
}

function adds
{
	x=$1
	y=$2

	return $(( $x - $y ))
}
	sum 7 5
	z=$?
	echo "7+5 = $z"

	adds 7 5
	echo "7-5 = $?"

exit 0

