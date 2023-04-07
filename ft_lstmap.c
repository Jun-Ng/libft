#include "libft.h"

/*
	Assumptions
		1. (*f) returns a pointer
		2. (*del) to free the content
	
	Where do you need to malloc
		1. new lst
		2. content? 

	Possible point of failures
		malloc'ing for node, node->content
	
	You'll need to hold a head pointer? to free
*/

static void	*free_all(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;

	if (!lst || !f || !del)
		return (0);
	p = 0;
	while (lst)
	{
		if (!p)
		{
			p = ft_lstnew((*f)(lst->content));
			if (!p)
				return (free_all(&p, del));
		}
		if (p)
		{
			ft_lstadd_back(&p, ft_lstnew((*f)(lst->content)));
			if (!p->next)
				return (free_all(&p, del));
			p = p->next;
		}
		lst = lst->next;
	}
	return (p);
}
