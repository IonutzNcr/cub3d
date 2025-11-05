/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:21:21 by inicoara          #+#    #+#             */
/*   Updated: 2025/11/05 19:43:15 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum		e_err
{
	P_NUM = 1,
	NO_ENV,
	INV_EXT,
	E_SCENE,
	E_DUPLI,
	INV_LN,
	EM_FILE,
	F_MALL,
	NO_WALL,
	INV_CH,
	PLY_NB,
	NO_PLY,
	NO_FILE,
};

typedef int	(*t_check)(char *line);
typedef int	(*t_mapf)(void);

typedef struct s_task
{
	t_check	func;
	t_check	parse;
	int		done;
}			t_task;

typedef struct s_map_task
{
	t_check	func;
}			t_map_task;

typedef struct s_assets
{
	char	*file_no;
	char	*file_so;
	char	*file_we;
	char	*file_ea;
	int		floor;
	int		ceiling;
}			t_assets;

typedef struct s_player
{
	double	x;
	double	y;
	double	orientation;
}			t_player;

int			is_extension(int argc, char *argv[], char *env[]);
int			is_file_empty(char *file);
int			set_sgt_error(int error);
int			*sgt_error(void);
int			*sgt_line(void);
t_assets	*sgt_assets(void);
char		***sgt_map(void);
int			get_player_info(void);
t_player	*sgt_player(void);

/*this is ok...*/
int			is_texture_no(char *line);
int			is_texture_so(char *line);
int			is_texture_we(char *line);
int			is_texture_ea(char *line);
int			is_ceiling(char *line);
int			is_floor(char *line);

int			asset_checker(t_task *liste, char *line);

int			checked_list(t_task liste[6]);
void		free_split(char **arg);
int			parse_floor(char *line);
int			parse_ceiling(char *line);
int			parse_no(char *line);
int			parse_so(char *line);
int			parse_we(char *line);
int			parse_ea(char *line);
int			asset_parser(t_task liste[6], char *line);
int			is_invalid_space(char ch);
int			print_error(void);
void		init_list(t_task list[6]);
char		*wgnl(char **line, int fd);
int			parser(int argc, char *argv[], char *env[]);
int			last_verif(t_task liste[6]);
int			quick_verif(int argc, char *argv[], char *env[]);
int			hard_verif(char *argv[]);
int			empty_gnl(int fd);
int			mapper(char *line, int fd);

int			add_line(char *line);
int			remove_map(void);
void		remove_assets(void);
void		free_singleton(void);
void		*ft_remalloc(void *old, int n_size, int old_size);

int			map_parser(char *line);
int			map_checker(void);
int			count_elements(char **argv);

int			check_characters(void);
char		**get_row(int row);
int			map_fixer(void);
int			is_lc_wall(void);
int			is_c1_wall(void);
int			is_lr_wall(void);
int			is_r1_wall(void);

char	**ft_free_map_null(char **map);
char	**copy_map(char **map);
int check_walls();
int	can_move(int x, int y, char **map);
int is_on_edge(int x, int y);
void	ft_searchpath(int x, int y, char **map, int *isOut);


t_player find_new_zero(char **map);
#endif