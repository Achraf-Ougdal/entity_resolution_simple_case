#include "libft.h"

int		is_line_empty(char *line)
{
	int iterator;
	int line_length;

	iterator = 0;
	line_length = strlen(line);
	while (iterator < line_length)
	{
		if (!(line[iterator] == '\0' || line[iterator] == ' ' || line[iterator] == '\n' || line[iterator] == '\t'||
			 line[iterator] == '\v' || line[iterator] == '\f' || line[iterator] == '\r'))
			return (0);
		iterator++;
	}
	return (1);
}