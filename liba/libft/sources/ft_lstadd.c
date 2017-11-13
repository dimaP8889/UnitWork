
#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!(*alst))
	{
		new->next = NULL;
		*alst = new;
		return ;
	}
	new->next = (*alst)->content;
	*alst = new;
}
