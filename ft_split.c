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

#include <stdio.h>

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

static void	free_all(char **s)
{
	// while (s && *s)
	// 	free(*s++);
	printf("%p\n", s);
	// free(s);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		n_elements;
	unsigned int		s_len;
	int					m_len;
	char				**arr;

	n_elements = count_elements(s, c);
	arr = malloc((sizeof(arr) * n_elements) + 1);
	if (!arr)
		return (0);
	m_len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			s_len = count_strlen(s, c);
			if (m_len < 2)
				*arr = malloc(s_len + 1);
			else
				*arr = 0;
			if (!*arr)
			{
				free_all(arr - m_len);
				return (0);
			}
			strlcpy(*arr, s, s_len + 1);
			m_len++;
			arr++;
			s += s_len;
		}
	}
	*arr = 0;
	arr -= n_elements;
	return (arr);
}
