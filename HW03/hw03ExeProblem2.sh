#!/bin/bash
#checks for one argument
if [ "$#" != 1 ]; then
    echo "Usage: $0 PATH"
    exit 1
fi
# checking if path is valid
if [ ! -e "$1" ]; then
    echo "$1 is not a valid path"
    exit 2
fi

# check if its a file
if [ -f "$1" ]; then
    my_item="$1"
    echo `source get-storage.sh`
    exit 0
fi

# check if its a directory and sum the sizes of all items in the directory
if [ -d "$1" ]; then
    my_item="$1"
    total_size=0
    for item in `ls -A $my_item`; do
        total_size=$((total_size + $(subtree-storage.sh $my_item/$item)))
    done
    echo $total_size
    exit 0
fi