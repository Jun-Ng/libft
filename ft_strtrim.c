#include "libft.h"

static int	in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static int	trimmed_size(char const *s1, char const *set)
{
	int	n;

	n = 0;
	while (s1 && *s1)
	{
		if (!in_set(*s1++, set))
			n++;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ts;
	int		len;
	int		n;

	if (!s1)
		return (0);
	if (!set || !*set || !*s1)
		return (ft_strdup(s1));
	len = trimmed_size(s1, set);
	if (!len)
		return (ft_strdup(""));
	ts = malloc(len + 1);
	if (!ts)
		return (0);
	n = 0;
	while (*s1)
	{
		if (!in_set(*s1, set))
			ts[n++] = *s1;
		s1++;
	}
	ts[n] = 0;
	return (ts);
}
