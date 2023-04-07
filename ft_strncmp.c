#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n < 1)
		return (0);
	while (n-- && (*s1 || *s2) && *s1++ == *s2++)
		;
	if (*(unsigned char *)--s1 > *(unsigned char *)--s2)
		return (1);
	else if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	return (0);
}
