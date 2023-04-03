#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s0;

	if (!s)
		return (0);
	if (len == 0 || (unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s0 = malloc(len + 1);
	if (!s0)
		return (0);
	ft_strlcpy(s0, s + start, len + 1);
	return (s0);
}
