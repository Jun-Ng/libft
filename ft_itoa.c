#include "libft.h"

/*
	check if is min int
		if its min int do something specific
	else check if its negative

	if its 0 do you turn it into '0'? i think so
*/

#include <stdio.h>

static int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

static int	i_len(int i)
{
	int	n;

	n = 0;
	while (i != 0)
	{
		i = i / 10;
		n++;
	}
	if (!n)
		n = 1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		len;
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	len = i_len(n);
	a = malloc(len + neg + 1);
	if (!a)
		return (0);
	len = len + neg - 1;
	a[len + 1] = 0;
	while (len > -1)
	{
		a[len--] = ft_abs((n % 10)) + 48;
		n /= 10;
	}
	if (neg)
		a[0] = '-';
	return (a);
}
