#include "hashtable.h"

// purge* : compare chaque case avec ses cases de collision et les 5 cases suivants( en utilisant les quatre distances ) en supprimant la case dupliquée.
// les distances avec lesquelles on va travailler sont : Livenshtein, Jaro_Winkle, Soundex et n-gram


                                       /***********************************************************************/
                                       /*                  en utilisant la distance Jaro_Winkler              */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*          le seuil ε au delà duquel deux tokens sont considérés comme équivalent pour la distance de Jaro_Winkler est 0.84          */
    /**************************************************************************************************************************************/


void	purgeJaroWinkler(char	*file_name)
{
	HashTable	**data_table;
	HashTable	*temp;
	HashTable	*temp1;
	int			iterator1;
	int			iterator2;
	int			tab_length;
	char		*mot1;
	char		*mot2;


	iterator1 = 0;
	tab_length = line_count(file_name);
	if (!(data_table = MappingToHashTable(file_name)))
		return;
	while (iterator1 < tab_length - 1)
	{
		temp = data_table[iterator1];
		while (temp->next != NULL)
		{
			temp1 = temp->next;
			while (temp1 != NULL)
			{
				if (!is_line_empty(temp->mot) && !is_line_empty(temp1->mot))
				{
					if (JaroWinkler(temp->mot, temp1->mot) >= 0.84){
						strcpy(temp1->mot, "\n");
					}
				}
				temp1 = temp1->next;
			}
			temp=temp->next;
		}
		iterator2 = iterator1 + 1;
		while(iterator2 - iterator1 <= 5 && iterator2 < tab_length)
		{
			mot1 = strdup(data_table[iterator1]->mot);
			mot2 = strdup(data_table[iterator2]->mot);
			if (!is_line_empty(mot1) && !is_line_empty(mot2))
			{
				if (JaroWinkler(mot1, mot2) >= 0.84)
					strcpy(data_table[iterator2]->mot, "\n");
			}
			iterator2++;
		}
		iterator1++;
	}
	
	purge(file_name, data_table);
}


                                       /***********************************************************************/
                                       /*                  en utilisant la distance Levenshtein              */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*             2 Tokens sont considérés similaires si la distance de Levenshtein entre eux est superieure ou egale à 0.8              */
    /**************************************************************************************************************************************/


