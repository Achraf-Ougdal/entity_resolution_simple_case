/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aougdal <aougdal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:19:02 by aougdal           #+#    #+#             */
/*   Updated: 2019/10/25 20:02:46 by aougdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > strlen(s))
		return (ft_strdup(""));
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[start] != '\0' && len--)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
