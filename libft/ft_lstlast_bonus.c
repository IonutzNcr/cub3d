/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:30:30 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/18 09:31:10 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return (0);
	next = lst->next;
	if (!next)
		return (lst);
	while (next->next)
		next = next->next;
	return (next);
}
