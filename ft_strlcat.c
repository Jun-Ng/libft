#include "libft.h"

/*
**	1. Appends src to end of dst
**	2. expected length to append = dstsize - strlen(dst) - 1
**	3. It will always null terminate
**
**	Return Value
**		len(dst) + len(src)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	r_len;
	size_t	m_len;

	if (!dst || !src)
		return (0);
	d_len = ft_strlen(dst);
	r_len = d_len + ft_strlen(src);
	if (!dstsize)
		return (r_len);
	m_len = dstsize - d_len - 1;
	while (m_len--)
		dst[d_len++] = *src++;
	dst[d_len] = 0;
	return (r_len);
}
