#!/bin/bash

while getopts "f:" option; do
   case $option in
      f)
        root_dir=$OPTARG
        build_dir="$root_dir/build"
        tmp_dir="$root_dir/.tmp";;
      \?)
        echo "Invalid option"
        exit;;
   esac
done

# Exit if no directory provided
if [ -z "$root_dir" ]; then
  echo "No directory provided, see -f option"
fi

# Create or empty build
if [ ! -d "$build_dir" ]; then
  mkdir "$build_dir"
else
  # Good practice: le ${variable:?} fait crash le script si la variable
  # n'est pas définie, évite de supprimer tous les fichiers au cas où.
  rm -rfv "${build_dir:?}/"*
fi

# Create or emput .tmp
if [ ! -d "$tmp_dir" ]; then
  mkdir "$tmp_dir"
else
  rm -rfv "${tmp_dir:?}/"*
fi

for c in "$root_dir/"*.c; do
  avr-gcc -c \
      -std=gnu17 -Os -Wall -DF_CPU=16000000 -mmcu=atmega328p \
      "$c" \
      -o "$tmp_dir/${c%.*}.o"
done