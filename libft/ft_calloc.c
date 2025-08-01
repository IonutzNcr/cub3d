/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:11:35 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 14:11:37 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*dest;
	unsigned char	*ruh;
	size_t			total;

	total = nmemb * size;
	if (size != 0 && nmemb > ((size_t)-1 / size))
		return (NULL);
	dest = (void *)malloc(nmemb * size);
	if (!dest)
		return (0);
	ruh = (unsigned char *)dest;
	while (total--)
		*ruh++ = 0;
	return (dest);
}

/*int main() {
//     // Test with real calloc
//     size_t nmemb = 5;
//     size_t size = sizeof(int);

//     // Test with real calloc
//     int *arr_real = (int *)calloc(nmemb, size);
//     if (arr_real) {
//         printf("Real calloc: ");
//         for (size_t i = 0; i < nmemb; i++) {
//             printf("%d ", arr_real[i]);
//         }
//         printf("\n");
//         free(arr_real);
//     } else {
//         printf("Real calloc failed\n");
//     }

//     // Test with custom calloc (ft_calloc)
//     int *arr_custom = (int *)ft_calloc(nmemb, size);
//     if (arr_custom) {
//         printf("Custom calloc (ft_calloc): ");
//         for (size_t i = 0; i < nmemb; i++) {
//             printf("%d ", arr_custom[i]);
//         }
//         printf("\n");
//         free(arr_custom);
//     } else {
//         printf("Custom calloc failed\n");    }

//     return (0);
		printf("test the fck: %d\n", ft_calloc(-4, -4) == 0);
		printf("test the fck: %d\n", ft_calloc(-1, -1) == 0);
		printf("test the fck: %d\n", ft_calloc(-2, -2) == 0);
		printf("test the fck: %d\n", ft_calloc(-3, -3) == 0);
		printf("test the fck: %d\n", ft_calloc(-7, 7) == 0);
}*/
