/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:30:23 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/17 10:29:32 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	remove_assets(void)
{
	t_assets	*assets;

	assets = sgt_assets();
	if (assets->file_ea)
		free(assets->file_ea);
	if (assets->file_no)
		free(assets->file_no);
	if (assets->file_so)
		free(assets->file_so);
	if (assets->file_we)
		free(assets->file_we);
}

t_assets	*sgt_assets(void)
{
	static t_assets	assets;

	return (&assets);
}