void	purgeLevenshtein(char	*file_name)
{
	HashTable	**data_table;
	int		iterator1;
	int		iterator2;
	int		tab_length;
	float	distance;
	float	decimal;
	HashTable *temp;
	HashTable *temp1;

	iterator1 = 0;
	tab_length = line_count(file_name);
	if (!(data_table = MappingToHashTable(file_name)))
		return;
	while (iterator1 < tab_length - 1)
	{
		temp = data_table[iterator1];
		while (temp->next != NULL)
		{
			temp1 = data_table[iterator1]->next;
			while (temp1->next != NULL)
			{
				if (!is_line_empty(temp->mot) && !is_line_empty(temp1->mot))
				{
					decimal = (float)(ft_max(strlen(temp->mot), strlen(temp1->mot)));
					distance = (1-(levenshtein(temp->mot, strlen(temp->mot), temp1->mot, strlen(temp1->mot))/decimal));
					if (distance >= 0.8)
						strcpy(temp1->mot, "\n");
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
		iterator2 = iterator1 + 1;
		while(iterator2 - iterator1 <= 5 && iterator2 < tab_length)
		{
			if (!is_line_empty(data_table[iterator1]->mot) && !is_line_empty(data_table[iterator2]->mot))
			{
				decimal = (float)(ft_max(strlen(data_table[iterator1]->mot), strlen(data_table[iterator2]->mot)));
				distance = (1-(levenshtein(data_table[iterator1]->mot, strlen(data_table[iterator1]->mot), data_table[iterator2]->mot, strlen(data_table[iterator2]->mot))/decimal));
				if (distance >= 0.8)
					strcpy(data_table[iterator2]->mot, "\n");
			}
			iterator2++;
		}
		iterator1++;
	}
	
	purge(file_name, data_table);
}



                                       /***********************************************************************/
                                       /*                  en utilisant la distance Soundex              */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*           					  2 Tokens sont considérés similaires leurs code Soundex sont identiques   			           		  */
    /**************************************************************************************************************************************/


void	purgeSoundex(char	*file_name)
{
	HashTable	**data_table;
	char		*term1;
	char		*term2;
	int			iterator1;
	int			iterator2;
	int			tab_length;
	HashTable	*temp;
	HashTable	*temp1;

	iterator1 = 0;
	tab_length = line_count(file_name);
	if (!(data_table = MappingToHashTable(file_name)))
		return ;
	while (iterator1 < tab_length - 1)
	{
		temp = data_table[iterator1];
		while (temp->next != NULL)
		{
			temp1 = data_table[iterator1]->next;
			while (temp1->next != NULL)
			{
				init();
				if (!is_line_empty(temp->mot) && !is_line_empty(temp1->mot))
				{
					term1 = strdup(soundex(temp->mot));
					term2 = strdup(soundex(temp1->mot));
					if (!strcmp(term1, term2))
						strcpy(temp1->mot, "\n");
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
		iterator2 = iterator1 + 1;
		while(iterator2 - iterator1 <= 5  && iterator2 < tab_length)
		{
			init();
			if (!is_line_empty(data_table[iterator1]->mot) && !is_line_empty(data_table[iterator2]->mot))
			{
				term1 = strdup(soundex(data_table[iterator1]->mot));
				term2 = strdup(soundex(data_table[iterator2]->mot));
				if (!strcmp(term1, term2))
					strcpy(data_table[iterator2]->mot, "\n");
			}
			iterator2++;
		}
		iterator1++;
	}
	purge(file_name, data_table);
}


void	purge_N_Gram(char	*file_name)
{
	int		iterator1;
	int		iterator2;
	int		tab_length;
	char *mot;
	HashTable 	**data_table;
	HashTable	*temp;
	HashTable	*temp1;

	iterator1 = 0;
	tab_length = line_count(file_name);
	if (!(data_table = MappingToHashTable(file_name)))
		return;
	while (iterator1 < tab_length - 1)
	{
		temp = data_table[iterator1];
		while (temp->next != NULL)
		{
			temp1 = data_table[iterator1]->next;
			while (temp1->next != NULL)
			{
				if (!is_line_empty(temp->mot) && !is_line_empty(temp1->mot))
				{
					if (ngram_distance(temp->mot, temp1->mot, 1) >= 0.75)
						strcpy(temp1->mot, "\n");
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
		iterator2 = iterator1 + 1;
		while(iterator2 - iterator1 <= 5  && iterator2 < tab_length)
		{
			if (!is_line_empty(data_table[iterator1]->mot) && !is_line_empty(data_table[iterator2]->mot))
			{
				if (ngram_distance(data_table[iterator1]->mot, data_table[iterator2]->mot, 1) >= 0.75)
					strcpy(data_table[iterator2]->mot, "\n");
			}
			iterator2++;
		}
		iterator1++;
	}
	
	purge(file_name, data_table);
}



void	purge(char *file_name, HashTable	**data_table)
{
	int		file_descriptor;
	int		iterator;
	int		number_of_lines;

	iterator = 0;
	number_of_lines = line_count(file_name);
	remove(file_name);
	file_descriptor = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	while (iterator < number_of_lines)
	{
		while(data_table[iterator]->next != NULL)
		{
			if (is_line_empty(data_table[iterator]->mot) == 0)
				ft_putendl_fd(data_table[iterator]->mot, file_descriptor);
			data_table[iterator] = data_table[iterator]->next;
		}
		iterator++;
	}
	close(file_descriptor);
	free_array(data_table, number_of_lines);
}
