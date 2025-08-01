/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:46 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:16:47 by inicoara         ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write(fd, s, l);
	write(fd, "\n", 1);
	return ;
}

// int main()
// {
//     ft_putendl_fd("test de test", 1);
// }
