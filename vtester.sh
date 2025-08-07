#!/bin/bash

# Fichier de sortie
OUTPUT_FILE="test_output"

# Vider le fichier de sortie s'il existe déjà
> "$OUTPUT_FILE"

# Lancer chaque fichier de map dans maps/invalid avec valgrind
for map_file in maps/invalid/*; do
    echo ">>> Testing $map_file" 

    valgrind --leak-check=full --show-leak-kinds=all ./cub3d "$map_file" 2>&1 \
        | awk '/HEAP SUMMARY:/, /^==.*ERROR SUMMARY:/ { print }' 
    
    echo -e "---\n" 
done
