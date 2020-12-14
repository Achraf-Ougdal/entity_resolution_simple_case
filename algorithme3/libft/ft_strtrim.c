/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aougdal <aougdal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:00:37 by aougdal           #+#    #+#             */
/*   Updated: 2019/10/22 20:49:10 by aougdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_doesexist(char this, const char *here)
{
	int		i;

	i = 0;
	while (here[i] != '\0')
	{
		if (here[i] == this)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ret;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_doesexist(s1[i], set))
		i++;
	start = i;
	i = strlen(s1) - 1;
	while (i > start && ft_doesexist(s1[i], set))
		i--;
	end = i;
	if (!(ret = (char*)malloc(sizeof(char) * (end - start + 1) + 1)))
		return (NULL);
	ret = ft_substr(s1, start, end - start + 1);
	return (ret);
}
