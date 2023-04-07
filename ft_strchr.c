#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;

	r = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			r = (char *)s;
			break ;
		}
		s++;
	}
	if (!c)
		r = (char *)s;
	return (r);
}
