/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:55:23 by inicoara          #+#    #+#             */
/*   Updated: 2025/11/06 06:56:27 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	init_to_save_lines(int *fd, t_task liste[6], size_t *is, char **argv)
{
	*is = 0;
	init_list(liste);
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		return (perror("Error: "), 1);
	return (0);
}

int	last_verif_to_save_lines(int fd, t_task liste[6])
{
	if (last_verif(liste))
		return (close(fd), free_singleton(), print_error());
	close(fd);
	return (0);
}
