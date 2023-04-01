#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s;
	char		*s_p;
	size_t		len;

	len = ft_strlen(s1);
	s = malloc(len + 1);
	s_p = 0;
	if (!len && s)
		return (s);
	if (s)
	{
		s_p = s;
		while (*s1)
			*s_p++ = *s1++;
	}
	*s_p = 0;
	return (s);
}
