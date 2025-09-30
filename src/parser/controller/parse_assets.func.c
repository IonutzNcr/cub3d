/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:00:38 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 01:02:29 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_no(char *line)
{
	int			fd;
	t_assets	*assets;

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_NO = ft_strdup(line);
	if (!assets->file_NO && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}

int	parse_so(char *line)
{
	int			fd;
	t_assets	*assets;

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_SO = ft_strdup(line);
	if (!assets->file_SO && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}

int	parse_we(char *line)
{
	int			fd;
	t_assets	*assets;

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_WE = ft_strdup(line);
	if (!assets->file_WE && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}

int	parse_ea(char *line)
{
	int			fd;
	t_assets	*assets;

	while (*line && (*line != '/' && *line != '.'))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1 && set_sgt_error(NO_FILE))
		return (*sgt_error());
	if (is_file_empty(line) && set_sgt_error(EM_FILE))
		return (close(fd), *sgt_error());
	close(fd);
	assets = sgt_assets();
	assets->file_EA = ft_strdup(line);
	if (!assets->file_EA && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}
