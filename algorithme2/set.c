#include "set.h"

void    ft_swap(char **tab, int i, int j)
{
    char    *tmp;

    tmp = strdup(tab[i]);
    free(tab[i]);
    tab[i] = strdup(tab[j]);
    free(tab[j]);
    tab[j] = strdup(tmp);
    free(tmp);
}

void    ajout_tas(char **tas, char *string, int p)
{
    int     iterator;

    tas[p] = strdup(string);
    iterator = p;
    while (iterator > 1 && strcmp(tas[iterator], tas[iterator / 2]) < 0)
    {
        ft_swap(tas, iterator, iterator/2);
        iterator = iterator / 2;
    }
}

char    *extraire_min(char **tas, int last)
{
    char    *min;
    int     iterator;

    min = strdup(tas[1]);
    free(tas[1]);
    tas[1] = strdup(tas[last]);
    last--;
    iterator = 1;
    while(iterator <= last / 2 && (strcmp(tas[iterator], tas[2 * iterator]) > 0 || strcmp(tas[iterator], tas[(2 * iterator) + 1]) > 0))
    {
        if (strcmp(tas[(2 * iterator) + 1], tas[2 * iterator]) > 0)
        {
            ft_swap(tas, iterator, 2 * iterator);
            iterator = iterator * 2;
        }
        else
        {
            ft_swap(tas, iterator, (2 * iterator) + 1);
            iterator =  (2 * iterator) + 1;
        }
    }
    return (min);
}

static char    **allocate_table(int number_of_lines, int *characters_data)
{
    char    **returned_table; // la structure de donées (tableau dynamique) qu'on va allouer et retourner
    int     iterator;  // un iterateur pour parcourir le tableau

    iterator = 0;
    if (!(returned_table = (char**)malloc(sizeof(char*) * (number_of_lines + 2))))
        return (NULL);
    returned_table[0] = strdup("");
    while (iterator < number_of_lines)
    {
        if (!(returned_table[iterator + 1] = (char*)malloc(sizeof(char) * (characters_data[iterator] + 1))))
            return (NULL);
        iterator++;
    }
    returned_table[iterator + 1] = strdup("");
    return (returned_table);
}
// mappintToSet : fonction qui lit un fichier et met chaque ligne dans une case du tableau de données
//// elle utilise la fonction get_next_line cette fonction prend en parametre le 'file descriptor' et l'edresse d'un pointeur sur une chaine de caractere
////// get_next_line lit le fichier et retourne une ligne du fichier , au cas ou on fait appel de cette fonction dans une boucle, elle retournera les lignes du fichier ligne par ligne
//////// alors mappingToSet met la ligne retournée par get_next_line dans la case correspondante dans le tableau de données

char            **LireToTas(char *file_name)
{
    char    **file_data;
    char    *line;
    int     iterator;  // un iterateur pour parcourir le tableau
    int     file_descriptor;
    int     number_of_lines;
    int     *characters_data;

    iterator = 1;
    file_descriptor = open(file_name, O_RDONLY);
    number_of_lines = line_count(file_name);
    characters_data = characters_count(file_name);
    if(!(file_data = allocate_table(number_of_lines, characters_data)))
        return (NULL);
    while (get_next_line(file_descriptor, &line) > 0)
    {
        ajout_tas(file_data, line, iterator);
        iterator++;
    }
    close(file_descriptor);
    free(characters_data);
    return (file_data);
}

void        MappingToTable(char *file_name)
{
    char    **file_data;
    int     *characters_data;
    int     iterator;
    int     number_of_lines;

    iterator = 0;
    file_data = LireToTas(file_name);
    number_of_lines = line_count(file_name);
    characters_data = characters_count(file_name);
    Tas = allocate_table(number_of_lines, characters_data);
    int last = number_of_lines;
    while (iterator < number_of_lines)
    {
        Tas[iterator] = extraire_min(file_data, last);
        last--;
        iterator++;
    }
    Tas[iterator] = strdup("");
    free(characters_data);
    free_array(file_data, number_of_lines + 2);
}
