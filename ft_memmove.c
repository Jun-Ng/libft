#include "libft.h"

/*
	if overlap || len == 0
		return dst;
	if (d > s && d - s < len)

	memmove (1, 0, 4);
	src = | a | b | c | d | e | 0 |
	dst = 	  | b | c | d | e | 0 | = src + 1

	First iteration len--;
	src =	| a | a | c | d | e | 0 |
	dst =		| a | c | d | e | 0 |

	Second iteration len--;
	src =	| a | a | a | d | e | 0 |
	dst =		| a | a | d | e | 0 |
	
	Eventually becomes
	dst = | a | a | a | a | not desired output

	To prevent that, start from behind
	len--;
	dst[len] = src[len];

	First iteration len = 3;
	src = | a | b | c | d | d | 0 |
	dst = 	  | b | c | d | d | 0 |

	Second iteration len = 2;
	src = | a | b | c | c | d | 0 |
	dst = 	  | b | c | c | d | 0 |

	l = 1
	src = | a | b | b | c | d | 0 |
	dst = 	  | b | b | c | d | 0 |

	l = 0;
	src = | a | a | b | c | d | 0 |
	dst = 	  | a | b | c | d | 0 |
	
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	unsigned int	n;

	d = dst;
	s = src;
	if (d == s || len == 0)
		return (dst);
	if (d > s && d - s < (unsigned int)len)
	{
		n = (unsigned int)len;
		while (n--)
			d[n] = s[n];
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
