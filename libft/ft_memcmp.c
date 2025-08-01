/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:15:31 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:15:33 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (0);
}

/* int main()
// {
//     int arr[5] = {1,2,3,4,5};
//     int parr[5] = {4,2,5,4,4};
//     char const arr2[5] =  {'i','o', 'n', 'u', 't'};
//     char const parr2[5] =  {'i','a', 'n', 'u', 't'};
//     printf("%d : %d\n", ft_memcmp("ionut","ianut", sizeof(char) * 5),
	memcmp("ionut","ianut", sizeof(char) * 5));
//     printf("diff: %d\n", (unsigned char)'o' - (unsigned char)'a');
//     printf("%d : %d\n", ft_memcmp("ionut cel mai mare","ionut cel mai mar",
		sizeof(char) * 10), memcmp("ionut cel mai mare","ionut cel mai mare",
		sizeof(char) * 10));
//     printf("%d : %d\n", ft_memcmp("ionut","ianut", 1),
	memcmp("ionut","ianut", 1));
//     printf("%d : %d\n", ft_memcmp("ionut","ianut", 0),
	memcmp("ionut","ianut", 0));
//     printf("%d : %d\n", ft_memcmp("a","a",1), memcmp("a","a", 1));
//     printf("%d \n", ft_memcmp(arr, parr, sizeof(int)*5));
//     printf("%d \n", memcmp(arr, parr, sizeof(int)*5));
//      printf("%d\n", ft_memcmp(arr2, parr2, sizeof(char)*5));
//      printf("%d\n", memcmp(arr, parr, sizeof(char)*5));
// }*/
