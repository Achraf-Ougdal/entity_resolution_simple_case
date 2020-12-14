#include "libft.h"

void	free_array(char	**tab_to_free, int size)
{
	int 	i;

	i = 0;
	while (i < size)
	{
		free(tab_to_free[i]);
		i++;
	}
	free(tab_to_free);
}