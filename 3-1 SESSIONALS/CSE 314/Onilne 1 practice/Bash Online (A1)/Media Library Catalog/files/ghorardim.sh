#!/bin/bash
> out.txt
> filename_befor_hyphen.txt
> filename_after_hyphen.txt
> artist.txt
> title.txt
> unknown.txt
> final.txt
catalog=$1

declare -A catalog
for file in media/*.*
do 
    filename=$(basename "$file")
    filename_without_extension="${filename%.*}"

    echo "$filename_without_extension" >> out.txt
    


    filename_before_hyphen="${filename_without_extension%-*}"
    filename_after_hyphen="${filename_without_extension##*-}"
    filename_after_hyphen=$(echo "$filename_after_hyphen"| xargs -0)
    echo "$filename_before_hyphen" >> filename_befor_hyphen.txt
    echo "$filename_after_hyphen" >> filename_after_hyphen.txt


    filename_before_bracket="${filename_before_hyphen:(-2):1}"

    if [[ $filename_before_bracket != ")" ]]; then
        artist="$filename_before_hyphen"
        title="$filename_after_hyphen"
        echo "$filename_before_hyphen" >> artist.txt
    elif [[ $filename_before_bracket == ")" ]]; then
        title="$filename_before_hyphen"
        artist="$filename_after_hyphen"
        echo "$filename_before_hyphen" >> title.txt
    elif [[ -z $filename_befor_hyphen || -z $filename_after_hyphen ]]; then
        echo "$filename_before_hyphen" >> unknown.txt
    
    fi


    if [[ -z "${catalog[$artist]}" ]]; then
        catalog[$artist]="$title"
    else
        catalog[$artist]="${catalog[$artist]} $title"
    fi

    echo "$artist" >> final.txt
    echo "$title" >> final.txt
    

done
# for artist in $(echo "${!catalog[@]}" | sort); do
#     echo "$artist" >> final.txt
#     for title in $(echo "${catalog[$artist]}" | tr ' ' '\n' | sort); do
#         echo "$title" >> final.txt
#     done
# done



    


