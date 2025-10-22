#!/bin/bash


# Lancer chaque fichier de map dans maps/invalid avec valgrind
for map_file in maps/invalid/*; do
    echo ">>> Testing $map_file" 

    valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./cub3D "$map_file"
    
    echo -e "---\n" 
done
 
echo -e "-------------------\n" 

# Lancer chaque fichier de map dans maps/invalid avec valgrind
for map_file in maps/valid/*; do
    echo ">>> Testing $map_file" 

    valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes  --track-origins=yes ./cub3D "$map_file"
    
    echo -e "---\n" 
done
