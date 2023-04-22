#!/bin/bash

for file in $(find . -name '*.cpp')
do
    iconv -f cp1251 -t utf-8 "$file" > "$file.new" &&
    mv -f "$file.new" "$file"
done