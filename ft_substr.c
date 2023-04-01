#include "libft.h"

/*
	s = the string from which to create the substring;
	start = start index of substring in string 's';
	len = max_len of substr;

	assuming that max len refers to string without null;

	situations
	1. if s is null;
		return NULL
	
	always null terminate here since string is provided?
		2. if start is more than s || len == 0
			return malloc'ed empty string ( as null terminator);
		 012345	
	s = "abcdef"

	errors:
		if malloc fails return NULL

	ft_substr(s, 4, 10)
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s0;

	if (!s)
		return (0);
	if (len == 0 || (unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s0 = malloc(len + 1);
	if (!s0)
		return (0);
	ft_strlcpy(s0, s + start, len + 1);
	return (s0);
}
