#include "libft.h"

/*
** lst = address of a pointer to the first link of a new list
** new = the new t_list to add to be BEGINNING of the list

	so probably

	new.next = lst
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
