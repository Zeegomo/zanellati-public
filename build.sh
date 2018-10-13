#!/bin/bash

BUILDSETTINGS="g++ `python-config --ldflags` "$*

echo "Compiling:"

#for file in $*; do
#	BUILDSETTINGS=${BUILDSETTINGS}" "${file}
#	echo $file
#done


${BUILDSETTINGS} && echo "OK" || echo "Something went wrong"

