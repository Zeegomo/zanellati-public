#!/bin/bash

BUILDSETTINGS="`python3.7m-config --ldflags` "

echo "Compiling:"

#for file in $*; do
#	BUILDSETTINGS=${BUILDSETTINGS}" "${file}
#	echo $file
#done


g++ $* ${BUILDSETTINGS} && echo "OK" || echo "Something went wrong"

