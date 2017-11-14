#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (lst) //&& new)
	{
		while (lst)
		{
			//new = f(lst);
			ft_lstadd(&new, f(lst));
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
