#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_p;
	const char	*s2_p;

	s1_p = s1;
	s2_p = s2;
	while (n--)
	{
		if (*s1_p != *s2_p)
			return (*(unsigned char *)s1_p - *(unsigned char *)s2_p);
		s1_p++;
		s2_p++;
	}
	return (0);
}
