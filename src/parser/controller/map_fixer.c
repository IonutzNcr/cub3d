#include "checker.h"

static int	find_max_lenght(char **map)
{
	int	max;
	int	l;

	max = 0;
	while (map && *map)
	{
		l = ft_strlen(*map);
		if (l > max)
			max = l;
		map++;
	}
	return (max);
}

static void	fill_row(char *dest, int max)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (i < max)
		dest[i++] = '1';
	dest[i] = '\0';
}

static int	fix_length(void)
{
	int		max_lenght;
	char	**map;
	char	*row;
	int		curr_lenght;

	map = *sgt_map();
	max_lenght = find_max_lenght(map);
	while (*map)
	{
		curr_lenght = ft_strlen(*map);
		row = ft_remalloc(*map, max_lenght + 1, curr_lenght + 1);
		if (!row && set_sgt_error(12)) // malloc fail...
			return (12);
		fill_row(row, max_lenght);
		free(*map);
		*map = row;
		map++;
	}
	return (0);
}

/*
	REPLACE space by 1 inside the map...
*/
static void	replace_space(void)
{
	char	**map;
	char	*row;

	map = *sgt_map();
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row == ' ')
				*row = '1';
			row++;
		}
		map++;
	}
}

/*
	ret error if malloc problem or other problem..
	ret 0 if success
*/
int	map_fixer(void)
{
	replace_space();
	if (fix_length())
		return (*sgt_error());
	return (0);
}