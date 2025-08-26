#include <mlx.h>
#include "img.h"
#include "checker.h"
#include <math.h>

#define W 1000
#define H 1000
#define TILE 30
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

static void rotate_point(float cx, float cy, float angle, float *px, float *py)
{
    float s = sin(angle);
    float c = cos(angle);

    // translation vers l'origine
    float x = *px - cx;
    float y = *py - cy;

    // rotation
    float xnew = x * c - y * s;
    float ynew = x * s + y * c;

    // retour
    *px = xnew + cx;
    *py = ynew + cy;
}

static void draw_player_triangle(t_img *frame, int c, int i, char dir, int tile, uint32_t color)
{
    int x0 = c * tile;
    int y0 = i * tile;

    // Centre de la case
    float cx = x0 + tile / 2.0f;
    float cy = y0 + tile / 2.0f;

    // Triangle de base (pointe vers le haut/N)
    float Ax = cx;           float Ay = y0;
    float Bx = x0;           float By = y0 + tile;
    float Cx = x0 + tile;    float Cy = y0 + tile;

    // Choisir angle selon direction
    float angle = 0.0f; // N = 0
    if (dir == 'E') angle = M_PI / 2.0f;      // Est → 90°
    else if (dir == 'S') angle = M_PI;        // Sud → 180°
    else if (dir == 'W') angle = 3*M_PI/2.0f; // Ouest → 270°

    // Appliquer la rotation
    rotate_point(cx, cy, angle, &Ax, &Ay);
    rotate_point(cx, cy, angle, &Bx, &By);
    rotate_point(cx, cy, angle, &Cx, &Cy);

    // Dessiner d'abord le fond (sol blanc)
    img_fill_rect(frame, x0, y0, tile, 0x00FFFFFF);

    // Puis le triangle
    img_fill_triangle(frame, (int)Ax, (int)Ay, (int)Bx, (int)By, (int)Cx, (int)Cy, color);
}

int render_2dMap(void *mlx, void *win)
{
    t_img frame;
    if (img_create(mlx, &frame, W, H)) return 1;

    char **map = *sgt_map();
    int rows = count_elements(map);
    int l = ft_strlen(*map);
    int i = 0;
    int is_player = 0;
   for (int i = 0; i < rows; i++) {
    int cols = ft_strlen(map[i]);
    for (int c = 0; c < cols; c++) {
        char cell = map[i][c];
        int x0 = c * TILE;
        int y0 = i * TILE;

        if (cell == '1') {
            img_fill_rect(&frame, x0, y0, TILE, 0x00FF0000); // mur rouge
        }
        else if (cell == '0') {
            img_fill_rect(&frame, x0, y0, TILE, 0x00FFFFFF); // sol blanc
        }
        else if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W') {
            draw_player_triangle(&frame, c, i, cell, TILE, 0x0000FF00); // joueur vert
        }
    }
}


    // Afficher l’image dans la fenêtre
    mlx_put_image_to_window(mlx, win, frame.img, 0, 0);

    // Boucle (si tu veux animer, modifie frame puis remet un put_image)
    mlx_loop(mlx);

    // (jamais atteint normalement)
  /*   img_destroy(mlx, &frame); */
}
