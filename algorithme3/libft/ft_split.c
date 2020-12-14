/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aougdal <aougdal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:09:19 by aougdal           #+#    #+#             */
/*   Updated: 2019/10/23 01:59:08 by aougdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(const char *str, char c)
{
	int		count;
	int		flag;
	int		i;

	flag = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (!flag)
			{
				flag = 1;
				count++;
			}
		}
		else
			flag = 0;
		str++;
	}
	return (count);
}

static	int	ft_wordlen(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		j;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (j < ft_count_words(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		len = ft_wordlen(&s[i], c);
		if (!(ret[j] = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ret[j++] = ft_substr(s, i, len);
		i += len;
	}
	ret[j] = 0;
	return (ret);
}
