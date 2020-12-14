/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aougdal <aougdal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:27:00 by aougdal           #+#    #+#             */
/*   Updated: 2019/10/22 17:48:26 by aougdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (!(ret = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (len1--)
		ret[i++] = s1[j++];
	j = 0;
	while (len2--)
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}
