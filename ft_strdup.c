#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s;
	size_t		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	s = malloc(len + 1);
	ft_memcpy(s, s1, len);
	s[len] = 0;
	return (s);
}
