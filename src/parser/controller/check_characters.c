/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:57:59 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 00:58:04 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_invalid_ch(char ch)
{
	if (ch == '1' || ch == '0' || ch == 'N' || ch == 'S' || ch == 'E'
		|| ch == 'W')
		return (0);
	return (1);
}

static int	is_player(char ch)
{
	if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		return (1);
	return (0);
}

int	check_characters(void)
{
	int		cply;
	int		k;
	int		i;
	char	*row;

	i = 0;
	k = count_elements(*sgt_map());
	cply = 0;
	while (i < k)
	{
		row = *get_row(i++);
		while (row && *row)
		{
			if (is_invalid_ch(*row) && set_sgt_error(INV_CH))
				// invalid character in map
				return (*sgt_error());
			if (is_player(*row))
				cply++;
			if (cply > 1 && set_sgt_error(PLY_NB)) // too many player
				return (*sgt_error());
			row++;
		}
	}
	if (cply == 0 && set_sgt_error(NO_PLY)) // No player detected
		return (*sgt_error());
	return (0);
}
