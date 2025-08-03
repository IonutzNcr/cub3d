/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:55:51 by yoyo              #+#    #+#             */
/*   Updated: 2025/08/03 16:59:53 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
    verif if file is empty
    return 0 if everything is good 
    return 1 if file is empty
    used in quick verif
    ???should also be used in assets parse to check if xpm file is empty...
*/
int is_file_empty(char *file)
{
    int fd;
    int byte;
    char buf[2];

    fd = open(file, O_RDONLY);
    byte = read(fd, buf, 2);
    close(fd);
    if (byte == 0)
        reutrn (1);
    return (0);
}