/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:56:54 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 00:57:00 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	asset_checker(t_task *liste, char *line)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (liste[i].func(line))
		{
			if (liste[i].done && set_sgt_error(E_DUPLI)) // duplicata error
				return (*sgt_error());
			else
			{
				liste[i].done = 1;
				return (0);
			}
		}
		else
			continue ;
	}
	set_sgt_error(INV_LN); // invalid line
	return (*sgt_error());
}
