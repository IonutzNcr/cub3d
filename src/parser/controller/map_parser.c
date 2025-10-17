/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:59:25 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/17 10:26:33 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	map_parser(char *line)
{
	if (add_line(line) && set_sgt_error(10))
		return (*sgt_error());
	return (0);
}
