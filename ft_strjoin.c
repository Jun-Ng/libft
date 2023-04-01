#include "libft.h"

/*
	scenarios

	1. both s1 && s2 are null;
		return null
	2. s2 is null
		return (s1 + '0')

	Errors
		allocation fails
			return null

*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		tlen;

	s3 = 0;
	if (!s1 || !ft_strlen(s1))
		return (ft_strdup(s2));
	if (!s2 || !ft_strlen(s2))
		return (ft_strdup(s1));
	tlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(tlen);
	if (!s3)
		return (0);
	ft_strlcat(s3, s1, tlen);
	ft_strlcat(s3, s2, tlen);
	return (s3);
}
