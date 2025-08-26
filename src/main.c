/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:57:16 by yoyo              #+#    #+#             */
/*   Updated: 2025/08/26 05:16:44 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "minimap.h"
#include <mlx.h>

int   main(int argc, char **argv, char **env)
{
    if (parser(argc, argv, env))
        return (1);
    /* free_singleton(); */
    printf("SUCCESS\n");
   /*  void	*mlx; */
  /*   mlx = mlx_init(); */
   /*  printf("DONE MLX\n"); */
    init_mini_map();
    printf("DONE MLX2\n");
    return (0);
}