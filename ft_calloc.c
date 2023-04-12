#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = 0;
	if ((count * size) / size != count)
		return (0);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
