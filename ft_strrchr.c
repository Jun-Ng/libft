#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	int		l;

	if (!s)
		return (0);
	l = ft_strlen(s) + 1;
	r = 0;
	while (--l > -1)
	{
		if (s[l] == (char)c)
		{
			r = (char *)s + l;
			break ;
		}
	}
	return (r);
}

