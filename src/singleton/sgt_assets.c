/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:30:23 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 01:30:31 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	remove_assets(void)
{
	t_assets	*assets;

	assets = sgt_assets();
	if (assets->file_EA)
		free(assets->file_EA);
	if (assets->file_NO)
		free(assets->file_NO);
	if (assets->file_SO)
		free(assets->file_SO);
	if (assets->file_WE)
		free(assets->file_WE);
}

t_assets	*sgt_assets(void)
{
	static t_assets	assets;

	return (&assets);
}
