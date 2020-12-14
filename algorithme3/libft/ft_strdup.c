/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aougdal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:02:36 by aougdal           #+#    #+#             */
/*   Updated: 2019/10/19 03:22:22 by aougdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	char	*tmp;
	size_t	len;

	len = strlen(s);
	if (!(ret = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	tmp = ret;
	while (*s)
		*tmp++ = *s++;
	*tmp = '\0';
	return (ret);
}
