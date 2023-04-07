#include "libft.h"

/*
** Guarantees NULL termination only if there is room
** User is supposed to include NULL in dstsize
**
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		s_len;

	if (!dst)
		return (0);
	d = dst;
	s = src;
	s_len = ft_strlen(src);
	if (dstsize > s_len + 1)
		ft_memcpy(d, s, s_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(d, s, dstsize - 1);
		d[dstsize - 1] = '\0';
	}
	return (s_len);
}
