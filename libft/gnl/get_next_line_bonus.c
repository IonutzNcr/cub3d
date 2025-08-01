/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:41:22 by inicoara          #+#    #+#             */
/*   Updated: 2024/11/27 18:36:41 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_copy(char *str, char *buf, ssize_t rd)
{
	ssize_t	strsize;
	char	*copy;
	ssize_t	i;
	char	*tmp;

	tmp = "";
	if (!str)
		str = tmp;
	i = 0;
	strsize = 0;
	while (str[i++])
		strsize++;
	copy = malloc (strsize + rd + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (strsize--)
		copy[i++] = *str++;
	while (rd--)
		copy[i++] = *buf++;
	copy[i] = '\0';
	return (copy);
}

static char	*ft_read_once(char *ptr, int fd, ssize_t *r, int *error)
{
	ssize_t	rd;
	char	*buf;
	char	*line;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (*error = 1, ft_free(&ptr, 0));
	rd = read(fd, buf, BUFFER_SIZE);
	if (rd == -1)
	{
		*error = 1;
		return (ft_free(&buf, &ptr));
	}
	if (rd == 0)
	{
		free(buf);
		*r = 0;
		return (ptr);
	}
	line = ft_copy(ptr, buf, rd);
	if (!line)
		return (ft_free(&ptr, &buf));
	ft_free(&ptr, &buf);
	return (line);
}

static char	*ft_get_line(char *ptr)
{
	ssize_t	psx;
	ssize_t	i;
	char	*line;

	i = 0;
	psx = ft_index_line(ptr, '\n');
	if (psx == -1)
		return (NULL);
	while (i < psx + 1)
		i++;
	line = malloc (i + 1);
	if (!line)
		return (0);
	i = 0;
	while (i < psx + 1)
	{
		line[i] = ptr[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_substract(char *ptr, size_t psx, int *error)
{
	size_t	ptrsize;
	size_t	i;
	char	*rest;
	ssize_t	tmp;

	ptrsize = 0;
	i = 0;
	while (ptr[ptrsize])
		ptrsize++;
	if (ptrsize - psx == 0)
		return (ft_free(&ptr, 0));
	rest = malloc(ptrsize - psx + 1);
	if (!rest)
	{
		*error = 1;
		return (ft_free(&ptr, 0));
	}
	tmp = psx;
	while (i < ptrsize - psx)
		rest[i++] = ptr[tmp++];
	rest[i] = '\0';
	free(ptr);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*ptr[1024];
	char		*line;
	ssize_t		rd;	
	int			error;

	error = 0;
	rd = 1;
	while (!error && rd && ft_index_line(ptr[fd], '\n') == -1)
		ptr[fd] = ft_read_once(ptr[fd], fd, &rd, &error);
	if (ft_index_line(ptr[fd], '\n') != -1)
	{
		line = ft_get_line(ptr[fd]);
		if (!line)
			return (ft_free(&ptr[fd], 0));
		ptr[fd] = ft_substract(ptr[fd],
				ft_index_line(ptr[fd], '\n') + 1, &error);
		if (!ptr[fd] && error)
			return (ft_free(&line, 0));
		return (line);
	}
	line = ptr[fd];
	ptr[fd] = NULL;
	return (line);
}

/*int main(int argc, char **argv)
{
    int fd = open (argv[1], O_RDONLY);
    (void)argc;

    char *tmp = get_next_line(fd);
	printf("%s", tmp);
	if (tmp)
		free(tmp);
 
	tmp = get_next_line(fd);
	if (tmp)
		free(tmp);
	return (0);
}*/
