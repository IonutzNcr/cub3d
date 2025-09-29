/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:20:52 by leothoma          #+#    #+#             */
/*   Updated: 2025/09/29 13:18:35 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a modifier plus tard
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920

#define TEXTURE_COUNT 4

//
typedef struct s_game
{
	int	move_forward;
	int	move_backward;
	int	rotation_left;
	int	rotation_right;

	double	move_speed;
	double	rotation_speed;

	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_y;
	double	plane_x;

	int	map_width;
	int	map_height;
	char	**world_map;

	int	ceiling_color;
	int	floor_color;

	void	*textures[TEXTURE_COUNT];
	char	*tex_addr[TEXTURE_COUNT];
	int	bits_per_pixel[TEXTURE_COUNT];
	int	line_length[TEXTURE_COUNT];
	int	endian[TEXTURE_COUNT];
	int	tex_width[TEXTURE_COUNT];
	int	tex_height[TEXTURE_COUNT];
}	t_game;

typedef struct s_ray
{
	double	time;
	double	oldtime;
	double	frametime;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
}	t_ray;

typedef struct s_ctx
{
	t_ray *ray;
	t_mlx *mlx;
	t_game *game;
}	t_ctx;

t_mlx	**sgt_mlx();
void	render_single_frame(t_game *game, t_mlx *mlx, t_ray *ray);
void	cast_ray(t_game *game, int i, t_mlx *mlx, t_ray *ray);
void	draw_walls(t_game *game, t_ray *r, int i, t_mlx *mlx);
void	calculate_wall_distance(t_game *g, t_ray *r);
void	execute_dda(t_game *game, t_ray *r);
void	calculate_distances(t_game *game, t_ray *r);
void	init_ray(t_game *game, t_ray *r, int i);
void	ft_verline(t_mlx *mlx, int x, int drawStart, int drawEnd, int color);
void	start_game_loop(t_game *game, t_mlx *mlx);
void	clear_all(t_ctx *ctx);

