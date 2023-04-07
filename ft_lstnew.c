#include "libft.h"

/*
** Probably don't need to malloc for content,
** Since they don't allow to use free for while malloc'ing for content fails
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(*n));
	if (!n)
		return (0);
	n->content = content;
	n->next = 0;
	return (n);
}
