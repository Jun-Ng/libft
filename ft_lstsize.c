#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;

	if (!lst)
		return (0);
	n = 1;
	while (lst && lst->next)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}
