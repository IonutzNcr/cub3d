/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:36:37 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:44:18 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_putnbr_base_fd_u(int fd, unsigned int nb, char *base, ssize_t *t)
{
	char	digit;

	if (nb < (unsigned int)ft_strlen(base))
	{
		digit = base[nb];
		write(fd, &digit, 1);
		*t += 1;
		return ;
	}
	ft_putnbr_base_fd_u(fd, nb / (unsigned int)ft_strlen(base), base, t);
	ft_putnbr_base_fd_u(fd, nb % (unsigned int)ft_strlen(base), base, t);
	return ;
}

void	ft_putnbr_base_fd(int fd, int nb, char *base, ssize_t *t)
{
	char	digit;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*t += 11;
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		*t += 1;
	}
	if (nb < ft_strlen(base))
	{
		digit = base[nb];
		write(fd, &digit, 1);
		*t += 1;
		return ;
	}
	ft_putnbr_base_fd(fd, nb / ft_strlen(base), base, t);
	ft_putnbr_base_fd(fd, nb % ft_strlen(base), base, t);
	return ;
}

void	ft_putnbr_base_fd_ptr(int fd, uintptr_t nb, char *base, ssize_t *t)
{
	char	digit;

	if (nb < (uintptr_t)ft_strlen(base))
	{
		digit = base[nb];
		write(fd, &digit, 1);
		*t += 1;
		return ;
	}
	ft_putnbr_base_fd_ptr(fd, nb / ft_strlen(base), base, t);
	ft_putnbr_base_fd_ptr(fd, nb % ft_strlen(base), base, t);
	return ;
}
