#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			d_len;
	size_t			s_len;
	unsigned int	n;

	if (!dst || !src)
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize > d_len)
	{
		n = d_len;
		while (*src && dstsize && dstsize-- > d_len + 1)
			dst[n++] = *src++;
		dst[n] = 0;
		return (d_len + s_len);
	}
	return (dstsize + s_len);
}
