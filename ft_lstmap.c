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

	assuming that function doesn't fail,
	The only places you need to free, is when malloc fails?

	applying a null function is going to break your code,
	so check if f & del are actual functions

	you can probably do this recursively?

	lst->next = ft_lstmap()

	how do you fix the free problem then?

	you can't reverse back the list without a head

	you return the head
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*i;

	if (!lst || !f || !del)
		return (0);
	head = ft_lstnew((*f)(lst->content));
	if (!head)
		ft_lstclear(&head, del);
	i = head;
	lst = lst->next;
	while (lst && i)
	{
		ft_lstadd_back(&head, ft_lstnew((*f)(lst->content)));
		if (!i->next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		i = i->next;
		lst = lst->next;
	}
	return (head);
}

// static void	*free_all(t_list **lst, void (*del)(void *))
// {
// 	ft_lstclear(lst, del);
// 	return (0);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*p;

// 	if (!lst || !f || !del)
// 		return (0);
// 	p = 0;
// 	while (lst)
// 	{
// 		if (!p)
// 		{
// 			p = ft_lstnew((*f)(lst->content));
// 			if (!p)
// 				return (free_all(&p, del));
// 		}
// 		else if (p)
// 		{
// 			ft_lstadd_back(&p, ft_lstnew((*f)(lst->content)));
// 			if (!p->next)
// 				return (free_all(&p, del));
// 			p = p->next;
// 		}
// 		lst = lst->next;
// 	}
// 	return (p);
// }

