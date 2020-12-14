#ifndef SET_H
#define SET_H

#include "./libft/libft.h"

char	**data_table;  // la structure de donées (tableau dynamique) qu'on va allouer et retourner
char	**MappingToSet(char *file_name);
void	purgeJaroWinkler(char *file_name);
void	purgeLevenshtein(char	*file_name);
void	purgeSoundex(char	*file_name);
void	purge_N_Gram(char	*file_name);
void	purge(char *file_name,char	**data_table);

#endif