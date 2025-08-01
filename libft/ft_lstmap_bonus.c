/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:25:56 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/18 09:32:13 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

t_list	*ft_clear_return0(t_list **head, char *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(head, del);
	return (NULL);
}

t_list	*ft_del_return0(char *content, void (*del)(void *))
{
	del(content);
	return (NULL);
}

t_list	*ft_free_head(t_list **head)
{
	free(*head);
	return (0);
}

void	ft_swap_list(t_list **prev, t_list **node, t_list **lst)
{
	(*prev)->next = *node;
	*lst = (*lst)->next;
	*prev = *node;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*previous;
	t_list	*nwnode;
	char	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	head = ft_lstnew(content);
	if (!head)
		return (ft_del_return0(content, del));
	if (!head->content)
		return (ft_free_head(&head));
	previous = head;
	while (lst->next)
	{
		content = f(lst->next->content);
		if (!content)
			return (ft_clear_return0(&head, content, del));
		nwnode = ft_lstnew(content);
		if (!nwnode)
			return (ft_clear_return0(&head, content, del));
		ft_swap_list(&previous, &nwnode, &lst);
	}
	return (head);
}
