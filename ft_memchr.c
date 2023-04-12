#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s0;

	s0 = (unsigned char *)s;
	while (s0 && n--)
	{
		if (*s0 == (unsigned char)c)
			return (s0);
		s0++;
	}
	return (0);
}
