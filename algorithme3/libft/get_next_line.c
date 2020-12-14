#include "libft.h"

int		get_next_line(int file_descriptor, char **line)
{
	static char		*holder;
	char			buff[BUFFER_SIZE + 1];
	int				bytes_read;
	int				i;

	if (file_descriptor < 0 || line == NULL || read(file_descriptor, buff, 0) < 0 || file_descriptor >= 4864)
		return (-1);
	if (!holder)
		holder = strdup("");
	while ((bytes_read = read(file_descriptor, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		holder = ft_strjoin(holder, buff);
		if (strchr(buff, '\n'))
			break;
	}
	i = 0;
	while (holder[i] != '\n' && holder[i] != '\0')
		i++;
	*line = ft_substr(holder, 0, i);
	if (strlen(holder) == 0 && i == 0 && bytes_read == 0)
		return (0);
	holder = strdup(holder + i + 1);
	return (1);
}
