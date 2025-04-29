#!/bin/bash


submission_folder=$1
target_folder=$2
test_folder=$3
answer_folder=$4


#taskA
mkdir -p "$target_folder"

mkdir -p "$target_folder/C" "$target_folder/C++" "$target_folder/Python" "$target_folder/Java"

temp="unzipped"
rm -rf "$temp"

for file in "$submission_folder"/*zip
do

    filename=$(basename "$file")
    filename_without_extension="${filename%.zip}"
    id=${filename_without_extension: -7}


    rm -rf "$temp"
    unzip -qq "$file" -d "$temp"

    filetype=$(find "$temp" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.py" -o -name "*.java" \) | head -n 1)

    if [[ $filetype == *.c ]];then
        mkdir -p "$target_folder"/C/"$id"
        mv "$filetype" "$target_folder/C/$id/main.c"
    elif [[ $filetype == *.cpp ]];then
        mkdir -p "$target_folder"/C++/"$id"
        mv "$filetype" "$target_folder/C++/$id/main.cpp"
    elif [[ $filetype == *.py ]];then
        mkdir -p "$target_folder"/Python/"$id"
        mv "$filetype" "$target_folder/Python/$id/main.py"
    elif [[ $filetype == *.java ]];then
        mkdir -p "$target_folder"/Java/"$id"
        mv "$filetype" "$target_folder/Java/$id/Main.java"
    fi
done

rm -rf "$temp"


echo "Student id","Student Name","Language","Matched","Not Matched","Line Count","Comment Count" >> "targets/resultcheck.csv"

#taskB&C with paknami
for file in "$target_folder"/*/*/[Mm]ain.*
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


    filepath="$file"

    folderpath=$(dirname "$file")

    if [[ "$file" == *.c ]]; then
        gcc "$filepath" -o "$folderpath/main.out"
    elif [[ "$file" == *.cpp ]]; then
        g++ "$filepath" -o "$folderpath/main.out"
    elif [[ "$file" == *.java ]]; then
        javac "$filepath" -d "$folderpath"
    fi    




    filepath="$file"

    folderpath=$(dirname "$file")
    
    if [[ "$file" == *.c ]]; then
        lang="C"
        count=1;
        for testcase in "$test_folder"/*
        do
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            ./"$folderpath/main.out" < "$testcase" > "$outputfile"
            fi
            ((count++))

        done
    elif [[ "$file" == *.cpp ]]; then
        lang="C++"
        count=1;
        for testcase in "$test_folder"/*
        do
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            ./"$folderpath/main.out" < "$testcase" > "$outputfile"
            fi
            ((count++))
        done
    elif [[ "$file" == *.java ]]; then
        lang="Java"
        count=1
        for testcase in "$test_folder"/*
        do
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            java -cp "$folderpath" Main < "$testcase" > "$outputfile"
            fi
            ((count++))
        done
    elif [[ "$file" == *.py ]]; then
        lang="Python"
        count=1
        for testcase in "$test_folder"/* 
        do 
            outputfile="$folderpath/out$count.txt"
            if [[ ! -f "$outputfile" ]]; then
            python3 "$file" < "$testcase" > "$outputfile"
            fi
            ((count++))
        done
    
    fi 


    matched=0
    not_matched=0
   # filepath="$file"
    #folderpath=$(dirname "$file")
    zipfile=$(find "$submission_folder" -name "*$student_id.zip")
    zipname=$(basename "$zipfile")
    name=${zipname%%_submission*}
    name_only=${name%_*}

    student_id=$(basename "$(dirname "$file")")
    count=1
    for ans in "$answer_folder"/*
    do
        outputfile="$folderpath/out$count.txt"
        if [[ -f "$outputfile" ]]; then
           if diff -q "$outputfile" "$ans" > /dev/null; then
             ((matched++))
            else
                ((not_matched++))
            fi
        fi
        ((count++))
    done
    # echo "$student_id" "$lang" >> "targets/lang.txt"
    # echo "$student_id" "$matched" "$not_matched" >> "targets/match_unmatch.txt"
    # echo "$dirname" "$lines" "$comment_count" >> "targets/output.csv"
    

    echo "$student_id","$name_only","$lang","$matched","$not_matched","$lines","$comment_count" >> "targets/resultcheck.csv"
done 



# #taskB


# for file in targets/*/*/[Mm]ain.*
# do 

#     lines=$(wc -l < "$file")
#     dirname=$(basename "$(dirname "$file")")
#     comment_count=0

#     if [[ "$file" == *.c ]]; then
#         comment_count=$(grep -cE '//' "$file")
#     elif [[ "$file" == *.cpp ]]; then
#         comment_count=$(grep -cE '//' "$file")
#     elif [[ "$file" == *.py ]]; then
#         comment_count=$(grep -cE '#' "$file")
#     elif [[ "$file" == *.java ]]; then
#         comment_count=$(grep -cE '//' "$file")
#     fi





#     echo "$dirname" "$lines" "$comment_count" >> output.csv
    
# done 



# for file in targets/*/*/[Mm]ain.*
# do 

#     filepath="$file"

#     folderpath=$(dirname "$file")

#     if [[ "$file" == *.c ]]; then
#         gcc "$filepath" -o "$folderpath/main.out"
#     elif [[ "$file" == *.cpp ]]; then
#         g++ "$filepath" -o "$folderpath/main.out"
#     elif [[ "$file" == *.java ]]; then
#         javac "$filepath" -d "$folderpath"
#     fi    
# done 



# for file in targets/*/*/[Mm]ain.*
# do 

    
#     filepath="$file"

#     folderpath=$(dirname "$file")
    
#     if [[ "$file" == *.c ]]; then
#         count=1;
#         for testcase in tests/*
#         do
#             outputfile="$folderpath/out$count.txt"
#             if [[ ! -f "$outputfile" ]]; then
#             ./"$folderpath/main.out" < "$testcase" > "$outputfile"
#             fi
#             ((count++))

#         done
#     elif [[ "$file" == *.cpp ]]; then
#         count=1;
#         for testcase in tests/*
#         do
#             outputfile="$folderpath/out$count.txt"
#             if [[ ! -f "$outputfile" ]]; then
#             ./"$folderpath/main.out" < "$testcase" > "$outputfile"
#             fi
#             ((count++))
#         done
#     elif [[ "$file" == *.java ]]; then
#         count=1
#         for testcase in tests/*
#         do
#             outputfile="$folderpath/out$count.txt"
#             if [[ ! -f "$outputfile" ]]; then
#             java -cp "$folderpath" Main < "$testcase" > "$outputfile"
#             fi
#             ((count++))
#         done
#     elif [[ "$file" == *.py ]]; then
#         count=1
#         for testcase in tests/* 
#         do 
#             outputfile="$folderpath/out$count.txt"
#             if [[ ! -f "$outputfile" ]]; then
#             python3 "$file" < "$testcase" > "$outputfile"
#             fi
#             ((count++))
#         done
    
#     fi    
# done 




# >match_unmatch.txt
# for student_folder in targets/*/*
# do

#     matched=0
#     not_matched=0
#    # filepath="$file"
#     #folderpath=$(dirname "$file")
#     student_id=$(basename "$student_folder")
#     count=1
#     for ans in answers/*
#     do
#         outputfile="$student_folder/out$count.txt"
#         if [[ -f "$outputfile" ]]; then
#            if diff -q "$outputfile" "$ans" > /dev/null; then
#              ((matched++))
#             else
#                 ((not_matched++))
#             fi
#         fi
#         ((count++))
#     done
#     echo "$student_id" "$matched" "$not_matched" >> "match_unmatch.txt"
# done



























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
