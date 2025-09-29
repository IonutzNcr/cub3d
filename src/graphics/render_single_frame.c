/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_single_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:20:43 by leothoma          #+#    #+#             */
/*   Updated: 2025/09/29 14:28:32 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

#define W 119
#define S 115
#define A 97
#define D 100
#define ESC 65307

void	init_map(t_game *game)
{
	char **map = *sgt_map();
	game->world_map = map;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_verline(t_mlx *mlx, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y < drawEnd)
	{
		my_mlx_pixel_put(mlx->img, x, y, color);
		y++;
	}
}

void	init_ray(t_game *game, t_ray *r, int i)
{
	r->camera_x = 2.0 * i / (double)SCREEN_WIDTH - 1;
	r->ray_dir_x = game->dir_x + game->plane_x * r->camera_x;
	r->ray_dir_y = game->dir_y + game->plane_y * r->camera_x;
	r->map_x = (int)game->pos_x;
	r->map_y = (int)game->pos_y;
	if (r->ray_dir_x == 0)
		    r->delta_dist_x = 1e30;
	else
		    r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		    r->delta_dist_y = 1e30;
	else
		    r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
	r->hit = 0;
}

void calculate_wall_distance(t_game *g, t_ray *r)
{
    // éviter divisions par 0 si un rayon est parfaitement vertical/horizontal
    const double BIG = 1e30;

    if (r->side == 0) {
        double denom = (r->ray_dir_x != 0.0) ? r->ray_dir_x : (1.0 / BIG);
        r->perp_wall_dist = (r->map_x - g->pos_x + (1 - r->step_x) * 0.5) / denom;
    } else {
        double denom = (r->ray_dir_y != 0.0) ? r->ray_dir_y : (1.0 / BIG);
        r->perp_wall_dist = (r->map_y - g->pos_y + (1 - r->step_y) * 0.5) / denom;
    }

    if (r->perp_wall_dist < 1e-6) r->perp_wall_dist = 1e-6; // garde-fou
}
void execute_dda(t_game *game, t_ray *r)
{
    // dimensions de la map
    int h = game->map_height;
    int w = game->map_width;

    // Sécurité: limite d’itérations pour éviter une boucle infinie si map invalide
    for (int k = 0; k < w * h + 10 && r->hit == 0; ++k)
    {
        // tie-break explicite pour l'égalité (optionnel mais propre)
        if (r->side_dist_x < r->side_dist_y || 
           (r->side_dist_x == r->side_dist_y && fabs(r->ray_dir_x) > fabs(r->ray_dir_y)))
        {
            r->side_dist_x += r->delta_dist_x;
            r->map_x += r->step_x;
            r->side = 0;
        }
        else
        {
            r->side_dist_y += r->delta_dist_y;
            r->map_y += r->step_y;
            r->side = 1;
        }

        // bornes: si on sort, on arrête proprement
        if (r->map_x < 0 || r->map_x >= w || r->map_y < 0 || r->map_y >= h) {
            r->hit = 1;
            // distance grande pour que rien ne s'affiche (ou gères ça comme "rien touché")
            r->perp_wall_dist = 1e9;
            break;
        }

        if (game->world_map[r->map_y][r->map_x] != '0')
            r->hit = 1;
    }
}

/* void	calculate_wall_distance(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
} */


