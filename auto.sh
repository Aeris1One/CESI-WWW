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
  echo 'No directory provided, see -f option'
fi

echo 'Étape 1 : Création des dossiers nécessaires'

# Create or empty build
if [ ! -d "$build_dir" ]; then
  echo '- Création du dossier build/'
  mkdir "$build_dir"
else
  # Good practice: le ${variable:?} fait crash le script si la variable
  # n'est pas définie, évite de supprimer tous les fichiers au cas où.
  echo '- Vidange du dossier build/'
  rm -rfv "${build_dir:?}/"*
fi

# Create or emput .tmp
if [ ! -d "$tmp_dir" ]; then
  echo '- Création du dossier .tmp/'
  mkdir "$tmp_dir"
else
  echo '- Vidange du dossier .tmp/'
  rm -rfv "${tmp_dir:?}/"*
fi

echo 'Étape 2 : Compilation des fichiers objets'
for c in "$root_dir/"*.c; do
  c=$(basename "$c")
  o="${c%.*}.o"
  avr-gcc \
      -std=gnu17 -Os -Wall -DF_CPU=16000000 -mmcu=atmega328p \
      -c "$c" \
      -o "$tmp_dir/$o"
  o_file_list="$o_file_list $tmp_dir/$o"
done

echo 'Étape 3 : Création des liens'
  # shellcheck disable=SC2086
avr-gcc \
      -std=gnu17 -Os -Wall -DF_CPU=16000000 -mmcu=atmega328p \
      $o_file_list \
      -o "$build_dir/output.elf"