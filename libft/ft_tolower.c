/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:47 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:21:48 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

// int main()
// {
//     int i = 0;

//     while (ft_tolower (i) == tolower(i) && i < 128)
//     {
//         i++;
//     }
//     printf("me:true %d: %d\n", ft_tolower (i), tolower(i) );
//     printf("i: %d\n", i);
// }
