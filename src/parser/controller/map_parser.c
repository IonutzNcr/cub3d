/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:59:25 by leothoma          #+#    #+#             */
/*   Updated: 2025/11/06 00:41:23 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_main.h"

int	map_parser(char *line)
{
	if (check_line(line) && set_sgt_error(INV_CH))
		return (*sgt_error());
	if (add_line(line) && set_sgt_error(F_MALL))
		return (*sgt_error());
	return (0);
}
