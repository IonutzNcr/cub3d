// img.c
#include "img.h"
#include <string.h> // memset si besoin

int img_create(void *mlx, t_img *dst, int w, int h)
{
    dst->w = w;
    dst->h = h;
    dst->img = mlx_new_image(mlx, w, h);
    if (!dst->img) return 1;
    dst->addr = mlx_get_data_addr(dst->img, &dst->bpp, &dst->line_len, &dst->endian);
    if (!dst->addr) return 1;
    return 0;
}

void img_destroy(void *mlx, t_img *img)
{
    if (img->img)
        mlx_destroy_image(mlx, img->img);
    img->img = NULL;
    img->addr = NULL;
}

static inline int in_bounds(t_img *img, int x, int y)
{
    return (x >= 0 && x < img->w && y >= 0 && y < img->h);
}

void img_put_pixel(t_img *img, int x, int y, uint32_t color)
{
    if (!in_bounds(img, x, y)) return;

    // bpp est en bits → bytes_per_pixel :
    int    bpp_bytes = img->bpp / 8;
    char  *px = img->addr + (y * img->line_len) + (x * bpp_bytes);

    // MLX Linux est généralement en B,G,R,A (endian = 0), mais on écrit brut :
    *(uint32_t *)px = color;
}

/*
 * Dessine un carré plein de côté `size` à partir de (x,y) (coin haut-gauche)
 * color : 0xAARRGGBB (ou 0x00RRGGBB si pas d’alpha)
 */
void img_fill_rect(t_img *img, int x, int y, int size, uint32_t color)
{
    int i, j;
    int x2 = x + size;
    int y2 = y + size;

    if (x >= img->w || y >= img->h || x2 <= 0 || y2 <= 0) return; // entièrement hors
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x2 > img->w) x2 = img->w;
    if (y2 > img->h) y2 = img->h;

    for (j = y; j < y2; ++j) {
        // écrire ligne par ligne pour minimiser le recalcul d’adresse
        int    bpp_bytes = img->bpp / 8;
        char  *row = img->addr + j * img->line_len + x * bpp_bytes;
        for (i = x; i < x2; ++i) {
            *(uint32_t *)(row) = color;
            row += bpp_bytes;
        }
    }
}
