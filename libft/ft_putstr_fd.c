/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:12 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:17:14 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write(fd, s, l);
	return ;
}

// int main()
// {
//     ft_putstr_fd("test de test", 1);
// }
