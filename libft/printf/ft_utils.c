/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:27:31 by inicoara          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:04 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_c(char c, ssize_t *n)
{
	write(1, &c, 1);
	*n += 1;
	return ;
}

void	ft_write_s(char *s, ssize_t *n)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*n += 6;
		return ;
	}
	ft_putstr_fd(s, 1);
	*n += ft_strlen(s);
	return ;
}

void	ft_write_p(void *ptr, ssize_t *n)
{
	if (!ptr)
	{
		write (1, "(nil)", 5);
		*n += 5;
		return ;
	}
	write(1, "0x", 2);
	*n += 2;
	ft_putnbr_base_fd_ptr(1, (uintptr_t)ptr, "0123456789abcdef", n);
}
