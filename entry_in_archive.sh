#!/bin/bash

argc=$#
libft=../../libft.a
contents=$(ar -t $libft)
all_found=1
for arg in "$@"
do
	extract_result=$(echo "$contents" | grep -w $arg | wc -l)
	if [[ $extract_result -eq 0 ]]; then
		all_found=0
		break
	fi
done

echo "$all_found"