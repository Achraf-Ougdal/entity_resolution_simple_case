#include "libft.h"

//file_descriptor c'est le "file descriptor" retourné par la fonction "Open"

// cette fonction calcule le nombre de lignes dans le fichier

int     line_count(char *file_name)
{
    char    buffer;
    int     count;
    int     file_descriptor;

    count = 0;
    file_descriptor = open(file_name, O_RDONLY);
    if (file_descriptor < 0 || read(file_descriptor, &buffer, 0) < 0 || read(file_descriptor, &buffer, 1) == 0)
    	return (0);
    if (buffer == '\n')
        count++;
    while (read(file_descriptor, &buffer, 1) > 0)
    {
        if (buffer == '\n')
            count++;
    }
    close(file_descriptor);
    return (++count);
}

// cette fonction fait le calcule de nombre  de caracteres de chaque ligne

int		*characters_count(char *file_name)
{
    char    buffer;
	int     count;
	int     iterator;
    int     file_descriptor;
    int     *data;

	count = 0;
	iterator = 0;
    file_descriptor = open(file_name, O_RDONLY);
	if (!(data = (int*)malloc(sizeof(int) *  line_count(file_name))))
        return (NULL);
	while (read(file_descriptor, &buffer, 1) > 0)
    {
        if (buffer != '\n')
            count++;
        else
        {
        	data[iterator] = count;
        	count = 0;
        	iterator++;
        }
    }
    data[iterator] = count;
    close(file_descriptor);
    return (data);
}
