#!/bin/bash

# Fichier de sortie
OUTPUT_FILE="test_output"

# Vider le fichier de sortie s'il existe déjà
> "$OUTPUT_FILE"

# Lancer chaque fichier de map dans map/invalid avec cub3d
for map_file in maps/invalid/*; do
    echo ">>> Testing $map_file"
    ./cub3d "$map_file" 
    echo -e "\n---\n" 
done

# Lancer chaque fichier de map dans map/invalid avec cub3d
for map_file in maps/valid/*; do
    echo ">>> Testing $map_file"
    ./cub3d "$map_file" 
    echo -e "\n---\n" 
done
