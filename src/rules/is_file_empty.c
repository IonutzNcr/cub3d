/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:55:51 by yoyo              #+#    #+#             */
/*   Updated: 2025/07/29 18:56:06 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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