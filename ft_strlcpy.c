#include "libft.h"

// static int	check_olap(const char *dst, const char *src)
// {
// 	const char	*d;
// 	const char	*s;
// 	const char	*start;
// 	const char	*end;
// 	const char	*between;

// 	d = dst;
// 	s = src;
// 	start = d;
// 	while (*(d + 1) != 0 && d++)
// 		;
// 	end = d;
// 	between = s;
// 	if (between >= start && between <= end)
// 		return (1);
// 	d = dst;
// 	start = s;
// 	while (*(s + 1) != 0 && s++)
// 		;
// 	end = s;
// 	between = d;
// 	if (between >= start && between <= end)
// 		return (1);
// 	return (0);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		s_len;

	d = dst;
	s = src;
	s_len = ft_strlen(src);
	if (s_len + 1 < dstsize)
		ft_memcpy(d, s, s_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(d, s, dstsize - 1);
		d[dstsize - 1] = '\0';
	}
	return (s_len);
}
