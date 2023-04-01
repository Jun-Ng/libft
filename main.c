#include "libft.h"
#include <stdio.h>
#include <string.h>

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

int	main(void)
{
	char	p[11] = "cc_aaba_aa";
	char	*dst;

	dst = malloc(11);
	printf("%s | %p\n", p, p);
	ft_strlcpy(dst, p, 11);
	printf("%s | %p\n", dst, dst);
	free(dst);
	return (0);
}
