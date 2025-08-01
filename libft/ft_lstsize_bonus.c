/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:10:18 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/18 09:18:36 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next;

	if (!lst)
		return (0);
	i = 1;
	next = lst->next;
	while (next)
	{
		i++;
		next = next->next;
	}
	return (i);
}
