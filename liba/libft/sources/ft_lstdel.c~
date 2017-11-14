
#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	new = *alst;
	if (!alst)
		return ;
	while (new)
	{
		del((new)->content, (new)->content_size);
		free(new);
		new = new->next;
	}
	*alst = NULL;
}
