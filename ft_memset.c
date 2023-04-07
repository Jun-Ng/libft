#include "libft.h"

/*
** if string B is NULL, return (0);
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = b;
	if (!b)
		return (0);
	while (len--)
		*dst++ = (unsigned char)c;
	return (b);
}
