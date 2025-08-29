/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:57:16 by yoyo              #+#    #+#             */
/*   Updated: 2025/08/30 00:12:35 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

int   main(int argc, char **argv, char **env)
{
    if (parser(argc, argv, env))
        return (1);
    if(get_player_info())
    {
        printf("frerot\n");
        return (1);
    }
    t_player *player = sgt_player();
    printf("Player x: %f, y: %f, orientation: %f\n", player->x, player->y, player->orientation);
    free_singleton();
    printf("SUCCESS\n");
    return (0);
}