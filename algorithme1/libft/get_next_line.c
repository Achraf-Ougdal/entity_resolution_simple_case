#include "libft.h"

int				get_next_line(int file_descriptor, char *line)
{
	char	buffer;
	int		iterator;

	iterator = 0;
	if (file_descriptor < 0 || !line || read(file_descriptor, &buffer, 0) < 0)
		return (-1);
	while (read(file_descriptor, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			line[iterator] = '\0';
			return (1);
		}
		else
		{
			line[iterator] = buffer;
			iterator++;
		}
	}
	line[iterator] = '\0';
	return (0);
}