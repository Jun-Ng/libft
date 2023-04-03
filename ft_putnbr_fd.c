#include "libft.h"
#include <unistd.h>

/*
	wait fuck

	-2147483648

	divide then modulo

	/ 10
	% 10

	123 / 100 = 1
	123 % 100 = 23
	23 / 10 = 2.3
	23 % 10 = 3
	3 / 1 = 3

*/

static int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

static int	count_places(int n)
{
	int	p;

	p = 0;
	while (n)
	{
		n /= 10;
		p++;
	}
	if (!p)
		p = 1;
	return (p);
}

static int	ft_pow(int x, int y)
{
	int	z;

	z = x;
	while (y--)
		x *= z;
	return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		l;

	l = ft_pow(10, count_places(n) - 2);
	if (n < 0)
		write(fd, "-", 1);
	while (l)
	{
		c = ft_abs((n / l)) + 48;
		write(fd, &c, 1);
		n %= l;
		l /= 10;
	}
}
