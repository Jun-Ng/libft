#include "libft.h"

/*
	if s has no address == NULL
		return (0);
	if malloc fails
		return (0);
	if function is not provided
		strcpy(s, )
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	n;

	n = 0;
	while (f && s && s[n])
	{
		(*f)(n, &s[n]);
		n++;
	}
}
