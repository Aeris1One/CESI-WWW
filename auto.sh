#!/bin/bash

file='.'
while getopts "f:" option; do
   case $option in
      f)
        file=$OPTARG;;
      \?)
        echo "Invalid option"
        exit;;
   esac
done

ls "$file"