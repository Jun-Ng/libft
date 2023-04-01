#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	int		n;

	r = 0;
	n = 1;
	while (*(s + 1) != 0 && s++ && n++)
		;
	if (!c)
		r = (char *)++s;
	else
	{
		while (n)
		{
			if (*s == c)
			{
				r = (char *)s;
				break ;
			}
			s--;
			n--;
		}
	}
	return (r);
}

