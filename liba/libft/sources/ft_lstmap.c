#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	//t_list *new1;

	new = malloc(sizeof(t_list));
	if (lst && new)
	{
		//new1 = new;
		while (lst)
		{
			new = f(lst);
			ft_lstadd(new);
			lst = lst->next;
			//new = new->next;
		}
		//new = NULL;
		return (new);
	}
	return (NULL);
}