void draw_walls(t_game *game, t_ray *r, int i, t_mlx *mlx)
{
    int tex_num;
    double wall_x;
    int tex_x, tex_y;
    int y;

    // 1) Protéger contre dist = 0
    if (r->perp_wall_dist <= 1e-6)
        r->perp_wall_dist = 1e-6;

    r->line_height = (int)(SCREEN_HEIGHT / r->perp_wall_dist);

    r->draw_start = -r->line_height / 2 + SCREEN_HEIGHT / 2;
    if (r->draw_start < 0) r->draw_start = 0;

    r->draw_end = r->line_height / 2 + SCREEN_HEIGHT / 2;
    if (r->draw_end >= SCREEN_HEIGHT) r->draw_end = SCREEN_HEIGHT - 1;

    // 2) Calcul du point de contact sur l’axe "mur"
    if (r->side == 0)
        wall_x = game->pos_y + r->perp_wall_dist * r->ray_dir_y;
    else
        wall_x = game->pos_x + r->perp_wall_dist * r->ray_dir_x;
    wall_x -= floor(wall_x); // garder la frac

    // 3) Sélection texture (E/W/N/S)
    if (r->side == 0)
        tex_num = (r->ray_dir_x > 0) ? 0 : 1;
    else
        tex_num = (r->ray_dir_y > 0) ? 2 : 3;

    // 4) tex_x + clamp
    tex_x = (int)(wall_x * (double)game->tex_width[tex_num]);
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= game->tex_width[tex_num]) tex_x = game->tex_width[tex_num] - 1;

    if ((r->side == 0 && r->ray_dir_x < 0) || (r->side == 1 && r->ray_dir_y > 0))
        tex_x = game->tex_width[tex_num] - tex_x - 1;

    // 5) Boucle Y avec clamp de tex_y et garde-fou sur i
    if (i < 0 || i >= SCREEN_WIDTH) return; // éviter tout débordement horizontal

    for (y = r->draw_start; y <= r->draw_end; y++) // <= pour inclure la dernière ligne
    {
        int d = (y * 256 - SCREEN_HEIGHT * 128 + r->line_height * 128);
        tex_y = ((long long)d * game->tex_height[tex_num] / r->line_height) / 256;

        // clamp tex_y
        if (tex_y < 0) tex_y = 0;
        if (tex_y >= game->tex_height[tex_num]) tex_y = game->tex_height[tex_num] - 1;

        char *tex_ptr = game->tex_addr[tex_num]
            + (tex_y * game->line_length[tex_num] + tex_x * (game->bits_per_pixel[tex_num] / 8));

        unsigned int color = *(unsigned int *)tex_ptr;
        if (r->side == 1)
            color = (color >> 1) & 0x7F7F7F;

        my_mlx_pixel_put(mlx->img, i, y, color);
    }
}

void	handle_time(t_ray *ray, struct timeval *tv)
{
	ray->oldtime = ray->time;
	gettimeofday(tv, NULL);
	ray->time = tv->tv_sec * 1000 + tv->tv_usec / 1000;
	ray->frametime = (ray->time - ray->oldtime) / 1000.0;
}

void	calculate_distances(t_game *game, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (game->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - game->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (game->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - game->pos_y) * r->delta_dist_y;
	}
}


void	cast_ray(t_game *game, int i, t_mlx *mlx, t_ray *ray)
{
	ft_bzero(ray, sizeof(t_ray));
	init_ray(game, ray, i);
	calculate_distances(game, ray);
	execute_dda(game, ray);
	calculate_wall_distance(game, ray);
	draw_walls(game, ray, i, mlx);
}

void	fill_background(t_mlx *mlx, t_game *game)
{
	//haut de l'ecrant
	game->floor_color = sgt_assets()->floor;
	game->ceiling_color= sgt_assets()->ceiling;
	for (int i = 0; i < SCREEN_HEIGHT / 2; i++)
	{
		for(int j = 0; j < SCREEN_WIDTH; j++)
		{
			my_mlx_pixel_put(mlx->img, j, i, game->floor_color);
		}
	}
	//bas de l'ecrant
	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			my_mlx_pixel_put(mlx->img, j, i, game->ceiling_color);
		}
	}
}

void	render_single_frame(t_game *game, t_mlx *mlx, t_ray *ray)
{
	int	i;
	struct timeval tv;

	ft_bzero(mlx->img->addr, game->map_width * game->map_height * (mlx->img->bits_per_pixel / 8));
	i = 0;
	fill_background(mlx, game);
	while (i < SCREEN_WIDTH)
	{
		cast_ray(game, i, mlx, ray);
		i++;
	}
	handle_time(ray, &tv);
}

