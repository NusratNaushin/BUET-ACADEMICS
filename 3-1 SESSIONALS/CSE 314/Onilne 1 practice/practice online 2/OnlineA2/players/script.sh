#!/bin/bash

# Find all .txt files recursively
find . -type f -name "*.txt" | while read filepath; do
    # Extract info from the file
    player_name=$(sed -n '1p' "$filepath")
    country=$(sed -n '2p' "$filepath" | xargs)
    role=$(sed -n '4p' "$filepath" | xargs)

    # Create target directory
    target_dir="./$country/$role"
    mkdir -p "$target_dir"

    # Move and rename file
    mv "$filepath" "$target_dir/$player_name.txt"
done

# Remove empty directories bottom-up
find . -type d -empty -delete
