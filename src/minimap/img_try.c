#include "img_tri.h"
#include <stdlib.h>

// --- Bresenham (contour) ---
void img_draw_line(t_img *img, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy; // err = dx + dy (car dy est négatif)

    while (1) {
        img_put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// --- Triangle plein (barycentrique) ---
static inline int edge_function(int ax, int ay, int bx, int by, int px, int py)
{
    // vecteur AB x AP (produit en z)
    return (px - ax) * (by - ay) - (py - ay) * (bx - ax);
}

void img_fill_triangle(t_img *img,
                       int x0, int y0, int x1, int y1, int x2, int y2,
                       uint32_t color)
{
    // Boîte englobante
    int minx = x0 < x1 ? x0 : x1; minx = minx < x2 ? minx : x2;
    int miny = y0 < y1 ? y0 : y1; miny = miny < y2 ? miny : y2;
    int maxx = x0 > x1 ? x0 : x1; maxx = maxx > x2 ? maxx : x2;
    int maxy = y0 > y1 ? y0 : y1; maxy = maxy > y2 ? maxy : y2;

    // clamp sur l’image
    if (minx < 0) minx = 0;
    if (miny < 0) miny = 0;
    if (maxx >= img->w) maxx = img->w - 1;
    if (maxy >= img->h) maxy = img->h - 1;

    // Orientation du triangle (horaire / anti-horaire)
    int area2 = edge_function(x0, y0, x1, y1, x2, y2);
    if (area2 == 0) {
        // triangle dégénéré : on peut tracer juste les bords
        img_draw_line(img, x0, y0, x1, y1, color);
        img_draw_line(img, x1, y1, x2, y2, color);
        img_draw_line(img, x2, y2, x0, y0, color);
        return;
    }

    // Règle d’inclusion : on remplit les points du même côté des 3 arêtes
    // On accepte les points avec signe cohérent avec area2
    for (int y = miny; y <= maxy; ++y) {
        for (int x = minx; x <= maxx; ++x) {
            int w0 = edge_function(x1, y1, x2, y2, x, y);
            int w1 = edge_function(x2, y2, x0, y0, x, y);
            int w2 = edge_function(x0, y0, x1, y1, x, y);

            if ((area2 > 0 && w0 >= 0 && w1 >= 0 && w2 >= 0) ||
                (area2 < 0 && w0 <= 0 && w1 <= 0 && w2 <= 0)) {
                img_put_pixel(img, x, y, color);
            }
        }
    }
}

// --- Triangle contour (utilise 3 lignes) ---
void img_stroke_triangle(t_img *img,
                         int x0, int y0, int x1, int y1, int x2, int y2,
                         uint32_t color)
{
    img_draw_line(img, x0, y0, x1, y1, color);
    img_draw_line(img, x1, y1, x2, y2, color);
    img_draw_line(img, x2, y2, x0, y0, color);
}
