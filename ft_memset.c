#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	size_t			str_len;

	dst = b;
	str_len = 0;

	while (*dst++)
		str_len++;
	dst = b;
	if (len <= str_len)
	{
		while (len)
		{
			*dst++ = c;
			len--;
		}
	}
	return (b);
}
