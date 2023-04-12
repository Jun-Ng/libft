#include "libft.h"

/*
**	If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is
**	returned; otherwise a pointer to the first character of the first occurrence of needle is returned.

	Error precedence
	1. Needle is an empty string
		return haystack
	2.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		h;
	size_t		n;

	if (!*needle)
		return ((char *)haystack);
	if (!haystack || !*haystack || !needle || len == 0)
		return (0);
	h = 0;
	while (len && haystack[h])
	{
		n = 0;
		while (n < len && haystack[h + n] == needle[n])
			n++;
		if (n == ft_strlen(needle))
			return ((char *)(haystack + h));
		h++;
		len--;
	}
	return (0);
}
