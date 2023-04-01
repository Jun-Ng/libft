#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s0;

	s0 = (char *)s;
	while (c && *s0 && n--)
	{
		if (*s0 == c)
			return (s0);
		s0++;
	}
	return (0);
}
