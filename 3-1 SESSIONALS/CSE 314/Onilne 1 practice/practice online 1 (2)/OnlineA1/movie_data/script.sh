#!/bin/bash

> dir.txt

find . -type f -name "*.txt" | while read filepath; do

    director_name=$( tail -n 2 "$filepath" | head -n 1 )


        


    #echo $director_name >> dir.txt

    mkdir -p "$director_name"
    mv "$filepath" "$director_name/"

    

done
