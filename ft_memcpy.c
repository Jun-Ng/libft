#include "libft.h"

/*
** Just replace dst with ( n > 0 && src[n - 1])
** Process must be done in char since you have to copy byte by byte
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;

	if (!dst)
		return (dst);
	if (!src)
		return (dst);
	d = dst;
	while (n--)
		*d++ = *(char *)src++;
	return (dst);
}
