/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyo <yoyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:57:16 by yoyo              #+#    #+#             */
/*   Updated: 2025/08/08 21:36:00 by yoyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include <mlx.h>

int   main(int argc, char **argv, char **env)
{
    if (parser(argc, argv, env))
        return (1);
    free_singleton();
    printf("SUCCESS\n");
    void	*mlx;
    mlx = mlx_init();
    printf("DONE MLX\n");
    return (0);
}