/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_file_ok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:35 by yoyo              #+#    #+#             */
/*   Updated: 2025/07/29 21:00:05 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int is_texture_file_ok(char *line, char *direction, t_assets *assets)
{
    int fd;

    errno = 0;
    if (ft_strncmp(line, direction, 2) != 0)
        return (0);
    line += 2;
    while (*line == ' ')
        line++;
    if (!*line)
        return (0);
    fd = open(line, O_RDONLY);
    if (fd == -1)
        return (0);
    if (is_file_empty(line))
    {
        close(fd);
        fill_assets_texture(-1, direction, assets);
        return (0);
    }
    fill_assets_texture(fd, direction, assets);
    return (1);
}