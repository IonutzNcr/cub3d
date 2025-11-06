/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:03:56 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 17:50:26 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define ERR_LG "ERROR: Invalid line between map and the rest\n"

static void	print_error_2(int error)
{
	if (error == F_MALL)
		write(2, "ERROR: Malloc Fail\n", 19);
	if (error == NO_WALL)
		write(2, "ERROR: NO WALL DETECTED\n", 24);
	if (error == INV_CH)
		write(2, "ERROR: Invalid character in map\n", 32);
	if (error == PLY_NB)
		write(2, "ERROR: Too many players\n", 24);
	if (error == NO_PLY)
		write(2, "ERROR: No player detected\n", 26);
	if (error == NO_FILE)
		write(2, "ERROR: INVALID FILE\n", 20);
	if (error == LOAD_ERR)
		write(2, "ERROR: FAILED TO LOAD TEXTURE\n", 30);
	if (error == INC_ERR)
		write(2, "ERROR: incomplete file config\n", 30);
	if (error == BTW_LN)
		write(2, ERR_LG, 45);
	if (error > 16)
		printf("ERROR %d not detected yet\n", error);
}

int	print_error(void)
{
	int	error;

	error = *sgt_error();
	if (error == P_NUM)
		write(2, "ERROR: Invalid parameter number\n", 32);
	if (error == NO_ENV)
		write(2, "ERROR: No env found\n", 20);
	if (error == INV_EXT)
		write(2, "ERROR: Invalid file extension\n", 30);
	if (error == E_SCENE)
		write(2, "ERROR: Empty scene\n", 19);
	if (error == E_DUPLI)
		write(2, "ERROR: Double config detected\n", 30);
	if (error == INV_LN)
		write(2, "ERROR: Invalid Line\n", 20);
	if (error == EM_FILE)
		write(2, "ERROR: Empty file detected\n", 27);
	print_error_2(error);
	return (error);
}

char	*wgnl(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return (NULL);
	if ((*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
	return (*line);
}

void	init_list(t_task list[6])
{
	int	i;

	i = 0;
	while (i < 6)
		list[i++].done = 0;
	list[0].func = is_texture_no;
	list[0].parse = parse_no;
	list[1].func = is_texture_so;
	list[1].parse = parse_so;
	list[2].func = is_texture_we;
	list[2].parse = parse_we;
	list[3].func = is_texture_ea;
	list[3].parse = parse_ea;
	list[4].func = is_ceiling;
	list[4].parse = parse_ceiling;
	list[5].func = is_floor;
	list[5].parse = parse_floor;
}

int	empty_gnl(int fd)
{
	char	*line;

	while (wgnl(&line, fd))
		free(line);
	return (0);
}
