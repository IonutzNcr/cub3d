/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:51 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:44:02 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag(const char *s, va_list vlist, ssize_t *t)
{
	if (*s == 'c')
		ft_write_c(va_arg(vlist, int), t);
	if (*s == 's')
		ft_write_s(va_arg(vlist, char *), t);
	if (*s == 'd' || *s == 'i')
		ft_putnbr_base_fd(1, va_arg(vlist, int), "0123456789", t);
	if (*s == 'u')
		ft_putnbr_base_fd_u(1, va_arg(vlist, unsigned long), "0123456789", t);
	if (*s == 'p')
		ft_write_p(va_arg(vlist, void *), t);
	if (*s == 'X')
		ft_putnbr_base_fd_u(1, va_arg(vlist, int), "0123456789ABCDEF", t);
	if (*s == 'x')
		ft_putnbr_base_fd_u(1, va_arg(vlist, int), "0123456789abcdef", t);
	if (*s == '%')
	{
		write(1, "%", 1);
		*t += 1;
	}
	if (*s == '\0')
		return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	vlist;
	size_t	i;
	ssize_t	k;

	va_start(vlist, s);
	k = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
			ft_flag(&s[++i], vlist, &k);
		else
		{
			write(1, &s[i], 1);
			k++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	va_end(vlist);
	return (k);
}
