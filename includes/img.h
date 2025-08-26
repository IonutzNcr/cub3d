// img.h (ex: à mettre dans includes/)
#ifndef IMG_H
# define IMG_H
# include <mlx.h>
# include <stdint.h>

typedef struct s_img {
    void    *img;         // handle MLX
    char    *addr;        // adresse du buffer
    int     bpp;          // bits par pixel
    int     line_len;     // octets par ligne
    int     endian;       // 0 = little, 1 = big
    int     w;            // largeur
    int     h;            // hauteur
}   t_img;

// Création/Destruction
int  img_create(void *mlx, t_img *dst, int w, int h);
void img_destroy(void *mlx, t_img *img);

// Dessin
void img_put_pixel(t_img *img, int x, int y, uint32_t color);
void img_fill_rect(t_img *img, int x, int y, int size, uint32_t color);

#endif
