/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:20:52 by leothoma          #+#    #+#             */
/*   Updated: 2025/09/30 18:07:47 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define SCREEN_HEIGHT 1080
# define SCREEN_WIDTH 1920
# define TEXTURE_COUNT 4
# include "struct.h"

typedef struct s_game
{
	int			move_forward;
	int			move_backward;
	int			rotation_left;
	int			rotation_right;

	double		move_speed;
	double		rotation_speed;

	double		pos_x;
	double		pos_y;

	double		dir_x;
	double		dir_y;

	double		plane_y;
	double		plane_x;

	int			map_width;
	int			map_height;
	char		**world_map;

	int			ceiling_color;
	int			floor_color;

	void		*textures[TEXTURE_COUNT];
	char		*tex_addr[TEXTURE_COUNT];
	int			bits_per_pixel[TEXTURE_COUNT];
	int			line_length[TEXTURE_COUNT];
	int			endian[TEXTURE_COUNT];
	int			tex_width[TEXTURE_COUNT];
	int			tex_height[TEXTURE_COUNT];
}				t_game;

typedef struct s_ray
{
	double		time;
	double		oldtime;
	double		frametime;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
}				t_ray;

typedef struct s_ctx
{
	t_ray		*ray;
	t_mlx		*mlx;
	t_game		*game;
}				t_ctx;

t_mlx			**sgt_mlx(void);
void			render_single_frame(t_game *game, t_mlx *mlx, t_ray *ray);
void			cast_ray(t_game *game, int i, t_mlx *mlx, t_ray *ray);
void			draw_walls(t_game *game, t_ray *r, int i, t_mlx *mlx);
void			calculate_wall_distance(t_game *g, t_ray *r);
void			execute_dda(t_game *game, t_ray *r);
void			calculate_distances(t_game *game, t_ray *r);
void			init_ray(t_game *game, t_ray *r, int i);
void			ft_verline(t_mlx *mlx, int x, int drawStart, int drawEnd,
					int color);
void			start_game_loop(t_game *game, t_mlx *mlx);
void			clear_all(t_ctx *ctx);

int				handle_movement(t_ctx *ctx);
int				is_open_cell(t_game *g, int my, int mx);
double			clampd(double v, double a, double b);
int				inside_map(const t_game *g, int my, int mx);
void			compute_box_center(t_aabb box, t_vec2 *box_center);
void			compute_axis_delta(t_vec2 *c, t_vec2 *box_center, t_vec2 *axis_delta);
t_aabb			aabb_from_cell(int mx, int my);
t_gridBounds		compute_grid_bounds(double cx, double cy, double r);
t_closestPoint	closest_point_on_aabb(double cx, double cy, t_aabb b);
t_penetration		make_penetration(double cx, double cy, t_closestPoint cp,
					double radius);
int				has_overlap(t_penetration *pn);
#endif