int key_press(int keycode, t_ctx *ctx)
{
	if (keycode == 119)
		ctx->mlx->w = 1;
	else if (keycode == 115)
		ctx->mlx->s = 1;
	else if (keycode == 97)
		ctx->mlx->a = 1;
	else if (keycode == 100)
		ctx->mlx->d = 1;
	else if (keycode == 65361)
		ctx->mlx->left_arrow = 1;
	else if (keycode == 65363)
		ctx->mlx->right_arrow = 1;
	else if (keycode == 65307)
	{
		clear_all(ctx);
		exit(0);
	}
	return (0);
}

int key_release(int keycode, t_ctx *ctx)
{
	if (keycode == 119)
		ctx->mlx->w = 0;
	else if (keycode == 115)
		ctx->mlx->s = 0;
	else if (keycode == 97)
		ctx->mlx->a = 0;
	else if (keycode == 100)
		ctx->mlx->d = 0;
	else if (keycode == 65361)
		ctx->mlx->left_arrow = 0;
	else if (keycode == 65363)
		ctx->mlx->right_arrow = 0;
	else if (keycode == 65307)
		exit(0);
	return (0);
}

int	check_wall_colision(double *wall_dist)
{
	if (*wall_dist < 0.15)
		return (0);
	return (1);
}

static inline int tile_x(double x) { return (int)floor(x); }
static inline int tile_y(double y) { return (int)floor(y); }

static inline int is_open_cell(t_game *g, int my, int mx)
{
    if (my < 0 || mx < 0) return 0;
    printf("map_height: %d\n map_width: %d\n", g->map_height, g->map_width);
    if (my >= g->map_height || mx >= g->map_width) return 0;
    return g->world_map[my][mx] == '0';
}


static inline double clampd(double v, double a, double b) {
    return (v < a) ? a : (v > b) ? b : v;
}

static inline int inside_map(const t_game *g, int my, int mx) {
    return (my >= 0 && my < g->map_height && mx >= 0 && mx < g->map_width);
}

/* Repousse le centre (g->pos_x, g->pos_y) en dehors des murs si le cercle (rayon)
   chevauche une case solide. Gère bien les coins. */
static void fix_position_near_walls(t_game *g, double radius)
{
    double cx = g->pos_x;
    double cy = g->pos_y;
    const double eps = 1e-6;

    /* Quelques itérations au cas où le centre chevauche plusieurs cases (coins) */
    for (int iter = 0; iter < 3; ++iter) {
        int changed = 0;

        int min_mx = (int)floor(cx - radius) - 1;
        int max_mx = (int)floor(cx + radius) + 1;
        int min_my = (int)floor(cy - radius) - 1;
        int max_my = (int)floor(cy + radius) + 1;

        for (int my = min_my; my <= max_my; ++my) {
            for (int mx = min_mx; mx <= max_mx; ++mx) {
                if (!inside_map(g, my, mx)) continue;
                if (is_open_cell(g, my, mx)) continue; // on ne traite que les murs

                /* AABB de la case mur */
                double bx0 = mx,     by0 = my;
                double bx1 = mx + 1, by1 = my + 1;

                /* Point le plus proche de l’AABB */
                double nx = clampd(cx, bx0, bx1);
                double ny = clampd(cy, by0, by1);

                double vx = cx - nx;
                double vy = cy - ny;
                double d2 = vx*vx + vy*vy;
                double r2 = radius * radius;

                if (d2 < r2 - 1e-12) {
                    /* Il y a chevauchement */
                    if (d2 > eps*eps) {
                        double d = sqrt(d2);
                        double push = (radius - d);
                        cx += (vx / d) * push;
                        cy += (vy / d) * push;
                    } else {
                        /* Cas dégénéré (centre sur l'arête/coin) :
                           on pousse le long de l’axe le plus “proche” du centre de la box */
                        double bcx = 0.5 * (bx0 + bx1);
                        double bcy = 0.5 * (by0 + by1);
                        double ax = fabs(cx - bcx);
                        double ay = fabs(cy - bcy);

                        if (ax > ay) {
                            /* repousser en X jusqu’à être à radius de la face */
                            if (cx > bcx) cx = bx1 + radius + eps;
                            else          cx = bx0 - radius - eps;
                        } else {
                            /* repousser en Y */
                            if (cy > bcy) cy = by1 + radius + eps;
                            else          cy = by0 - radius - eps;
                        }
                    }
                    changed = 1;
                }
            }
        }
        if (!changed) break; // plus d’overlap
    }

    g->pos_x = cx;
    g->pos_y = cy;
}

