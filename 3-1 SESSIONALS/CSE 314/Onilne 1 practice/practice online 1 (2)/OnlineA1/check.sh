#!/bin/bash

find . -type f -name "*.txt" | while read filepath; do

    # lineread1=$( head -n 1 "$filepath")
    # echo "$lineread1"
    # lineread2=$( head -n 4 "$filepath")
    # echo "$lineread2"

    lineread=$( tail -n 2 "$filepath")
    lineread2=$( tail -n 4 "$filepath" | head -n 2)
    echo "$lineread"
    echo "$lineread2"
done