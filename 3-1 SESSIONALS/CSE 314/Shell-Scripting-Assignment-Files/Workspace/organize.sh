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



for file in targets/*/*/[Mm]ain.*
do 

    filepath="$file"

    folderpath=$(dirname "$file")

    if [[ "$file" == *.c ]]; then
        gcc "$filepath" -o "$folderpath/main.out"
    elif [[ "$file" == *.cpp ]]; then
        g++ "$filepath" -o "$folderpath/main.out"
    elif [[ "$file" == *.java ]]; then
        javac "$filepath" -d "$folderpath"
    fi    
done 

for file in targets/*/*/[Mm]ain.*
do 

    
    filepath="$file"

    folderpath=$(dirname "$file")
    
    if [[ "$file" == *.c ]]; then
        count=1;
        for testcase in tests/*
        do
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            ./"$folderpath/main.out" < "$testcase" > "$outputfile"
            fi
            ((count++))

        done
    elif [[ "$file" == *.cpp ]]; then
        count=1;
        for testcase in tests/*
        do
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            ./"$folderpath/main.out" < "$testcase" > "$outputfile"
            fi
            ((count++))
        done
    elif [[ "$file" == *.java ]]; then
        count=1
        for testcase in tests/*
        do
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            java -cp "$folderpath" Main < "$testcase" > "$outputfile"
            fi
            ((count++))
        done
    elif [[ "$file" == *.py ]]; then
        count=1
        for testcase in tests/* 
        do 
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            python3 "$file" < "$testcase" > "$outputfile"
            fi
            ((count++))
        done
    
    fi    
done 




#gcc targets/C/2105221/main.c -o targets/C/2105221/main.out 






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
