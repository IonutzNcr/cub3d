#include "checker.h"

int	map_parser(char *line)
{
	if (add_line(line) && sgt_error(10)) // fail malloc
		return (*sgt_error());
	return (0);
}