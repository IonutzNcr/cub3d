/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:23:38 by leothoma          #+#    #+#             */
/*   Updated: 2025/08/27 00:23:39 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_main.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	int	w;
	int	a;
	int	s;
	int	d;
}	t_mlx;
