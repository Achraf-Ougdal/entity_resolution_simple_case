#include "set.h"

// allocate_table : fonction qui fait l'alocation du tableau avec lequel on va travailler 
//// l'allocation doit etre presice on alloue seulement les cases memoires qu'on a besoin d'allouer
//////exemple d'alllocation non precise : allouer un tableau  de 1000 cases alors que le fichier contient seulement 14 lignes 
//////// le tableau de deux dimentions retourné par cette fonction sera de taille numero_de_lignes + 1 (un mot par ligne, 14 lignes => 14 mots, la dernière case est reservée pour le caractere nul)
////////// chaque case du tableau est de taille nombre_de_caractere_de_la_ligne + 1

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

// mappintToSet : fonction qui lit un fichier et met chaque ligne dans une case du tableau de données
//// elle utilise la fonction get_next_line cette fonction prend en parametre le 'file descriptor' et l'edresse d'un pointeur sur une chaine de caractere
////// get_next_line lit le fichier et retourne une ligne du fichier , au cas ou on fait appel de cette fonction dans une boucle, elle retournera les lignes du fichier ligne par ligne
//////// alors mappingToSet met la ligne retournée par get_next_line dans la case correspondante dans le tableau de données

char			**MappingToSet(char *file_name)
{
	int		iterator;  // un iterateur pour parcourir le tableau
	int 	file_descriptor;
	int		number_of_lines;
	int		*characters_data;

	iterator = 0;
	file_descriptor = open(file_name, O_RDONLY);
	number_of_lines = line_count(file_name);
	characters_data = characters_count(file_name);
	if(!(data_table = allocate_table(number_of_lines, characters_data)))
		return (NULL);
	while (get_next_line(file_descriptor, data_table[iterator]) > 0)
		iterator++;
	close(file_descriptor);
	return (data_table);
}