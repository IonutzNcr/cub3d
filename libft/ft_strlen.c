/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:19:54 by inicoara          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:57 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	long unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int main()
// {
//     printf("%lu:%lu\n",
	ft_strlen("ksladjakfjskfjds;klfjksafjksdjfklsadjfskl;adfjas;"),
	strlen("ksladjakfjskfjds;klfjksafjksdjfklsadjfskl;adfjas;"));
//     printf("%lu:%lu\n", ft_strlen(" "), strlen(" "));
//     printf("%lu:%lu\n", ft_strlen(""), strlen(""));
// }*/