// Test de déplacement avec "rayon" pour éviter de s'accrocher aux coins.
// dx/dy = vecteur de déplacement (nouvelle position - ancienne position)
static void try_move_with_radius(t_game *g, double new_x, double new_y,
                                 double dx, double dy, double radius)
{
    double off_x = (dx > 0.0) ? radius : (dx < 0.0 ? -radius : 0.0);
    double off_y = (dy > 0.0) ? radius : (dy < 0.0 ? -radius : 0.0);

    // Test axe X
    int test_mx = tile_x(new_x + off_x);
    int cur_my  = tile_y(g->pos_y);
    if (is_open_cell(g, cur_my, test_mx))
        g->pos_x = new_x;

    // Test axe Y (en utilisant pos_x possiblement mis à jour pour permettre le "sliding")
    int test_my = tile_y(new_y + off_y);
    int cur_mx  = tile_x(g->pos_x);
    if (is_open_cell(g, test_my, cur_mx))
        g->pos_y = new_y;
    
    fix_position_near_walls(g, radius);
}


int handle_movement(t_ctx *ctx)
{
    t_mlx  *m = ctx->mlx;
    t_game *g = ctx->game;

    // Utilise les vitesses du jeu si elles sont renseignées, sinon des défauts
    double move_speed = (g->move_speed     > 0.0) ? g->move_speed     : 0.05;
    double rot_speed  = (g->rotation_speed > 0.0) ? g->rotation_speed : 0.05;
    double radius = 0.25;

    double old_dir_x, old_plane_x;

    // --- Avancer (W)
    if (m->w) {
        double dx = g->dir_x * move_speed;
        double dy = g->dir_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Reculer (S)
    if (m->s) {
        double dx = -g->dir_x * move_speed;
        double dy = -g->dir_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Strafe gauche (A) : utilise le plan (perpendiculaire à dir)
    if (m->a) {
        double dx = -g->plane_x * move_speed;
        double dy = -g->plane_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Strafe droit (D)
    if (m->d) {
        double dx =  g->plane_x * move_speed;
        double dy =  g->plane_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Rotation
    if (m->left_arrow || m->right_arrow) {
        double angle = m->left_arrow ? -rot_speed : rot_speed;

        old_dir_x   = g->dir_x;
        g->dir_x    = g->dir_x * cos(angle) - g->dir_y * sin(angle);
        g->dir_y    = old_dir_x * sin(angle) + g->dir_y * cos(angle);

        old_plane_x = g->plane_x;
        g->plane_x  = g->plane_x * cos(angle) - g->plane_y * sin(angle);
        g->plane_y  = old_plane_x * sin(angle) + g->plane_y * cos(angle);
    }

    return 0;
}

int	loop_hook(t_ctx *ctx)
{
	handle_movement(ctx);
	mlx_clear_window(ctx->mlx->mlx, ctx->mlx->mlx_win);
	render_single_frame(ctx->game, ctx->mlx, ctx->ray);
	mlx_put_image_to_window(ctx->mlx->mlx, ctx->mlx->mlx_win, ctx->mlx->img->img, 0, 0);
	return (0);
}

void    load_textures(t_ctx *ctx)
{
	int	i;
	t_assets *assets;

	i = -1;
	assets = sgt_assets();
	ctx->game->textures[0] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_NO, &ctx->game->tex_width[0], &ctx->game->tex_height[0]);
	ctx->game->textures[1] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_SO, &ctx->game->tex_width[1], &ctx->game->tex_height[1]);
	ctx->game->textures[2] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_WE, &ctx->game->tex_width[2], &ctx->game->tex_height[2]);
	ctx->game->textures[3] = mlx_xpm_file_to_image(ctx->mlx->mlx,
		assets->file_EA, &ctx->game->tex_width[3], &ctx->game->tex_height[3]);
	while(++i < TEXTURE_COUNT)
	{
		if (!ctx->game->textures[i])
		{
			printf("Error: failed to load texture %d\n", i);
			exit(1);
		}
		ctx->game->tex_addr[i] = mlx_get_data_addr(ctx->game->textures[i],
			&ctx->game->bits_per_pixel[i],
			&ctx->game->line_length[i],
			&ctx->game->endian[i]);
	}
}

/*
void	load_textures(t_ctx *ctx)
{
	t_assets	*assets;
	void	*images[4];
	int	img_width;
	int	img_height;

	assets = sgt_assets();
	printf("%s\n", assets->file_NO);
	images[0] = mlx_xpm_file_to_image(ctx->mlx->mlx, assets->file_NO, &img_width, &img_height);
	//images[0] = assets->file_NO;
	images[1] = assets->file_SO;
	images[2] = assets->file_WE;
	images[3] = assets->file_EA;
	ctx->game->textures = images;
}
*/

t_mlx	**sgt_mlx()
{
	static	void *sgt_mlx;
	return (&sgt_mlx);
}

void	clear_all(t_ctx *ctx)
{
	t_mlx	*mlx;

	remove_map();
	remove_assets();
	mlx = *sgt_mlx();
	mlx_destroy_image(mlx->mlx, ctx->game->textures[0]);
	mlx_destroy_image(mlx->mlx, ctx->game->textures[1]);
	mlx_destroy_image(mlx->mlx, ctx->game->textures[2]);
	mlx_destroy_image(mlx->mlx, ctx->game->textures[3]);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	free(mlx->img);
	free(mlx->mlx);
	//TODO FREE ALL
	exit(0);
}

void	mouse_press(t_ctx *ctx)
{
	clear_all(ctx);
}

void	start_game_loop(t_game *game, t_mlx *mlx)
{
	t_ray	ray;
	t_ctx	ctx;
	ctx.game = game;
	ctx.mlx = mlx;
	ctx.ray = &ray;
	game->pos_x = sgt_player()->x + 0.5;
	game->pos_y = sgt_player()->y + 0.5;
	game->dir_x = cos(sgt_player()->orientation * M_PI / 180);   // looking left
	game->dir_y = sin(sgt_player()->orientation * M_PI / 180);
	game->plane_x = -game->dir_y * 0.66;
	game->plane_y = game->dir_x * 0.66; // FOV 66°
	game->map_width = ft_strlen(**sgt_map());
    game->map_height = count_elements(*sgt_map());
	load_textures(&ctx);
	ray.time = 0;
	ray.oldtime = 0;
	ray.frametime = 0;
	init_map(game);

	mlx_hook(mlx->mlx_win, 2, 1L<<0, key_press, &ctx);
	mlx_hook(mlx->mlx_win, 3, 1L<<1, key_release, &ctx);
	mlx_hook(mlx->mlx_win, 17, 0, mouse_press, &ctx);
	mlx_loop_hook(mlx->mlx, loop_hook, &ctx);
	mlx_loop(mlx->mlx); 
}
