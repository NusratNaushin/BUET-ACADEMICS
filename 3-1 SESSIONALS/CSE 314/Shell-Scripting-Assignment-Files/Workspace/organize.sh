#!/bin/bash


if [ "$#" -lt 4 ]; then
    echo "Usage: ./organize.sh <submission_folder> <target_folder> <test_folder> <answer_folder> [-v] [-noexecute] [-nolc] [-nocc] [-nofc]"
    exit 1
fi



submission_folder=$1
target_folder=$2
test_folder=$3
answer_folder=$4


verbose=false
noexecute=false
nolc=false
nocc=false
nofc=false

shift 4
while [[ $# -gt 0 ]]; do
    case "$1" in
    -v) verbose=true ;;
    -noexecute) noexecute=true ;;
    -nolc) nolc=true ;;
    -nocc) nocc=true ;;
    #-nofc) nofc=true ;;
    *) echo "Unnknown option: $1"; exit 1 ;;
    esac
    shift
done

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

    if $verbose; then
        echo "Organizing files of $id"
    fi
   
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

# if [[ $noexecute ]]; then
#     echo "Student id","Student Name","Language","Line Count","Comment Count" >> "targets/resultcheck.csv"
# fi

# if [[ ! $noexecute ]]; then
#     echo "Student id","Student Name","Language","Matched","Not Matched","Line Count","Comment Count" >> "targets/resultcheck.csv"
# fi

# if [[  $nolc ]]; then
#     echo "Student id","Student Name","Language","Matched","Not Matched","Comment Count" >> "targets/resultcheck.csv"
# fi


csv_file="$target_folder/resultcheck.csv"
csv_header="Student id,Student Name,Language"
if [[ $noexecute == false ]]; then
    csv_header+=",Matched,Not Matched"
fi
if [[ $nolc == false ]]; then
    csv_header+=",Line Count"
fi
if [[ $nocc == false ]]; then
    csv_header+=",Comment Count"
fi

echo "$csv_header" > "$csv_file"




#taskB&C with paknami


#loop_count=1
for file in "$target_folder"/*/*/[Mm]ain.*
do 

    if [[ $nolc==false ]]; then
        lines=$(wc -l < "$file")
    fi


    dirname=$(basename "$(dirname "$file")")
    comment_count=0

    student_id=$(basename "$(dirname "$file")")

    if [[ "$file" == *.c ]]; then
        lang="C"
    elif [[ "$file" == *.cpp ]]; then
        lang="C++"
    elif [[ "$file" == *.py ]]; then
        lang="Python"
    elif [[ "$file" == *.java ]]; then
        lang="Java"
    fi

    if [[  $nocc==false ]]; then
        if [[ "$file" == *.c ]]; then
            comment_count=$(grep -cE '//' "$file")
        elif [[ "$file" == *.cpp ]]; then
            comment_count=$(grep -cE '//' "$file")
        elif [[ "$file" == *.py ]]; then
            comment_count=$(grep -cE '#' "$file")
        elif [[ "$file" == *.java ]]; then
            comment_count=$(grep -cE '//' "$file")
        fi
    fi

    filepath="$file"

    folderpath=$(dirname "$file")
    if [[ $noexecute == false ]]; then
        if [[ "$file" == *.c ]]; then
            gcc "$filepath" -o "$folderpath/main.out"
        elif [[ "$file" == *.cpp ]]; then
            g++ "$filepath" -o "$folderpath/main.out"
        elif [[ "$file" == *.java ]]; then
            javac "$filepath" -d "$folderpath"
        fi    
    fi




    filepath="$file"

    folderpath=$(dirname "$file")
    

    if [[ $noexecute == false ]]; then
        if [[ "$file" == *.c ]]; then
            if $verbose; then
            echo "Executing files of $student_id"
            #echo "$loop_count"
            #((loop_count++))
            fi
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
            if $verbose; then
            echo "Executing files of $student_id"
            #echo "$loop_count"
            #((loop_count++))
            fi
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
            if $verbose; then
            echo "Executing files of $student_id"
            #echo "$loop_count"
            #((loop_count++))
            fi
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
            if $verbose; then
            echo "Executing files of $student_id"
            #echo "$loop_count"
            #((loop_count++))
            fi
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
    fi

    matched=0
    not_matched=0
   # filepath="$file"
    #folderpath=$(dirname "$file")
    zipfile=$(find "$submission_folder" -name "*$student_id.zip")
    zipname=$(basename "$zipfile")
    name=${zipname%%_submission*}
    name_only=${name%_*}

    

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
    
    
# if [[ ! noexecute ]]; then
#     echo "$student_id","$name_only","$lang","$matched","$not_matched","$lines","$comment_count" >> "targets/resultcheck.csv"
# fi

# if [[ noexecute ]]; then
#     echo "$student_id","$name_only","$lang","$lines","$comment_count" >> "targets/resultcheck.csv"
# fi


    
    row="$student_id,$name_only,$lang"
    if [[ $noexecute == false ]]; then
        row+=",$matched,$not_matched"
    fi
    if [[ $nolc == false ]]; then
        row+=",$lines"
    fi
    if [[ $nocc == false ]]; then
        row+=",$comment_count"
    fi

    echo "$row" >> "$csv_file"

done 

echo "All submissions processed successfully"

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






# /organize.sh submissions targets tests answers -v -noexecute -nolc -nocc 
