/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:11:22 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:11:24 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		*(unsigned char *)s++ = '\0';
}

// int main()
// {
//     int i = 0;
//     int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//     int parr[10] = {0,1,2,3,4,5,6,7,8,9};
//     float arr2[10] = {0.2,1.1,2.2,3.4,4.1,5.1,6.1,7.1,8.1,9.1};
//     float parr2[10] = {0.2,1.1,2.2,3.4,4.1,5.1,6.1,7.1,8.1,9.1};
//     ft_bzero(arr,  10 * sizeof(int));
//     bzero(parr, 10 * sizeof(int));
//     ft_bzero(arr2,  10 * sizeof(int));
//     bzero(parr2, 10 * sizeof(int));
//     while(i < 10)
//     {
//         printf("arr: %d parr: %d\n", arr[i], parr[i]);
//         printf("arr2: %f parr2: %f\n", arr2[i], parr2[i]);
//         if (arr[i] != parr[i])
//             printf("error\n");
//         if (arr2[i] != parr2[i])
//             printf("error\n");
//         i++;
//     }
// }
