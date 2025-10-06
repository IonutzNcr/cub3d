/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:55:51 by yoyo              #+#    #+#             */
/*   Updated: 2025/10/06 16:28:38 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_file_empty(char *file)
{
	int		fd;
	int		byte;
	char	buf[2];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(), 1);
	byte = read(fd, buf, 2);
	close(fd);
	if (byte == 0)
		return (1);
	return (0);
}
