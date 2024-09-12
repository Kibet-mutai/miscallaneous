#!/bin/bash

DIR=${1:-.}

find "$DIR" -name '*.cpp' -o -name '*.h' | while read file; do
    echo "Formatting $file"
    clang-format -i "$file"
done

echo "Formatting complete.."
