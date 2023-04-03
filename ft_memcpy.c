#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;

	if (!dst)
		return (0);
	if (!src)
		return (dst);
	d = dst;
	while (n--)
		*d++ = *(char *)src++;
	return (dst);
}
