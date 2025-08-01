/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:20:29 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/15 17:44:52 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n-- && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (*--s1 - *--s2);
	if (*s1 < 0 || *s2 < 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (*s1 - *s2);
}

/* int main()
 {
		printf("%d : %d\n", ft_strncmp("ionut","ianut", 3),
			strncmp("ionut","ianut", 3));
		printf("%d : %d\n", ft_strncmp("ionut cel mai mare","ionut cel mai mar",
				40), strncmp("ionut cel mai mare","ionut cel mai mar", 40));
		printf("%d : %d\n", ft_strncmp("ionut","ianut", 1),
			strncmp("ionut","ianut", 1));
			printf("%d : %d\n", ft_strncmp("ionut","ianut", 0),
				strncmp("ionut","ianut", 0));
		printf("%d : %d\n", ft_strncmp("a","a",1), strncmp("a","a",1));
		printf("%d : %d\n", ft_strncmp("Tripouille","Tripouillex",42),
			strncmp("Tripouille","Tripouillex",42));
	printf("%d \n", ft_strncmp("1234", "1235", 3) == 0);
	printf("%d\n",ft_strncmp("test\200", "test\0", 6));

	printf("%d\n",strncmp("test\200", "test\0", 6));
 }*/
