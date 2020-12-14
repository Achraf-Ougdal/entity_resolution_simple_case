#ifndef SET_H
#define SET_H

# include "./libft/libft.h"

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdio.h>

char 			**Tas;

void    		ft_swap(char **tab, int i, int j);
void    		ajout_tas(char **tas, char *string, int p);
char    		*extraire_min(char **tas, int last);
char            **LireToTas(char *file_name);
void        	MappingToTable(char *file_name);
void			purgeJaroWinkler(char	*file_name);
void			purgeLevenshtein(char	*file_name);
void			purgeSoundex(char	*file_name);
void			purge_N_Gram(char	*file_name);
void			purge(char *file_name, char	**Tas);

#endif