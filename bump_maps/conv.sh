#!/bin/bash

for file in *.jpg; do
	convert "$file" -compress none -depth 8 -define ppm:format=p3 "${file%.*}.ppm" && rm "$file";
done
