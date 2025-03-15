#!/bin/bash

# Check if the src directory exists
if [ ! -d "scenes" ]; then
    echo "Error: scenes/ directory not found!"
    exit 1
fi

# # Find all files in the src/ directory and subdirectories
# find scenes/1_invalid -type f | while read -r path; do
#     echo "Running ./miniRT with $path"
#     valgrind --leak-check=full ./miniRT "$path"
# done

# # Find all files in the src/ directory and subdirectories
# find scenes/2_basic_shapes -type f | while read -r path; do
#     echo "Running ./miniRT with $path"
#     valgrind --leak-check=full ./miniRT "$path"

# # Find all files in the src/ directory and subdirectories
# find scenes/3_tasked_scenes -type f | while read -r path; do
#     echo "Running ./miniRT with $path"
#     valgrind --leak-check=full ./miniRT "$path"
# done

# Find all files in the src/ directory and subdirectories
find scenes/4_subject_scenes -type f | while read -r path; do
    echo "Running ./miniRT with $path"
    valgrind --leak-check=full ./miniRT "$path"
done
