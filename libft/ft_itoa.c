/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:15:04 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:15:05 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_get_size_and_sign(int n, unsigned int *p, int *sign)
{
	int				i;
	unsigned int	positive_nb;

	if (n < 0)
	{
		*sign = -1;
		positive_nb = n * -1;
	}
	else
	{
		*sign = 1;
		positive_nb = n;
	}
	*p = positive_nb;
	i = 0;
	while (positive_nb)
	{
		positive_nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_str_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	p;
	int				sign;
	int				size;
	int				mod;
	char			*number;

	if (n == 0)
		return (ft_str_zero());
	size = ft_get_size_and_sign(n, &p, &sign);
	if (sign == -1)
		size++;
	number = (char *)malloc(sizeof(char) * (size + 1));
	if (!number)
		return (0);
	if (sign == -1)
		number[0] = '-';
	number[size] = '\0';
	while (p != 0)
	{
		mod = p % 10;
		number[size - 1] = mod + '0';
		size--;
		p /= 10;
	}
	return (number);
}

/* int main()
 {
//     printf("%s \n", ft_itoa(123));
//     printf("%s \n", ft_itoa(1));
//     printf("%s \n", ft_itoa(0));

//     printf("%s \n", ft_itoa(-56454654));
//      printf("%s \n", ft_itoa(-2147483648));
	char *test = ft_itoa(-12345);
	printf("test1 :-12345: %s\n", test);

	char *test2 = ft_itoa(-2147483648);
	printf("test2 :-2147483648: %s\n", test2);

 }*/
