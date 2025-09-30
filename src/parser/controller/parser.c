/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:03:30 by leothoma          #+#    #+#             */
/*   Updated: 2025/10/01 01:03:34 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parser(int argc, char *argv[], char *env[])
{
	int	*error;

	error = sgt_error();
	if (quick_verif(argc, argv, env))
		return (*error);
	if (hard_verif(argv))
		return (*error);
	return (0);
}
