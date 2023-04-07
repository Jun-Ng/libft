#include "libft.h"

/*
	s = string to be split;
	c = the delimiter character;

	Flow
		1. Amount of strings
		2. Each string's size

	Edge Scenarios
		if S is not provided
			just return null terminated array of strings;
		if C is not provided
			doesn't matter

*/

static unsigned int	count_elements(char const *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

static unsigned int	count_strlen(char const *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s && *s++ != c)
		n++;
	return (n);
}

static char	**free_all(char **s, int n)
{
	while (s && n > -1)
		free(s[n--]);
	free(s);
	return (0);
}

static	unsigned int	assign_str(char	*arr, const char *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s && *s != c)
	{
		*arr++ = *s++;
		n++;
	}
	*arr = 0;
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**arr;

	if (!s)
		return (0);
	arr = malloc((sizeof(char *) * (count_elements(s, c) + 1)));
	if (!arr)
		return (0);
	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			arr[n] = malloc(count_strlen(s, c) + 1);
			if (!arr[n])
				return (free_all(arr, n));
			s += assign_str(arr[n++], s, c);
		}
	}
	arr[n] = 0;
	return (arr);
}

/*
	arr[n][y++] = *s++;
*/
