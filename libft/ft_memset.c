/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:16 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:16:18 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	void	*tmp;
	size_t	i;

	i = 0;
	tmp = s;
	while (i++ < n)
		*(unsigned char *)s++ = c;
	return (tmp);
}

// int main()
// {
//     int i = 0;
//     char carr[10] = {'0','1','2','3','4','5','6','7','8','9'};
//     char cparr[10] = {'0','1','2','3','4','5','6','7','8','9'};
//     int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//     int parr[10] = {0,1,2,3,4,5,6,7,8,9};
//     float arr2[10] = {0.2,1.1,2.2,3.4,4.1,5.1,6.1,7.1,8.1,9.1};
//     float parr2[10] = {0.2,1.1,2.2,3.4,4.1,5.1,6.1,7.1,8.1,9.1};
//     ft_memset(carr, 2, 10 * sizeof(char));
//     memset(cparr, 2, 10 * sizeof(char));
//     ft_memset(arr, 2, 10 * sizeof(int));
//     memset(parr, 2, 10 * sizeof(int));
//     ft_memset(arr, 2, 10 * sizeof(int));
//     memset(parr, 2, 10 * sizeof(int));
//     ft_memset(arr2, 1, 10 * sizeof(float));
//     memset(parr2, 1, 10 * sizeof(float));
//     while(i < 10)
//     {
//         printf("carr: %d cparr: %d\n", carr[i], cparr[i]);
//         printf("arr: %d parr: %d\n", arr[i], parr[i]);
//         printf("arr2: %f parr2: %f\n", arr2[i], parr2[i]);
//         if (arr[i] != parr[i])
//             printf("error\n");
//         if (arr2[i] != parr2[i])
//             printf("error\n");
//         i++;
//     }
// }
