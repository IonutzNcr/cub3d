/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:23:26 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:43:33 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_write_c(char c, ssize_t *n);
void	ft_write_s(char *s, ssize_t *n);
void	ft_putnbr_base_fd_ptr(int fd, uintptr_t nb, char *base, ssize_t *t);
void	ft_putnbr_base_fd_u(int fd, unsigned int nb, char *base, ssize_t *t);
void	ft_putnbr_base_fd(int fd, int nb, char *base, ssize_t *t);
void	ft_write_p(void *ptr, ssize_t *n);
#endif
