#!/bin/bash

# Fichier de sortie
OUTPUT_FILE="test_output"

# Vider le fichier de sortie s'il existe déjà
> "$OUTPUT_FILE"

# Lancer chaque fichier de map dans maps/invalid avec valgrind
for map_file in maps/invalid/*; do
    echo ">>> Testing $map_file" 

    valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3D "$map_file" 2>&1 
    
    echo -e "---\n" 
done
 
echo -e "-------------------\n" 

