#!/bin/bash


#taskA
mkdir -p targets

mkdir -p targets/C targets/C++ targets/Python targets/Java

temp="unzipped"
rm -rf "$temp"

for file in submissions/*zip
do

    filename=$(basename "$file")
    filename_without_extension="${filename%.zip}"
    id=${filename_without_extension: -7}

    rm -rf "$temp"
    unzip -qq "$file" -d "$temp"

    filetype=$(find "$temp" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.py" -o -name "*.java" \) | head -n 1)

    if [[ $filetype == *.c ]];then
        mkdir -p targets/C/"$id"
        mv "$filetype" "targets/C/$id/main.c"
    elif [[ $filetype == *.cpp ]];then
        mkdir -p targets/C++/"$id"
        mv "$filetype" "targets/C++/$id/main.cpp"
    elif [[ $filetype == *.py ]];then
        mkdir -p targets/Python/"$id"
        mv "$filetype" "targets/Python/$id/main.py"
    elif [[ $filetype == *.java ]];then
        mkdir -p targets/Java/"$id"
        mv "$filetype" "targets/Java/$id/Main.java"
    fi
done

rm -rf "$temp"

#taskB


for file in targets/*/*/[Mm]ain.*
do 

    lines=$(wc -l < "$file")
    dirname=$(basename "$(dirname "$file")")
    comment_count=0

    if [[ "$file" == *.c ]]; then
        comment_count=$(grep -cE '//' "$file")
    elif [[ "$file" == *.cpp ]]; then
        comment_count=$(grep -cE '//' "$file")
    elif [[ "$file" == *.py ]]; then
        comment_count=$(grep -cE '#' "$file")
    elif [[ "$file" == *.java ]]; then
        comment_count=$(grep -cE '//' "$file")
    fi

    echo "$dirname" "$lines" "$comment_count" >> output.csv
    
done 


gcc targets/C/2105221/main.c -o targets/C/2105221/main.out 






# linecount=$(wc -l )

# echo 



























# for z in submissions/*zip
# do 

#     filename=$(basename --"$z")
#     filename_without_extension="${filename%.zip}"

#     id=${filename_without_extension: -7}
#     mkdir
#     unzip "$z" -d "submissions"
# done


# for z in submissions/*zip
# do 
#     rm "$z"
# done


#!/bin/bash

# Make main folders


# Process each zip file
