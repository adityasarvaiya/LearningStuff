#!/bin/bash

	for x in `ls`; do
		if [ $x == "aap_shell_02.sh" ]; then
			exit 199
		fi
		echo $x
	done

exit 0

