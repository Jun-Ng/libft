#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	while (len--)
	{
		if (*h == *n)
		{
			while (*n)
			{
				if (*n != *(h + (n - needle)))
				{
					n = (char *)needle;
					break ;
				}
				n++;
			}
			if (*n == 0)
				return (h);
		}
		h++;
	}
	return (0);
}
