#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	negative;

	n = 0;
	negative = 1;
	while (is_space(*str) && str++)
		;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = (n * 10) + (*str++ - 48);
	return (n * negative);
}
