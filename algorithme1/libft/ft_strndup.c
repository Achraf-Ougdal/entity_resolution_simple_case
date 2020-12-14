#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	slen = (size_t)strlen(s);
	int		len = slen < n ? slen : n;
	char	*copy = (char*)malloc(len + 1);

	if (copy)
	{
		memcpy(copy, s, len);
		copy[len] = 0;
	}
	return (copy);
}