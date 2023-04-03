#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		s_len;

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
