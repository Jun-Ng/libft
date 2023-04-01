#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	int			n;

	d = dst;
	s = src;
	if (d == s || len == 0)
		return (dst);
	if (d > s && d - s < (int)len)
	{
		n = (int)len;
		while (n--)
			d[n] = s[n];
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
