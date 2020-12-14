#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "./libft/libft.h"

typedef struct HashTable
{
	char *mot;
	struct HashTable *next;
} HashTable;

void	purgeJaroWinkler(char *file_name);
void	purgeLevenshtein(char	*file_name);
void	purgeSoundex(char	*file_name);
void	purge_N_Gram(char	*file_name);
void ajoutMot(HashTable **table, char *mot, int tailletable);
HashTable **MappingToHashTable(char *file_name);
void	purge(char *file_name, HashTable	**data_table);
void	free_array(HashTable	**tab_to_free, int size);
int 	calculehash(char *mot, int tailletable);

#endif