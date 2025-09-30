#include "checker.h"

/*
	return 1 if is good
	retunr 0 if is bad
*/
static int	check_values_rgb(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strlen(argv[i]) || ft_strlen(argv[i]) > 3)
			return (0);
		if (!ft_isdigit(argv[i][0]) || !ft_isdigit(argv[i][0])
			|| !ft_isdigit(argv[i][0]))
			return (0);
		if (ft_atoi(argv[i]) < 0 || ft_atoi(argv[i]) > 255)
			return (0);
		i++;
	}
	return (1);
}

/*
	return 0 if everything is good
	return 1 if error found
	****set error singleton on error****bad idea...
*/
static int	check_rgb(char *line)
{
	char	**rgb;
	int		i;
	char	tmp;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	tmp = line[i];
	line[i] = '\0';
	rgb = ft_split(line, ',');
	line[i] = tmp;
	if (!rgb)
		return (1);
	if (count_elements(rgb) != 3)
		return (free_split(rgb), 1);
	if (!check_values_rgb(rgb))
		return (free_split(rgb), 1);
	free_split(rgb);
	return (0);
}

/*
	Return 0 if is bad
	Return 1 if is good
*/
int	is_ceiling(char *line)
{
	while (*line && *line == ' ')
		line++;
	if (ft_strncmp(line, "C", 1))
		return (0);
	line += 1;
	while (*line && *line == ' ')
		line++;
	if (!*line)
		return (0);
	if (check_rgb(line))
		return (0);
	while (*line != ' ' && *line != '\0')
		line++;
	while (!is_invalid_space(*line) && *line != '\0')
		line++;
	if (!*line)
		return (1);
	return (0);
}
/*
	Return 0 if is bad
	Return 1 if is good
*/
int	is_floor(char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "F", 1))
		return (0);
	line += 1;
	while (*line == ' ')
		line++;
	if (!*line)
		return (0);
	if (check_rgb(line))
		return (0);
	while (*line != ' ' && *line != '\0')
		line++;
	while (!is_invalid_space(*line) && *line != '\0')
		line++;
	if (!*line)
		return (1);
	return (0);
}
