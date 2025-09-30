/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:57:30 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 00:57:36 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	asset_parser(t_task liste[6], char *line)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (liste[i].done == 1)
		{
			if (liste[i].parse(line))
				return (*sgt_error());
			liste[i].done++;
			return (0);
		}
		i++;
	}
	set_sgt_error(E_DUPLI); // asset parser error means duplicata i guess...
	return (*sgt_error());
}
