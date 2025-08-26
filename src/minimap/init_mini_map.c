#include "checker.h"
#include "minimap.h"

int init_mini_map()
{
    void    *mlx_ptr;
    void    *win_ptr;

    // 1. Initialisation
    printf("the fck\n");
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);

    char **map = *sgt_map();
    int L = ft_strlen(*map);
    int l = count_elements(map);
    printf("L = %d l = %d\n", L , l );
    // 2. Création d'une fenêtre 800x600 qui s'appelle "Ma fenêtre"
    win_ptr = mlx_new_window(mlx_ptr, L *15 , l*15, "Ma fenetre");
    if (win_ptr == NULL)
        return (1);
    printf("succccccccccc\n");
    // 3. Boucle infinie pour garder la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return (0);
}