#!/bin/bash

> file.txt
> city.txt
> fullfile.txt
> part.txt
> cat.txt
> hey.txt
> dekhadekhi.txt
heist=$1

declare -A cat_count

mkdir -p "blueprints"
for file in $heist/*/*.dat
do 

    echo $file >> fullfile.txt
    basefile=$(basename $file)
    basefile_without_extension="${basefile%.dat}"
    category=${basefile_without_extension##*_}
    part_no=${basefile:5:2}

   
    cityname=${file%/*}
    city=$(basename $cityname)
   
    hesitname=${file%%/*}

    

    cp $file "blueprints/${city}_Part_${part_no}_${category}.dat"

    if (( 10#$part_no%2 == 0 )); then
        ((cat_count[$category]++))
    fi





    
  # cp $file "$heist/blueprints/"
    dekhi=${file##*/}
    echo $dekhi >> dekhadekhi.txt
    echo $part_no >> part.txt
    echo $category >> cat.txt
    echo $cityname >> file.txt
    echo $city >> city.txt
    echo $hesitname >> hey.txt


done


for category in "${!cat_count[@]}"
do

    echo "$category: ${cat_count[$category]}"

done | sort > "blueprints/summary.txt"

