#include "libft.h"

static int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

static int	count_places(int n)
{
	int	p;

	p = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		p *= 10;
	}
	return (p);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		l;

	if (n < 0)
		write(fd, "-", 1);
	l = count_places(n);
	while (l)
	{
		c = ft_abs((n / l)) + 48;
		write(fd, &c, 1);
		n %= l;
		l /= 10;
	}
}
