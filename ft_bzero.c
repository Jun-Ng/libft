#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	if (!s || !n)
		return ;
	p = s;
	while (n--)
		*p++ = 0;
}
