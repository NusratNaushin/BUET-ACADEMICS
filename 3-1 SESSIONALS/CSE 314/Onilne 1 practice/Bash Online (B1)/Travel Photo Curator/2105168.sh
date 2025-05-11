#!/bin/bash

> out.txt
> time.txt
mkdir -p "photus"
mkdir -p "photus/morning" "photus/afternoon" "photus/evening"

morn=0
aft=0
evn=0
for file in files/photos_input/*.jpg
do
    filename_without_start="${file##*/}"
    echo "$filename_without_start" >> out.txt

    #-5:2 kata lagbe re

    timing="${filename_without_start: -10:2}"
    echo "$timing" >> time.txt
    
    timing=$((10#$timing))

    if [[ $timing -ge 0 && $timing -le 11 ]]; then
        cp $file "photus/morning/morning_$filename_without_start"
        morn=$((morn + 1))
    elif [[ $timing -ge 12 && $timing -le 17 ]]; then
        cp $file "photus/afternoon/afternoon_$filename_without_start"
        aft=$((aft + 1))
    elif [[ $timing -ge 18 && $timing -le 23 ]]; then
        cp $file "photus/evening/evening_$filename_without_start"  
        evn=$((evn + 1))  
    fi
    
  
done


echo $morn >> photus/cnt.txt
echo $aft >> photus/cnt.txt
echo $evn >> photus/cnt.txt
