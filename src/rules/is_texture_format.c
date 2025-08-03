/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:55:22 by yoyo              #+#    #+#             */
/*   Updated: 2025/08/03 17:04:31 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* 
    Check if the format for the texture element is right
    return 1 if is good
    retunr 0 if is bad
*/
int is_texture_NO(char *line)
{
    while (*line == ' ')
        line++;
    if (ft_strncmp(line, "NO", 2))
        return (0);
    line += 2;
    while (*line == ' ')
        line++;
    if (!*line)
        return (0);
    if (ft_strncmp(line, "./", 2) || ft_strncmp(line, "/", 1))
        return (0);
    if (!ft_strncmp(line, "./", 2))
        line+=2;
    else if (!ft_strncmp(line, "/", 1))
        line+=1;
    while(!is_invalid_space(*line))
        line++;
    if (!*line)
        return (1);
    return (0);
}
/* 
    Check if the format for the texture element is right
    return 1 if is good
    retunr 0 if is bad
*/
int is_texture_SO(char *line)
{
    while (*line == ' ')
        line++;
    if (ft_strncmp(line, "SO", 2))
        return (0);
    line += 2;
    while (*line == ' ')
        line++;
    if (!*line)
        return (0);
    if (ft_strncmp(line, "./", 2) || ft_strncmp(line, "/", 1))
        return (0);
    if (!ft_strncmp(line, "./", 2))
        line+=2;
    else if (!ft_strncmp(line, "/", 1))
        line+=1;
    while(!is_invalid_space(*line))
        line++;
    if (!*line)
        return (1);
    return (0);
}
/* 
    Check if the format for the texture element is right
    return 1 if is good
    retunr 0 if is bad
*/
int is_texture_WE(char *line)
{
    while (*line == ' ')
        line++;
    if (ft_strncmp(line, "WE", 2))
        return (0);
    line += 2;
    while (*line == ' ')
        line++;
    if (!*line)
        return (0);
    if (ft_strncmp(line, "./", 2) || ft_strncmp(line, "/", 1))
        return (0);
    if (!ft_strncmp(line, "./", 2))
        line+=2;
    else if (!ft_strncmp(line, "/", 1))
        line+=1;
    while(!is_invalid_space(*line))
        line++;
    if (!*line)
        return (1);
    return (0);
}
/* 
    Check if the format for the texture element is right
    return 1 if is good
    retunr 0 if is bad
*/
int is_texture_EA(char *line)
{
    while (*line == ' ')
        line++;
    if (ft_strncmp(line, "EA", 2))
        return (0);
    line += 2;
    while (*line == ' ')
        line++;
    if (!*line)
        return (0);
    if (ft_strncmp(line, "./", 2) || ft_strncmp(line, "/", 1))
        return (0);
    if (!ft_strncmp(line, "./", 2))
        line+=2;
    else if (!ft_strncmp(line, "/", 1))
        line+=1;
    while(!is_invalid_space(*line))
        line++;
    if (!*line)
        return (1);
    return (0);
}
