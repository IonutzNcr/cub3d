/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionut <ionut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:11:07 by inicoara          #+#    #+#             */
/*   Updated: 2025/06/14 03:41:01 by ionut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isalpha(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	return (0);
}

static int	ft_pow(int base, int pow)
{
	int	res;

	res = 1;
	if (base == 0)
		return (0);
	if (pow == 0)
		return (1);
	while (pow--)
		res *= base;
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	i = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
		if (i++ == 1)
			return (0);
	else if (*nptr++ == '-')
		sign = -1;
	i = 0;
	if (ft_isalpha(*nptr))
		return (0);
	while (ft_isdigit(*nptr++))
		i++;
	nptr -= i + 1;
	while (ft_isdigit(*nptr))
		res += ((*nptr++ - '0') * ft_pow(10, --i));
	return (res * sign);
}
