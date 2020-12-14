#include "hashtable.h"

void	free_array(HashTable	**tab_to_free, int size)
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

static char 	**allocate_table(int number_of_lines, int *characters_data)
{
	char	**returned_table; // la structure de donées (tableau dynamique) qu'on va allouer et retourner
	int		iterator;  // un iterateur pour parcourir le tableau

	iterator = 0;
	if (!(returned_table = (char**)malloc(sizeof(char*) * (number_of_lines + 1))))
		return (NULL);
	while (iterator < number_of_lines)
	{
		if (!(returned_table[iterator] = (char*)malloc(sizeof(char) * (characters_data[iterator] + 1))))
			return (NULL);
		iterator++;
	}
	returned_table[iterator] = strdup("");
	free(characters_data);
	return (returned_table);
}

int calculehash(char *mot, int tailletable)
{
    int i = 0, nombreHashe = 0;

    while(i < strlen(mot))
    {
        nombreHashe += (int)mot[i];
        i++;
    }
    nombreHashe = nombreHashe % tailletable;
    return nombreHashe;
}

void ajoutMot(HashTable **table, char *mot, int tailletable)
{
    int indice;

    indice = calculehash(mot, tailletable);
    HashTable *nmot;
    HashTable *nmot1;
    nmot = (HashTable *)malloc(sizeof(HashTable));
    nmot1 = (HashTable *)malloc(sizeof(HashTable));
    nmot->mot=strdup(mot);
    nmot->next=NULL;
    if(strcmp(table[indice]->mot,"") == 0)
        table[indice] = nmot;
    else
    {
        nmot1 = table[indice];
        while(nmot1->next != NULL)
            nmot1 = nmot1->next;
        nmot1->next = nmot;
    }
}

HashTable **MappingToHashTable(char *file_name)
{
    HashTable   **table;
	char	    **data_table; // la structure de donées avec laquelle on va travailler
	int		    iterator;  // un iterateur pour parcourir le tableau
	int 	    file_descriptor;
	int		    number_of_lines;
	int		    *characters_data;
    int         i;

    i = 0;
	iterator = 0;
	file_descriptor = open(file_name, O_RDONLY);
	number_of_lines = line_count(file_name);
	characters_data = characters_count(file_name);
	if(!(data_table = allocate_table(number_of_lines, characters_data)))
		return (NULL);
	while (get_next_line(file_descriptor, &data_table[iterator]) > 0)
		iterator++;
	close(file_descriptor);
    table = (HashTable **)malloc(sizeof(HashTable*)*number_of_lines);
    while (i < number_of_lines)
    {
        table[i] = (HashTable *)malloc(sizeof(HashTable));
        table[i]->mot = strdup("");
        table[i]->next = NULL;
        i++;
    }
    i = 0;
    while(i < number_of_lines)
    {
        ajoutMot(table, data_table[i],number_of_lines);
        i++;
    }
    free(characters_data);
	return (table);
}