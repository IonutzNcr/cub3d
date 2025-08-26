#ifndef IMG_TRI_H
# define IMG_TRI_H

# include <stdint.h>
# include "img.h"   // contient t_img, img_put_pixel(...)

void img_draw_line(t_img *img, int x0, int y0, int x1, int y1, uint32_t color);
void img_fill_triangle(t_img *img,
                       int x0, int y0, int x1, int y1, int x2, int y2,
                       uint32_t color);
void img_stroke_triangle(t_img *img,
                         int x0, int y0, int x1, int y1, int x2, int y2,
                         uint32_t color);

#endif
