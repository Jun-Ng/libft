#include "libft.h"

/*
	HUH

	s1: The string TO BE TRIMMED
	set: The characters to trim from s1;

	Return Value
		The trimmed string

	Allocation fails
		return null

	Edge Scenarios
		1. s1 not provided;
		2. set is empty

	Flow
		1. total chars not in the set + 1 for null
		2. malloc
		3. assign
	

*/
#include <stdio.h>

static int	in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	count_chars(char const *s1, char const *set)
{
	int	n;

	n = 0;
	while (*s1)
	{
		if (in_set(*s1, set))
			n++;
		s1++;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_p;
	int		x;
	int		n;
	int		len;

	if (!s1)
		return (0);
	if (!set || !ft_strlen(set))
		return (ft_strdup(s1));
	n = count_chars(s1, set);
	if (!n)
		return (ft_strdup(s1));
	len = ft_strlen(s1) - n;
	s1_p = malloc(len + 1);
	if (!s1_p)
		return (0);
	x = 0;
	while (x < len)
	{
		if (!in_set(*s1, set))
			s1_p[x++] = *s1;
		s1++;
	}
	s1_p[x] = 0;
	return (s1_p);
}
