/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:00:38 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/17 10:28:41 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_no(char *line)
{
	int			fd;
	t_assets	*assets;
	char		buf[1];

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (read(fd, buf, 1) == -1)
		return (close(fd), 10);
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_no = ft_strdup(line);
	if (!assets->file_no && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}

int	parse_so(char *line)
{
	int			fd;
	t_assets	*assets;
	char		buf[1];

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (read(fd, buf, 1) == -1)
		return (close(fd), 10);
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_so = ft_strdup(line);
	if (!assets->file_so && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}

int	parse_we(char *line)
{
	int			fd;
	t_assets	*assets;
	char		buf[1];

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (read(fd, buf, 1) == -1)
		return (close(fd), 10);
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_we = ft_strdup(line);
	if (!assets->file_we && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}

int	parse_ea(char *line)
{
	int			fd;
	t_assets	*assets;
	char		buf[1];

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (read(fd, buf, 1) == -1)
		return (close(fd), 10);
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_ea = ft_strdup(line);
	if (!assets->file_ea && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}
