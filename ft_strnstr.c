#include "libft.h"

/*
**	If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is
**	returned; otherwise a pointer to the first character of the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		h;
	size_t		n;

	if (!haystack || !*haystack || len < 1)
		return (0);
	if (!needle || !*needle)
		return ((char *)haystack);
	h = 0;
	n = 0;
	while (len-- && haystack[h])
	{
		if (haystack[h++] == needle[n])
			n++;
		else
			n = 0;
		if (n == ft_strlen(needle))
			return ((char *)(haystack + h - n));
	}
	return (0);
}
