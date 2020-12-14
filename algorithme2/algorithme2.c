#include "set.h"

// purge* : compare chaque case avec les autres cases ( en utilisant les quatre distances ) en supprimant la case dupliquée.
// les distances avec lesquelles on va travailler sont : Livenshtein, Jaro_Winkle, Soundex et n-gram


                                       /***********************************************************************/
                                       /*                  en utilisant la distance Jaro_Winkler              */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*          le seuil ε au delà duquel deux tokens sont considérés comme équivalent pour la distance de Jaro_Winkler est 0.84          */
    /**************************************************************************************************************************************/


void	purgeJaroWinkler(char	*file_name)
{
	int		iterator1;
	int		iterator2;
	int		tab_length;

	iterator1 = 0;
	tab_length = line_count(file_name);
	MappingToTable(file_name);
	while (iterator1 < tab_length - 1)
	{
		iterator2 = iterator1 + 1;
		while (iterator2 < tab_length)
		{
			if (JaroWinkler(Tas[iterator1], Tas[iterator2]) >= 0.84)
			{
				strcpy(Tas[iterator2], "\n");
				iterator2++;
			}
			else
				break;
		}
		iterator1++;
	}
	purge(file_name, Tas);
}


                                       /***********************************************************************/
                                       /*                  en utilisant la distance Levenshtein               */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*             2 Tokens sont considérés similaires si la distance de Levenshtein entre eux est superieure ou egale à 0.8              */
    /**************************************************************************************************************************************/


void	purgeLevenshtein(char	*file_name)
{
	int		iterator1;
	int		iterator2;
	int		tab_length;
	float	distance;
	float	decimal;

	iterator1 = 0;
	tab_length = line_count(file_name);
	MappingToTable(file_name);
	while (iterator1 < tab_length - 1)
	{
		iterator2 = iterator1 + 1;
		while (iterator2 < tab_length)
		{
			decimal = (float)(ft_max(strlen(Tas[iterator2]), strlen(Tas[iterator1])));
			distance = (1-(levenshtein(Tas[iterator1], strlen(Tas[iterator1]), Tas[iterator2], strlen(Tas[iterator2]))/decimal));
			if (distance >= 0.8)
			{
				strcpy(Tas[iterator2], "\n");
				iterator2++;
			}
			else
				break;
		}
		iterator1++;
	}
	purge(file_name, Tas);
}


                                       /***********************************************************************/
                                       /*                  en utilisant la distance Soundex                   */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*           					  2 Tokens sont considérés similaires leurs code Soundex sont identiques   			           		  */
    /**************************************************************************************************************************************/

void	purgeSoundex(char	*file_name)
{
	char	*term1;
	char	*term2;
	int		iterator1;
	int		iterator2;
	int		tab_length;

	iterator1 = 0;
	tab_length = line_count(file_name);
	MappingToTable(file_name);
	while (iterator1 < tab_length - 1)
	{
		iterator2 = iterator1 + 1;
		while (iterator2 < tab_length)
		{
			init();
			term1 = strdup(soundex(Tas[iterator1]));
			term2 = strdup(soundex(Tas[iterator2]));
			if (!strcmp(term1, term2))
			{
				strcpy(Tas[iterator2], "\n");
				iterator2++;
			}
			else
				break;
		}
		iterator1++;
	}
	purge(file_name, Tas);
}

                                       /***********************************************************************/
                                       /*                  en utilisant la distance N_Gram     		          */
                                       /***********************************************************************/

    /**************************************************************************************************************************************/
    /*          le seuil ε au delà duquel deux tokens sont considérés comme équivalent pour la distance de N_Gram est 0.75          */
    /**************************************************************************************************************************************/


void	purge_N_Gram(char	*file_name)
{
	int		iterator1;
	int		iterator2;
	int		tab_length;

	iterator1 = 0;
	tab_length = line_count(file_name);
	MappingToTable(file_name);
	while (iterator1 < tab_length - 1)
	{
		iterator2 = iterator1 + 1;
		while (iterator2 < tab_length)
		{
			if (ngram_distance(Tas[iterator1], Tas[iterator2], 1) >= 0.75)
			{
				strcpy(Tas[iterator2], "\n");
				iterator2++;
			}
			else
				break;
		}
		iterator1++;
	}
	purge(file_name, Tas);
}


void	purge(char *file_name, char	**Tas)
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
		if (!is_line_empty(Tas[iterator]))
		{
			ft_putstr_fd(Tas[iterator], file_descriptor);
			if (iterator != number_of_lines - 1)
				ft_putchar_fd('\n', file_descriptor);
		}
		iterator++;
	}
	close(file_descriptor);
	free_array(Tas, number_of_lines);
}
