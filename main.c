#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void	print_array_address_int(int *arr)
{
	int	n;

	n = 0;
	while (arr[n])
	{
		printf("%d %p %d\n", n, &arr[n], arr[n]);
		n++;
	}
	printf("\n");
}

void	print_array_address_str(char *arr)
{
	int	n;

	n = 0;
	while (arr[n])
	{
		printf("%d %p %c\n", n, &arr[n], arr[n]);
		n++;
	}
	printf("\n");
}

void	test_func(unsigned int i, char *c)
{
	printf("%i | %c | %p\n", i, *c, c);
	*c = i + *c;
}

int	main(void)
{
	int	fd = open("foo.txt", O_RDWR);

	ft_putnbr_fd(2147483647, fd);
	return (0);
}
