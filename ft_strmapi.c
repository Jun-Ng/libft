#include "libft.h"

/*
	if s is NULL ( no address assigned )
		return (0);
	if malloc fails
		return (0);
	if (!f)
		c = ft_strdup(s);
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	int		slen;
	int		i;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	c = malloc(slen + 1);
	if (!c)
		return (0);
	i = -1;
	if (f && *s)
	{
		while (++i < slen)
			c[i] = (*f)(i, s[i]);
		c[slen] = 0;
	}
	else
		ft_strlcpy(c, s, slen + 1);
	return (c);
}
